package Mongo;

import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.Mongo;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.net.UnknownHostException;
import java.io.File;
import java.io.FileWriter;
import java.util. *;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.BufferedWriter;

public class AppMongoConnection {
	public DB db;
	public DBCollection tabla;
	public DBCursor cursor;

	public static void main(String[] args) throws IOException {
		AppMongoConnection Obj = new AppMongoConnection();
		//Obj.InsertarTabla();
		Obj.DesplegarBD();		
	}
	
	public void InsertarTabla() throws IOException
	{
		AppMongoConnection Obj = new AppMongoConnection();
		BasicDBObject documento=new BasicDBObject();
		File file=new File("D:\\Traductor\\BD.txt");
		String linea,espaniol = null,ingles= null;
		BufferedReader br=new BufferedReader(new FileReader(file));
		while((linea=br.readLine())!=null)
		{
			StringTokenizer st=new StringTokenizer(linea,";");
			espaniol=st.nextToken().trim();
			ingles=st.nextToken().trim();
		}
		br.close();
		try
		{
			Mongo mongo=new Mongo("localhost",27017);
			Obj.db=mongo.getDB("basededatosTraductor");
			Obj.tabla=Obj.db.getCollection("tabla");
		}catch (UnknownHostException exc) {
			Logger.getLogger(AppMongoConnection.class.getName()).log(Level.SEVERE, null, exc);
		}
		System.out.println(espaniol);
		System.out.println(ingles);
		documento.put("Espaniol", espaniol);
		documento.put("Ingles", ingles);
		Obj.tabla.insert(documento);
	}
	
	public void DesplegarBD()throws IOException
	{
		AppMongoConnection Obj = new AppMongoConnection();
		File file=new File("D:\\Traductor\\BDConsole.txt");
		FileWriter fw;
		BufferedWriter bw;
		fw=new FileWriter(file);
		bw=new BufferedWriter(fw);
		try
		{
			Mongo mongo=new Mongo("localhost",27017);
			Obj.db=mongo.getDB("basededatosTraductor");
			Obj.tabla=Obj.db.getCollection("tabla");
		}catch (UnknownHostException exc) {
			Logger.getLogger(AppMongoConnection.class.getName()).log(Level.SEVERE, null, exc);
		}
		Obj.cursor=Obj.tabla.find();
		while(Obj.cursor.hasNext())
		{
			//try{
				bw.write(Obj.cursor.next().toString());
				bw.append("\r\n"); //Salto de linea en un archivo.
/*			}catch(IOException ex){
				System.out.println(ex);
			}*/
		}
		bw.close();
		fw.close();
	}
	
}