using System;
using System.Windows.Forms;


namespace WinAppMSAgentsManagement
{
    public partial class frmAgentManagement : Form
    {
        private CAgent mObjAgent;
        public frmAgentManagement()
        {

            InitializeComponent();
        }
        public void LoadAgent()
        {

            mObjAgent = new CAgent("Genie", this, 100, 50); //Tipo de Agente

            mObjAgent.ShowAgent(this);
            //mObjAgent.Ingreso(this); // Bienvenida al Traductor
            //mObjAgent.Puntaje(this); //Traduce la palabra
            //mObjAgent.Imagen(this); // Mensaje para ejecutar la imagen
            //mObjAgent.PDF(this); //Mensaje para la creacion del PDF
            //mObjAgent.QR(this); //Mensaje para generar codigo QR
            //mObjAgent.Backup(this); // Mensaje para ejecutar el backup
            mObjAgent.Mongo(this); // Mensaje para ejecutar la base de datos
            //mObjAgent.Salida(this); //Mensaje para finalizar el Traductor
        }
        private void frmAgentManagement_Load(object sender, EventArgs e)
        {
            LoadAgent();
        }
    }
}
