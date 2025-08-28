using System.Text.Json.Nodes;

namespace GarageBoard
{
    public partial class GarageForm : Form
    {
        private MQTTPubSub client = new MQTTPubSub();

        private bool previousState = false;

        private bool currentState = false;

        private List<string> validCards = [];

        private string lastUID = "";
        private string recentUID = "";
        public GarageForm()
        {
            InitializeComponent();
            refreshTimer.Start();

            using (StreamReader sr = new StreamReader("validNFCs.txt"))
            {
                while (!sr.EndOfStream)
                {
                    string? token = sr.ReadLine();
                    if (token != null) validCards.Add(token);
                }
                sr.Close();
            }
            nfcBox1.DataSource = GetNFCCards();
        }

        private void refreshTimer_Tick(object sender, EventArgs e)
        {
            distanceBar.Value = (int)client.DistanceValue;
            distanceBox.Text = (client.DistanceValue - 3.8).ToString("0.##");
            stateBox.Text = client.DoorState;

            if (client.DoorState == "Open") currentState = true;
            else currentState = false;

            recentUID = client.UID;
            if (recentUID != lastUID)
            {
                lastUID = recentUID;
                if (!validCards.Contains(recentUID))
                {
                    DialogResult result = MessageBox.Show("New card with id " + recentUID + " detected!",
                                                            "Add Card?", MessageBoxButtons.YesNo);
                    if (result == DialogResult.Yes)
                    {
                        validCards.Add(recentUID);

                        using (StreamWriter sw = new StreamWriter("validNFCs.txt"))
                        {
                            foreach (string s in validCards)
                            {
                                sw.WriteLine(s);
                            }
                            sw.Close();
                        }
                        JsonObject obj = new JsonObject();
                        obj.Add("NFCAdd", recentUID);
                        client.PublishToTopic("bus_master/NFC/STATE", obj.ToJsonString());
                        obj.Clear();
                        nfcBox1.DataSource = GetNFCCards();
                    }
                }
                recentUID = "";
            }
            if (currentState != previousState)
            {
                ChangeGarageAppearance();
                previousState = currentState;
            }
        }

        private void ChangeGarageAppearance()
        {
            if (currentState == true)
            {
                bottomPanel.Hide();
                Thread.Sleep(500);
                secondPanel.Hide();
                Thread.Sleep(500);
                thirdPanel.Hide();
                Thread.Sleep(500);
                topPanel.Hide();
            }
            else
            {
                topPanel.Show();
                Thread.Sleep(500);
                thirdPanel.Show();
                Thread.Sleep(500);
                secondPanel.Show();
                Thread.Sleep(500);
                bottomPanel.Show();
            }
        }

        private void addNFCButton_Click(object sender, EventArgs e)
        {
            if (!validCards.Contains(nfcBox1.Text)) validCards.Add(nfcBox1.Text);

            using (StreamWriter sw = new StreamWriter("validNFCs.txt"))
            {
                foreach (string s in validCards)
                {
                    sw.WriteLine(s);
                }
                sw.Close();
            }
            JsonObject obj = new JsonObject();
            obj.Add("NFCAdd", nfcBox1.Text);
            client.PublishToTopic("bus_master/NFC/STATE", obj.ToJsonString());
            obj.Clear();
            nfcBox1.DataSource = GetNFCCards();
        }

        private void removeNFCButton_Click(object sender, EventArgs e)
        {
            validCards.Remove(nfcBox1.Text);
            using (StreamWriter sw = new StreamWriter("validNFCs.txt"))
            {
                foreach (string s in validCards)
                {
                    sw.WriteLine(s);
                }
                sw.Close();
            }
            JsonObject obj = new JsonObject();
            obj.Add("NFCRemove", nfcBox1.Text);
            client.PublishToTopic("bus_master/NFC/STATE", obj.ToJsonString());
            obj.Clear();
            nfcBox1.DataSource = GetNFCCards();

        }

        public List<string> GetNFCCards()
        {
            List<string> result = [];
            using (StreamReader sr = new StreamReader("validNFCs.txt"))
            {
                while (!sr.EndOfStream)
                {
                    string? token = sr.ReadLine();
                    if (token != null) result.Add(token);
                }
                sr.Close();
            }
            return result;
        }
    }
}
