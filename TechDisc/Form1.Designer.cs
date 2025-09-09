namespace TechDisc
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.TitlePanel = new System.Windows.Forms.TableLayoutPanel();
            this.TitleLabel = new System.Windows.Forms.Label();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.SpeedLabel = new System.Windows.Forms.Label();
            this.RPMLabel = new System.Windows.Forms.Label();
            this.LALabel = new System.Windows.Forms.Label();
            this.PreviousThrows = new System.Windows.Forms.Button();
            this.NewThrow = new System.Windows.Forms.Button();
            this.Reset = new System.Windows.Forms.Button();
            this.SpeedValue = new System.Windows.Forms.Label();
            this.RPMValue = new System.Windows.Forms.Label();
            this.LAValue = new System.Windows.Forms.Label();
            this.TitlePanel.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // TitlePanel
            // 
            this.TitlePanel.AutoSize = true;
            this.TitlePanel.BackColor = System.Drawing.SystemColors.Control;
            this.TitlePanel.ColumnCount = 1;
            this.TitlePanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.TitlePanel.Controls.Add(this.TitleLabel, 0, 0);
            this.TitlePanel.Dock = System.Windows.Forms.DockStyle.Top;
            this.TitlePanel.Font = new System.Drawing.Font("Microsoft Sans Serif", 28F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TitlePanel.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.TitlePanel.Location = new System.Drawing.Point(0, 0);
            this.TitlePanel.Name = "TitlePanel";
            this.TitlePanel.RowCount = 1;
            this.TitlePanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.TitlePanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 59F));
            this.TitlePanel.Size = new System.Drawing.Size(800, 59);
            this.TitlePanel.TabIndex = 0;
            // 
            // TitleLabel
            // 
            this.TitleLabel.AutoSize = true;
            this.TitleLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(51)))), ((int)(((byte)(10)))), ((int)(((byte)(87)))));
            this.TitleLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TitleLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 26F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TitleLabel.Location = new System.Drawing.Point(3, 0);
            this.TitleLabel.Name = "TitleLabel";
            this.TitleLabel.Size = new System.Drawing.Size(794, 59);
            this.TitleLabel.TabIndex = 0;
            this.TitleLabel.Text = "K-Tech Flyers Disc Simulation";
            this.TitleLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 9;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 3.3711F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 26.72583F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 3.3711F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 3.340729F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 26.72583F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 3.340729F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 3.309327F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 26.47461F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 3.340729F));
            this.tableLayoutPanel1.Controls.Add(this.SpeedLabel, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.RPMLabel, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.LALabel, 0, 7);
            this.tableLayoutPanel1.Controls.Add(this.PreviousThrows, 7, 1);
            this.tableLayoutPanel1.Controls.Add(this.NewThrow, 7, 4);
            this.tableLayoutPanel1.Controls.Add(this.Reset, 7, 7);
            this.tableLayoutPanel1.Controls.Add(this.SpeedValue, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.RPMValue, 2, 4);
            this.tableLayoutPanel1.Controls.Add(this.LAValue, 2, 7);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 59);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 9;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 3.333333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 26.66667F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 3.333333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 3.333333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 26.66667F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 3.333333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 3.333333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 26.66667F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 3.333333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(800, 391);
            this.tableLayoutPanel1.TabIndex = 1;
            // 
            // SpeedLabel
            // 
            this.SpeedLabel.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.SpeedLabel, 3);
            this.SpeedLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SpeedLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SpeedLabel.Location = new System.Drawing.Point(3, 12);
            this.SpeedLabel.Name = "SpeedLabel";
            this.tableLayoutPanel1.SetRowSpan(this.SpeedLabel, 3);
            this.SpeedLabel.Size = new System.Drawing.Size(259, 122);
            this.SpeedLabel.TabIndex = 0;
            this.SpeedLabel.Text = "Speed:";
            this.SpeedLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // RPMLabel
            // 
            this.RPMLabel.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.RPMLabel, 3);
            this.RPMLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RPMLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RPMLabel.Location = new System.Drawing.Point(3, 134);
            this.RPMLabel.Name = "RPMLabel";
            this.tableLayoutPanel1.SetRowSpan(this.RPMLabel, 3);
            this.RPMLabel.Size = new System.Drawing.Size(259, 122);
            this.RPMLabel.TabIndex = 1;
            this.RPMLabel.Text = "RPM:";
            this.RPMLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LALabel
            // 
            this.LALabel.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.LALabel, 3);
            this.LALabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.LALabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LALabel.Location = new System.Drawing.Point(3, 256);
            this.LALabel.Name = "LALabel";
            this.tableLayoutPanel1.SetRowSpan(this.LALabel, 3);
            this.LALabel.Size = new System.Drawing.Size(259, 135);
            this.LALabel.TabIndex = 2;
            this.LALabel.Text = "Launch Angle:";
            this.LALabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // PreviousThrows
            // 
            this.PreviousThrows.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(51)))), ((int)(((byte)(10)))), ((int)(((byte)(87)))));
            this.PreviousThrows.Dock = System.Windows.Forms.DockStyle.Fill;
            this.PreviousThrows.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PreviousThrows.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.PreviousThrows.Location = new System.Drawing.Point(559, 15);
            this.PreviousThrows.Name = "PreviousThrows";
            this.PreviousThrows.Size = new System.Drawing.Size(205, 92);
            this.PreviousThrows.TabIndex = 6;
            this.PreviousThrows.Text = "Previous Throws";
            this.PreviousThrows.UseVisualStyleBackColor = false;
            this.PreviousThrows.Click += new System.EventHandler(this.PreviousThrows_Click);
            // 
            // NewThrow
            // 
            this.NewThrow.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(51)))), ((int)(((byte)(10)))), ((int)(((byte)(87)))));
            this.NewThrow.Dock = System.Windows.Forms.DockStyle.Fill;
            this.NewThrow.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NewThrow.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.NewThrow.Location = new System.Drawing.Point(559, 137);
            this.NewThrow.Name = "NewThrow";
            this.NewThrow.Size = new System.Drawing.Size(205, 92);
            this.NewThrow.TabIndex = 7;
            this.NewThrow.Text = "New Throw";
            this.NewThrow.UseVisualStyleBackColor = false;
            this.NewThrow.Click += new System.EventHandler(this.NewThrow_Click);
            // 
            // Reset
            // 
            this.Reset.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(51)))), ((int)(((byte)(10)))), ((int)(((byte)(87)))));
            this.Reset.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Reset.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Reset.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.Reset.Location = new System.Drawing.Point(559, 259);
            this.Reset.Name = "Reset";
            this.Reset.Size = new System.Drawing.Size(205, 92);
            this.Reset.TabIndex = 8;
            this.Reset.Text = "Reset";
            this.Reset.UseVisualStyleBackColor = false;
            // 
            // SpeedValue
            // 
            this.SpeedValue.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.SpeedValue, 3);
            this.SpeedValue.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SpeedValue.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SpeedValue.Location = new System.Drawing.Point(268, 12);
            this.SpeedValue.Name = "SpeedValue";
            this.tableLayoutPanel1.SetRowSpan(this.SpeedValue, 3);
            this.SpeedValue.Size = new System.Drawing.Size(259, 122);
            this.SpeedValue.TabIndex = 9;
            this.SpeedValue.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // RPMValue
            // 
            this.RPMValue.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.RPMValue, 3);
            this.RPMValue.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RPMValue.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RPMValue.Location = new System.Drawing.Point(268, 134);
            this.RPMValue.Name = "RPMValue";
            this.tableLayoutPanel1.SetRowSpan(this.RPMValue, 3);
            this.RPMValue.Size = new System.Drawing.Size(259, 122);
            this.RPMValue.TabIndex = 10;
            this.RPMValue.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LAValue
            // 
            this.LAValue.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.LAValue, 3);
            this.LAValue.Dock = System.Windows.Forms.DockStyle.Fill;
            this.LAValue.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LAValue.Location = new System.Drawing.Point(268, 256);
            this.LAValue.Name = "LAValue";
            this.tableLayoutPanel1.SetRowSpan(this.LAValue, 3);
            this.LAValue.Size = new System.Drawing.Size(259, 135);
            this.LAValue.TabIndex = 11;
            this.LAValue.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.TitlePanel);
            this.Name = "Form1";
            this.Text = "Tech Disc App";
            this.TitlePanel.ResumeLayout(false);
            this.TitlePanel.PerformLayout();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel TitlePanel;
        private System.Windows.Forms.Label TitleLabel;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label SpeedLabel;
        private System.Windows.Forms.Label RPMLabel;
        private System.Windows.Forms.Label LALabel;
        private System.Windows.Forms.Button PreviousThrows;
        private System.Windows.Forms.Button NewThrow;
        private System.Windows.Forms.Button Reset;
        private System.Windows.Forms.Label SpeedValue;
        private System.Windows.Forms.Label RPMValue;
        private System.Windows.Forms.Label LAValue;
    }
}

