package qr;

import com.barcodelib.barcode.QRCode;

public class Generar {
	
	public boolean Generate(String nom) {
        try {
            QRCode obj = new QRCode();
            int i;
            i = 1;
            String name;
            obj.setData(nom);// datos en donde va a ir el qr
            obj.setModuleSize(5.0f);//tama�o de la imagen en double\
            name="D:\\Traductor\\Qr "+i+".jpeg";
            obj.renderBarcode(name);//destino
            i++;
            return true;
        } catch (Exception e) {
            System.out.println("Error" + e.getMessage());
            return false;
        }
    }

}
