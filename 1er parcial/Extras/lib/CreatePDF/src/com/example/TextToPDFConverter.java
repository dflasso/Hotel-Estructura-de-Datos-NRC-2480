package com.example;
 
import java.io.BufferedReader;  
import java.io.DataInputStream;  
import java.io.File;  
import java.io.FileInputStream;  
import java.io.FileOutputStream;  
import java.io.InputStreamReader;  
import com.itextpdf.text.Document;  
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.Element;  
import com.itextpdf.text.Font;  
import com.itextpdf.text.Paragraph;  
import com.itextpdf.text.pdf.PdfWriter;
import java.awt.Desktop;
import java.io.IOException;
import javax.swing.JOptionPane;
 
public class TextToPDFConverter {  
 
 
    public static void main(String[] args) throws Exception {  
 
        // TODO Auto-generated method stub  
        File file = new File("D:\\Hotel-clientes.txt");
 
        if(file.getName().endsWith(".txt")){
 
            if(convertTextToPDF(file)){
                JOptionPane.showMessageDialog(null, "Se ha generado su PDF","Creacion de PDF",JOptionPane.INFORMATION_MESSAGE);
                File archivo = new File("D:\\Reservacion.pdf");
                Desktop app = Desktop.getDesktop();
                app.open(archivo);
            }
            else
                JOptionPane.showMessageDialog(null, "No se ha podido generar su archivo PDF","Creacion de PDF",JOptionPane.ERROR_MESSAGE);
        }
        System.exit(0);             
    }  
 
    public static boolean convertTextToPDF(File file) throws Exception  
    {  
 
        FileInputStream fis=null;  
        DataInputStream in=null;  
        InputStreamReader isr=null;  
        BufferedReader br=null;  
 
        try {  
 
            Document pdfDoc = new Document();  
            String output_file =file.getParent()+""+"Reservacion.pdf";  
            @SuppressWarnings("unused")
			PdfWriter writer=PdfWriter.getInstance(pdfDoc,new FileOutputStream(output_file));  
            pdfDoc.open();  
            pdfDoc.setMarginMirroring(true);  
            pdfDoc.setMargins(36, 72, 108,180);  
            pdfDoc.topMargin();  
            Font myfont = new Font();  
            Font bold_font = new Font();  
            bold_font.setStyle(Font.BOLD);  
            bold_font.setSize(10);  
            myfont.setStyle(Font.NORMAL);  
            myfont.setSize(10);  
            pdfDoc.add(new Paragraph("\n"));  
 
            if(file.exists()){  
 
                fis = new FileInputStream(file);  
                in = new DataInputStream(fis);  
                isr=new InputStreamReader(in);  
                br = new BufferedReader(isr);  
                String strLine;  
 
                while ((strLine = br.readLine()) != null)  {  
 
                    Paragraph para =new Paragraph(strLine+"\n",myfont);  
                    para.setAlignment(Element.ALIGN_JUSTIFIED);  
                    pdfDoc.add(para);  
                }  
            }     
            else {  
 
                System.out.println("no such file exists!");
                return false;  
            }  
            pdfDoc.close();   
        }  
 
        catch(DocumentException e) {  
            System.out.println("Exception: " + e.getMessage());  
        } catch (IOException e) {
            System.out.println("Exception: " + e.getMessage());
        }  
        finally {  
 
            if(br!=null)  
            {  
                br.close();  
            }  
            if(fis!=null)  
            {  
                fis.close();  
            }  
            if(in!=null)  
            {  
                in.close();  
            }  
            if(isr!=null)  
            {  
                isr.close();  
            }  
 
        }  
        return true;  
    }  
}  