using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace DrawingForms2_2019
{
    public partial class Form1 : Form
    {
        Graphics gr;
        int mySize = 2;
        DashStyle myStyle = DashStyle.Solid;
        Color myColor = Color.DarkBlue;
        int initialX = 0;
        int initialY = 0;
        Rectangle myRect;
        public Form1()
        {
            InitializeComponent();
        }

        private void quitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gr = panel1.CreateGraphics();
            gr.SmoothingMode = SmoothingMode.AntiAlias;
            this.DoubleBuffered = true;
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            initialX = e.X;
            initialY = e.Y;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                myRect = new Rectangle(initialX, initialY, e.X - initialX, e.Y - initialY);
                toolTip1.SetToolTip(this.panel1, e.X.ToString() + "," + e.Y.ToString());
                panel1.Invalidate();
            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            using(Pen myPen = new Pen(myColor,mySize))
            {
                myPen.DashStyle = myStyle;
                gr.DrawRectangle(myPen, myRect);
            }
        }

        private void dashToolStripMenuItem_Click(object sender, EventArgs e)
        {
            myStyle = DashStyle.Dash;
        }

        private void dashDotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            myStyle = DashStyle.DashDot;
        }

        private void dashDotDotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            myStyle = DashStyle.DashDotDot;
        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            mySize = 4;
        }

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            mySize = 6;
        }

        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            mySize = 8;
        }

        private void newColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
           DialogResult dlgRes = colorDialog1.ShowDialog();
            if(dlgRes == DialogResult.OK)
            {
                myColor = colorDialog1.Color;
            }
        }

        private void panel1_MouseEnter(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Cross;
        }

        private void panel1_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }
    }
}
