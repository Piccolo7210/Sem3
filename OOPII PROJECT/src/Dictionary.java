import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import javax.swing.*;
import java.awt.*;
public class Dictionary {
	private static final String DICTIONARY_FILE = "E:\\JAVA 1-2\\OOPII PROJECT\\src\\dictionary.txt";
	public  Map<String, String> Synnonyms = new HashMap<>();
	public Map<String, String> Definitions = new HashMap<>();
	public  Map<String, String> Antonyms = new HashMap<>();
	public Dictionary() {
		this.loadDictionary();
//		this.worldlist();
	}
	public void loadDictionary() {
	        try (BufferedReader reader = new BufferedReader(new FileReader(DICTIONARY_FILE))) {
	            String line;
	            while ((line = reader.readLine()) != null) {
	                String[] parts = line.split(":");
	                if (parts.length == 4) {
	                    String word = parts[0].trim();
	                    String def = parts[1].trim();
	                    String synnonym = parts[2].trim();
	                    String antonym = parts[3].trim();
	                    Definitions.put(word, def);
	                    Synnonyms.put(word, synnonym);
	                    Antonyms.put(word, antonym);
	                }
	            }
	        } catch (IOException e) {
	            JOptionPane.showInternalMessageDialog(null,"Error loading dictionary (IO Exception)", "IOException",JOptionPane.PLAIN_MESSAGE );
	            System.exit(0);
	        }
	    }
	public void worldlist() {
		 Iterator it = this.Definitions.entrySet().iterator();
	        System.out.println("words:");
	        while (it.hasNext()) {
	            Map.Entry mapElement = (Map.Entry)it.next();
	            System.out.println(mapElement.getKey() );
	        }
	}
}
