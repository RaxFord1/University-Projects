using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            string sNumbers = inputTextBox.Text;
            var splitedNumbers = sNumbers.Split(',');
            int i;
            numbers = new int[splitedNumbers.Length];
            int counter=0;
            foreach (var num in splitedNumbers)
            {
                if (num == "" || num ==" ")
                {
                    continue;
                }
                if (!int.TryParse(num, out i))
                {
                    sumOutput.Text = "Error";
                    return;
                } else {
                    numbers[counter] = i;
                    counter++;
                }
            }
            sumOutput.Text = "Added";
        }
        public int SumElements()
        {
            int sum = 0;
            if (numbers != null)
            {
                if (radioButton1.Checked)
                {
                    sum = 0;
                    foreach (int num in numbers)
                    {
                        sum += num * num;
                    }
                    return sum;
                }
                else
                {
                    sum = numbers.Sum();
                }
            }
            return sum;
             
        }
        private void button1_Click_1(object sender, EventArgs e)
        {
            sumOutput.Text = SumElements().ToString();

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2(); // Instantiate a Form3 object.
            f2.Show();
            f2.frm1 = this;
        }
    }
}
