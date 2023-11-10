import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DictionaryApp {
    public Dictionary Dic;
    public DictionaryApp() {
    	Dic= new Dictionary();
    }
    public  void menu() {
    	Dic.loadDictionary();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Dictionary App Menu:");
            System.out.println("1. Lookup a word");
            System.out.println("2. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter the word to lookup: ");
                    String wordToLookup = scanner.nextLine();
                    lookupWord(wordToLookup);
                    break;
                case 2:
                    System.out.println("Exiting Dictionary App.");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private  void lookupWord(String word) {
       String definition = Dic.Definitions.get(word);
        if (definition != null) {
            System.out.print("Definition: " + definition);
            String Synnonym = Dic.Synnonyms.get(word);
            if(Synnonym != null) {
            	System.out.print("  Synnonym: " + Synnonym+"  ");
            	String Antonym = Dic.Antonyms.get(word);
            	if(Antonym !=null) {
            		System.out.println("Antonym: " + Antonym);
            	}
            	else {
            		System.out.println("Antonym not found in the dictionary.");
            	}
            }
            else {
            	System.out.println("Synnonym not found in the dictionary.");
            }
       
        } else {
            System.out.println("Word not found in the dictionary.");
        }
    }    
}
