using System;
using System.Threading;
using System.Windows.Forms;

using AxAgentObjects;

namespace WinAppMSAgentsManagement
{
    class CAgent
    {
        #region Atributes of the class
        ///<summary>
        ///Datos o variables miembro
        ///</summary>

        private AxAgent mMSAgent = new AxAgent();
        private string mName;
        private int mX, mY;
        private int mVoice;
        private int mCadence;

        #endregion

        #region Propiedades
        ///<summary>
        ///Manejo de descriptores de acceso
        ///</summary>   

        public AxAgent MSAgente
        {
            get { return mMSAgent; }
            set { mMSAgent = value; }
        }

        public string Name
        {
            get { return mName; }
            set { mName = value; }
        }

        public int X
        {
            get { return mX; }
            set { mX = value; }
        }

        public int Y
        {
            get { return mY; }
            set { mY = value; }
        }

        public int Voice
        {
            get { return mVoice; }
            set { mVoice = value; }
        }

        public int Cadence
        {
            get { return mCadence; }
            set { mCadence = value; }
        }

        #endregion

        #region Builders of the Class
        ///<summary>
        /// Constructores
        ///</summary>

        // Constructor por defecto
        public CAgent()
        {

        }

        public CAgent(string Name, Form ObjForm, int xBegin, int yEnd)
        {
            mCadence = 100;
            mVoice = 200;
            mX = xBegin;
            mY = yEnd;
            mName = Name;
            mMSAgent.BeginInit();
            ObjForm.Controls.Add(mMSAgent);
            mMSAgent.EndInit();
            mMSAgent.Characters.Load(mName, mName + ".acs");
            mMSAgent.BringToFront();
        }

        #endregion

        #region Methods
        ///<summary>
        ///Funciones miembro
        ///</summary>  

        public void ChooseLanguage(Boolean op)
        {
            if (op == true)
            {
                // Idioma Español
                mMSAgent.Characters[mName].LanguageID = 3082;
            }
            else
            {
                // Idioma Inglés
                mMSAgent.Characters[mName].LanguageID = 0x409;
            }
        }

        public void ChooseVoice(int tone)
        {
            mVoice = tone;
        }

        public void setCadence(int Cadence)
        {
            mCadence = Cadence;
        }

        public void GoStartPosition(Form formulario)
        {
            mMSAgent.Characters[mName].MoveTo(100, 100, mCadence);
        }

        public void HideAgent()
        {
            StopAgent();
            mMSAgent.Characters[mName].Hide(null);
        }

        public void FireAgent()
        {
            StopAgent();
            mMSAgent.Characters[mName].Play("Wave");
        }

        public void StopAgent()
        {
            mMSAgent.Characters[mName].StopAll("Play");
            mMSAgent.Characters[mName].StopAll("Speak");
            mMSAgent.Characters[mName].StopAll("Move");
        }

        public void ShowAgent(Form formulario)
        {
            StopAgent();
            mMSAgent.BringToFront();
            mMSAgent.Characters[mName].MoveTo(1000,90, mCadence);
            mMSAgent.Characters[mName].Show(1);
        }
        public void Puntaje(Form ObjForm)
        {
            string lineSpa, lineEng;
            System.IO.StreamReader file = new System.IO.StreamReader("C:\\Traductor\\Agente.txt");
            lineSpa = file.ReadLine();
            lineEng = file.ReadLine();
            file.Close();
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("Announce");
            Thread.Sleep(10000);
            Application.Exit();
        }
        public void Ingreso(Form ObjForm)
        {
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("Greet");
            mMSAgent.Characters[mName].Speak("Bienvenido al juego.", null);
            Thread.Sleep(10000);
            Application.Exit();
        }
        public void Imagen(Form ObjForm)
        {
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("GestureRight");
            mMSAgent.Characters[mName].Speak("Usted esta ejecutando su imagen en consola.", null);
            Thread.Sleep(10000);
            Application.Exit();
        }
        public void PDF(Form ObjForm)
        {
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("DoMagic1");
            mMSAgent.Characters[mName].Speak("Usted esta creando su PDF.", null);
            mMSAgent.Characters[mName].Play("DoMagic2");            
            Thread.Sleep(15000);
            Application.Exit();
        }

        public void QR(Form ObjForm)
        {
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("DoMagic1");
            mMSAgent.Characters[mName].Speak("Usted acaba de generar su codigo QR.", null);
            mMSAgent.Characters[mName].Play("DoMagic2");
            Thread.Sleep(15000);
            Application.Exit();
        }
        public void Backup(Form ObjForm)
        {
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("GestureRight");
            mMSAgent.Characters[mName].Speak("Usted está generando su Backup.", null);
            mMSAgent.Characters[mName].Play("DoMagic1");
            Thread.Sleep(15000);
            Application.Exit();
        }
        public void Mongo(Form ObjForm)
        {
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("GestureRight");
            mMSAgent.Characters[mName].Speak("Usted está desplegando toda la información de la base de datos 'Mongo'.", null);
            mMSAgent.Characters[mName].Play("DoMagic1");
            Thread.Sleep(15000);
            Application.Exit();
        }
        public void Salida(Form ObjForm)
        {
            mMSAgent.Characters[mName].Balloon.Style = 7;
            mMSAgent.Characters[mName].Play("Wave");
            mMSAgent.Characters[mName].Speak("Espero que hayas disfrutado del juego.", null);
            mMSAgent.Characters[mName].Play("Hide");
            Thread.Sleep(10000);
            Application.Exit();
        }

        public void IniciarBienvenida(Form ObjForm)
        {
            /*string line;
            System.IO.StreamReader file = new System.IO.StreamReader("D:\\Agente.txt");
            line = file.ReadLine();
            file.Close();
            

            mMSAgent.Characters[mName].Balloon.Style = 7;
            //mMSAgent.Characters[mName].Play("Greet");
            //mMSAgent.Characters[mName].Play("Announce");
            //mMSAgent.Characters[mName].Speak("\\pit=" + Voice + "\\ ", null);
            
            //mMSAgent.Characters[mName].Play("Blink");
            // mMSAgent.Characters[mName].MoveTo(100, 300, mCadence);
            //mMSAgent.Characters[mName].Play("GestureRight"); // mueve el brazo derecho
            //mMSAgent.Characters[mName].Speak("Para jugar, debes pensar en uno de estos animales, " +
                                                "y yo intentaré adivinarlo.", null);
            mMSAgent.Characters[mName].Play("Sad");
          //  mMSAgent.Characters[mName].Play("DoMagic2");
            
            Thread.Sleep(13000);
            Application.Exit();
            //*/
        }
        #endregion
    }
}
