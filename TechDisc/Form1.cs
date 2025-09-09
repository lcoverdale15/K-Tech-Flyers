using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TechDisc
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Function for when we press the previous throws button. 
        /// All it does is open a TXT file which stores the 
        /// previous throws.
        /// </summary>
        /// <param name="sender">Previous Throw Button</param>
        /// <param name="e">What event triggered the function</param>
        private void PreviousThrows_Click(object sender, EventArgs e)
        {
            String filename = @"C:\Users\footb\source\repos\K-Tech-Flyers\Previous Throws.txt";
            if (File.Exists(filename))
            {
                Process.Start(new ProcessStartInfo(filename) { UseShellExecute = true });
            }
            else
            {
                MessageBox.Show("File not found!");
            }
        }

        /// <summary>
        /// Function for when we press the new throw button.
        /// Will write current data of most recent throw to previous throws.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void NewThrow_Click(object sender, EventArgs e)
        {

        }
    }
}
