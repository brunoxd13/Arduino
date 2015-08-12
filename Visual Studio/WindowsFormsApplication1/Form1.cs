using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        string RecebeDados;

        public Form1()
        {
            InitializeComponent();
            timerCOM.Enabled = true;
        }

        private void atualizaListaCOMs()
        {
            int i;
            bool Alterou;    //flag para sinalizar que a quantidade de portas mudou

            i = 0;

            Alterou = false;

            //se a quantidade de portas mudou
            if (comboBoxPortas.Items.Count == SerialPort.GetPortNames().Length)
            {
                foreach (string s in SerialPort.GetPortNames())
                {
                    if (comboBoxPortas.Items[i++].Equals(s) == false)
                    {
                        Alterou = true;
                    }
                }
            }
            else
            {
                Alterou = true;
            }

            //Se não foi detectado diferença
            if (Alterou == false)
            {
                return;                     //retorna
            }

            //limpa comboBox
            comboBoxPortas.Items.Clear();

            //adiciona todas as COM diponíveis na lista
            foreach (string s in SerialPort.GetPortNames())
            {
                comboBoxPortas.Items.Add(s);
            }
            //seleciona a primeira posição da lista
            comboBoxPortas.SelectedIndex = 0;
        }

        private void timerCOM_Tick(object sender, EventArgs e)
        {
            atualizaListaCOMs();
        }

        private void btConectar_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen == false)
            {
                try
                {
                    serialPort1.PortName = comboBoxPortas.Items[comboBoxPortas.SelectedIndex].ToString();
                    serialPort1.Open();

                }
                catch
                {
                    return;

                }
                if (serialPort1.IsOpen)
                {
                    btConectar.Text = "Desconectar";
                    comboBoxPortas.Enabled = false;

                }
            }
            else
            {

                try
                {
                    serialPort1.Close();
                    comboBoxPortas.Enabled = true;
                    btConectar.Text = "Conectar";
                }
                catch
                {
                    return;
                }

            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (serialPort1.IsOpen == true)  // se porta aberta
                serialPort1.Close();        	//fecha a porta
        }

        private void btEnviar_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen == true)          //porta está aberta
                serialPort1.Write(textBoxEnviar.Text);  //envia o texto presente no textbox Enviar
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            RecebeDados = serialPort1.ReadExisting();              //le o dado disponível na serial
            this.Invoke(new EventHandler(trataDadoRecebido));   //chama outra thread para escrever o dado no text box
        }

        private void trataDadoRecebido(object sender, EventArgs e)
        {
            textBoxReceber.AppendText(RecebeDados);
        }
    }
}
