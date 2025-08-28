namespace GarageBoard
{
    partial class GarageForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            distanceBar = new TrackBar();
            titleLabel = new Label();
            label1 = new Label();
            distanceBox = new TextBox();
            distanceGroup = new GroupBox();
            nfcBox1 = new ComboBox();
            nfcLabel = new Label();
            nfcGroup = new GroupBox();
            removeNFCButton = new Button();
            addNFCButton = new Button();
            refreshTimer = new System.Windows.Forms.Timer(components);
            topPanel = new Panel();
            thirdPanel = new Panel();
            secondPanel = new Panel();
            bottomPanel = new Panel();
            garageDoor = new GroupBox();
            groupBox1 = new GroupBox();
            stateBox = new TextBox();
            label2 = new Label();
            ((System.ComponentModel.ISupportInitialize)distanceBar).BeginInit();
            distanceGroup.SuspendLayout();
            nfcGroup.SuspendLayout();
            garageDoor.SuspendLayout();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // distanceBar
            // 
            distanceBar.Location = new Point(13, 82);
            distanceBar.Margin = new Padding(10, 3, 10, 3);
            distanceBar.Maximum = 14;
            distanceBar.Name = "distanceBar";
            distanceBar.RightToLeft = RightToLeft.Yes;
            distanceBar.Size = new Size(1182, 114);
            distanceBar.TabIndex = 0;
            // 
            // titleLabel
            // 
            titleLabel.Anchor = AnchorStyles.Top;
            titleLabel.AutoSize = true;
            titleLabel.Font = new Font("Comic Sans MS", 24F, FontStyle.Bold, GraphicsUnit.Point, 0);
            titleLabel.Location = new Point(560, 21);
            titleLabel.Name = "titleLabel";
            titleLabel.Size = new Size(790, 111);
            titleLabel.TabIndex = 1;
            titleLabel.Text = "Bus Master Garage";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(368, 209);
            label1.Name = "label1";
            label1.Size = new Size(390, 56);
            label1.TabIndex = 2;
            label1.Text = "Distance to Middle:";
            // 
            // distanceBox
            // 
            distanceBox.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            distanceBox.Location = new Point(755, 202);
            distanceBox.Name = "distanceBox";
            distanceBox.Size = new Size(250, 63);
            distanceBox.TabIndex = 3;
            // 
            // distanceGroup
            // 
            distanceGroup.Controls.Add(distanceBox);
            distanceGroup.Controls.Add(label1);
            distanceGroup.Controls.Add(distanceBar);
            distanceGroup.Font = new Font("Comic Sans MS", 9.900001F, FontStyle.Regular, GraphicsUnit.Point, 0);
            distanceGroup.Location = new Point(12, 184);
            distanceGroup.Name = "distanceGroup";
            distanceGroup.Size = new Size(1303, 285);
            distanceGroup.TabIndex = 4;
            distanceGroup.TabStop = false;
            distanceGroup.Text = "Distance Sensor";
            // 
            // nfcBox1
            // 
            nfcBox1.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            nfcBox1.FormattingEnabled = true;
            nfcBox1.Location = new Point(30, 141);
            nfcBox1.Name = "nfcBox1";
            nfcBox1.Size = new Size(421, 64);
            nfcBox1.TabIndex = 5;
            // 
            // nfcLabel
            // 
            nfcLabel.Anchor = AnchorStyles.Top;
            nfcLabel.AutoSize = true;
            nfcLabel.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            nfcLabel.Location = new Point(30, 82);
            nfcLabel.Name = "nfcLabel";
            nfcLabel.Size = new Size(421, 56);
            nfcLabel.TabIndex = 6;
            nfcLabel.Text = "Valid NFC Signatures";
            // 
            // nfcGroup
            // 
            nfcGroup.Controls.Add(removeNFCButton);
            nfcGroup.Controls.Add(addNFCButton);
            nfcGroup.Controls.Add(nfcLabel);
            nfcGroup.Controls.Add(nfcBox1);
            nfcGroup.Font = new Font("Comic Sans MS", 9.900001F, FontStyle.Regular, GraphicsUnit.Point, 0);
            nfcGroup.Location = new Point(1327, 184);
            nfcGroup.Name = "nfcGroup";
            nfcGroup.Size = new Size(484, 531);
            nfcGroup.TabIndex = 7;
            nfcGroup.TabStop = false;
            nfcGroup.Text = "NFC Sensor";
            // 
            // removeNFCButton
            // 
            removeNFCButton.AutoSize = true;
            removeNFCButton.BackColor = Color.Red;
            removeNFCButton.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            removeNFCButton.Location = new Point(30, 385);
            removeNFCButton.Name = "removeNFCButton";
            removeNFCButton.Size = new Size(423, 113);
            removeNFCButton.TabIndex = 8;
            removeNFCButton.Text = "Remove NFC";
            removeNFCButton.UseVisualStyleBackColor = false;
            removeNFCButton.Click += removeNFCButton_Click;
            // 
            // addNFCButton
            // 
            addNFCButton.AutoSize = true;
            addNFCButton.BackColor = Color.FromArgb(0, 192, 0);
            addNFCButton.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            addNFCButton.Location = new Point(30, 260);
            addNFCButton.Name = "addNFCButton";
            addNFCButton.Size = new Size(423, 119);
            addNFCButton.TabIndex = 7;
            addNFCButton.Text = "Add NFC";
            addNFCButton.UseVisualStyleBackColor = false;
            addNFCButton.Click += addNFCButton_Click;
            // 
            // refreshTimer
            // 
            refreshTimer.Interval = 1000;
            refreshTimer.Tick += refreshTimer_Tick;
            // 
            // topPanel
            // 
            topPanel.BackColor = SystemColors.ButtonHighlight;
            topPanel.Location = new Point(78, 77);
            topPanel.Name = "topPanel";
            topPanel.Size = new Size(1175, 137);
            topPanel.TabIndex = 9;
            // 
            // thirdPanel
            // 
            thirdPanel.BackColor = SystemColors.ButtonHighlight;
            thirdPanel.Location = new Point(78, 220);
            thirdPanel.Name = "thirdPanel";
            thirdPanel.Size = new Size(1175, 137);
            thirdPanel.TabIndex = 10;
            // 
            // secondPanel
            // 
            secondPanel.BackColor = SystemColors.ButtonHighlight;
            secondPanel.Location = new Point(78, 363);
            secondPanel.Name = "secondPanel";
            secondPanel.Size = new Size(1175, 137);
            secondPanel.TabIndex = 11;
            // 
            // bottomPanel
            // 
            bottomPanel.BackColor = SystemColors.ButtonHighlight;
            bottomPanel.Location = new Point(78, 506);
            bottomPanel.Name = "bottomPanel";
            bottomPanel.Size = new Size(1175, 137);
            bottomPanel.TabIndex = 12;
            // 
            // garageDoor
            // 
            garageDoor.Controls.Add(topPanel);
            garageDoor.Controls.Add(secondPanel);
            garageDoor.Controls.Add(bottomPanel);
            garageDoor.Controls.Add(thirdPanel);
            garageDoor.Font = new Font("Comic Sans MS", 9.900001F, FontStyle.Regular, GraphicsUnit.Point, 0);
            garageDoor.Location = new Point(12, 482);
            garageDoor.Name = "garageDoor";
            garageDoor.Size = new Size(1303, 678);
            garageDoor.TabIndex = 13;
            garageDoor.TabStop = false;
            garageDoor.Text = "Garage Door";
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(stateBox);
            groupBox1.Controls.Add(label2);
            groupBox1.Font = new Font("Comic Sans MS", 9.900001F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBox1.Location = new Point(1327, 721);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(484, 439);
            groupBox1.TabIndex = 14;
            groupBox1.TabStop = false;
            groupBox1.Text = "Hall Effect";
            // 
            // stateBox
            // 
            stateBox.Enabled = false;
            stateBox.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            stateBox.Location = new Point(63, 137);
            stateBox.Name = "stateBox";
            stateBox.Size = new Size(375, 63);
            stateBox.TabIndex = 1;
            // 
            // label2
            // 
            label2.Anchor = AnchorStyles.Top;
            label2.AutoSize = true;
            label2.Font = new Font("Comic Sans MS", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label2.Location = new Point(63, 62);
            label2.Name = "label2";
            label2.Size = new Size(375, 56);
            label2.TabIndex = 0;
            label2.Text = "Garage Door State";
            // 
            // GarageForm
            // 
            AutoScaleDimensions = new SizeF(17F, 41F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ControlDark;
            ClientSize = new Size(1819, 1169);
            Controls.Add(groupBox1);
            Controls.Add(garageDoor);
            Controls.Add(nfcGroup);
            Controls.Add(distanceGroup);
            Controls.Add(titleLabel);
            Name = "GarageForm";
            Text = "Garage Board";
            ((System.ComponentModel.ISupportInitialize)distanceBar).EndInit();
            distanceGroup.ResumeLayout(false);
            distanceGroup.PerformLayout();
            nfcGroup.ResumeLayout(false);
            nfcGroup.PerformLayout();
            garageDoor.ResumeLayout(false);
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TrackBar distanceBar;
        private Label titleLabel;
        private Label label1;
        private TextBox distanceBox;
        private GroupBox distanceGroup;
        private ComboBox nfcBox1;
        private Label nfcLabel;
        private GroupBox nfcGroup;
        private Button removeNFCButton;
        private Button addNFCButton;
        private System.Windows.Forms.Timer refreshTimer;
        private Panel topPanel;
        private Panel thirdPanel;
        private Panel secondPanel;
        private Panel bottomPanel;
        private GroupBox garageDoor;
        private GroupBox groupBox1;
        private Label label2;
        private TextBox stateBox;
    }
}
