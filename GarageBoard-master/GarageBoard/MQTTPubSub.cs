using HiveMQtt.Client.Events;
using HiveMQtt.Client;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Text.Json.Nodes;
using System.Threading.Tasks;

namespace GarageBoard
{
    internal class MQTTPubSub : INotifyPropertyChanged
    {
        public HiveMQClient client;

        private string recentMessage = "";
        public string RecentMessage
        {
            get { return recentMessage; }
            set
            {
                recentMessage = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("RecentMessage"));
            }
        }
        private double distanceValue = 0.0;
        public double DistanceValue
        {
            get { return distanceValue; }
            set
            {
                distanceValue = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("DistanceValue"));
            }
        }

        private string doorState = "";
        public string DoorState
        {
            get { return doorState; }
            set
            {
                doorState = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("DoorState"));
            }
        }

        private string uid = "";
        public string UID
        {
            get { return uid; }
            set
            {
                uid = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("UID"));
            }
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        public MQTTPubSub()
        {
            client = new HiveMQClient(new HiveMQClientOptionsBuilder().
                                             WithBroker("192.168.1.102")
                                             .WithPort(1883)
                                             .WithAutomaticReconnect(true)
                                             .Build());
            client.OnMessageReceived += MessageHandler;
            client.AfterConnect += AfterConnectHandler;
            ConnectClient();
            RecentMessage = "";
        }

        protected virtual void OnPropertyChanged(string propertyName)
        {
            this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
        void AfterConnectHandler(object? sender, AfterConnectEventArgs eventArgs)
        {
            SubscribeToTopic("bus_master/#");
        }
        private void MessageHandler(object? sender, OnMessageReceivedEventArgs eventArgs)
        {
            RecentMessage = eventArgs.PublishMessage.PayloadAsString;
            string ?topic = eventArgs.PublishMessage.Topic;
            JsonNode? node = JsonNode.Parse(RecentMessage);
            if (topic != null)
            {
                switch (topic)
                {
                    case "bus_master/distance":
                        DistanceValue = (double)node["Distance"];
                        break;

                    case "bus_master/NFC/STATE":
                        DoorState = (string)node["State"];
                        break;

                    case "bus_master/NFC/UID":
                        UID = (string)node["ID"];
                        break;

                    default:

                        break;
                }

            }

        }

        public async void ConnectClient()
        {
            try
            {
                var done = await client.ConnectAsync().ConfigureAwait(false);
                //MessageBox.Show("Connected!");
            }
            catch (Exception e)
            {
                MessageBox.Show("Wait for connection...");
                Task.Delay(5000);
                ConnectClient();
            }

        }

        public async void SubscribeToTopic(string topic)
        {
            try
            {
                var subDone = await client.SubscribeAsync(topic).ConfigureAwait(false);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                Environment.Exit(0);
            }
        }

        public async void PublishToTopic(string topic, string message)
        {
            var pubDone = await client.PublishAsync(topic, message);
        }
    }
}
