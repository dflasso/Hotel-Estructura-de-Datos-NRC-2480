package qr;

import java.awt.Desktop;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.JOptionPane;

public class AppQR {

	public static void main(String[] args) throws IOException {
		Generar codigo = new Generar();
        String qr = "", cadena, archivo = "D:\\Hotel-clientesQR.txt";
        try 
        {
            FileReader f = new FileReader(archivo);
            try (BufferedReader b = new BufferedReader(f)) {
                while ((cadena = b.readLine()) != null) {
                    qr = qr + cadena+"\n";
                }
            }
        } catch (IOException e){
            System.out.println("Error" + e.getMessage());
            JOptionPane.showMessageDialog(null, "No se ha podido generar su imagen QR","Creacion de QR",JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        
        if(codigo.Generate(qr))
        {
            int i = 1;
            String name;
            name="D:\\Qr "+i+".jpeg";
            JOptionPane.showMessageDialog(null, "Se ha generado su imagen QR","Creacion de QR",JOptionPane.INFORMATION_MESSAGE);
            File file = new File(name);
            Desktop app = Desktop.getDesktop();//para abrir la imagen
            app.open(file);
         }
         else
             JOptionPane.showMessageDialog(null, "No se ha podido generar su imagen QR","Creacion de QR",JOptionPane.ERROR_MESSAGE);
        System.exit(0);
    }

}

