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
            this.TDLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // TDLabel
            // 
            this.TDLabel.AutoSize = true;
            this.TDLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(51)))), ((int)(((byte)(10)))), ((int)(((byte)(87)))));
            this.TDLabel.Font = new System.Drawing.Font("Bookman Old Style", 28F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TDLabel.ForeColor = System.Drawing.Color.White;
            this.TDLabel.Location = new System.Drawing.Point(34, 9);
            this.TDLabel.Name = "TDLabel";
            this.TDLabel.Size = new System.Drawing.Size(731, 65);
            this.TDLabel.TabIndex = 0;
            this.TDLabel.Text = "K-Tech Flyers Tech Disc";
            this.TDLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.TDLabel);
            this.Name = "Form1";
            this.Text = "Tech Disc App";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label TDLabel;
    }
}

