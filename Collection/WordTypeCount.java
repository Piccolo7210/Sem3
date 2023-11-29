package Collection;

import java.util.*;

public class WordTypeCount {
     private Map<String, Integer> map;
     private Scanner scanner;

     public WordTypeCount() {
         map = new HashMap<String, Integer>(); // create HashMap
         scanner = new Scanner(System.in); // create scanner
         createMap(); // create map based on user input
         displayMap(); // display map content
     } // end

     private void createMap() {
         System.out.println( "Enter a string:" ); // prompt for user input
         String input = scanner.nextLine();

         // create StringTokenizer for input
         StringTokenizer tokenizer = new StringTokenizer(input);

         // processing input text
         while (tokenizer.hasMoreTokens()) // while more input
         {
             String word = tokenizer.nextToken().toLowerCase(); // get word

             // if the map contains the word
             if (map.containsKey(word)) // is word in map
             {
                 int count = map.get(word); // get current count
                 map.put(word, count + 1); // increment count
             } // end if
             else
                 map.put(word, 1); // add new word with a count of 1 to map
         } // end while
     }

     private void displayMap() {
         Set <String> keys = map.keySet(); // get keys

         // sort key
         SortedSet< String> sortedKeys = new TreeSet<String>(keys);

         System.out.println( "Map contains:\nKey\t\tValue" );
        // System.out.println("Map size: "+map.size());
         // generate output for each key in map
         for (String key : sortedKeys)
             System.out.printf( "%-10s %10d\n",key, map.get(key).intValue() );

         System.out.printf("\nsize:%d\nisEmpty:%b\n",map.size(), map.isEmpty() );
     }

     public static void main(String[] args) {
         new WordTypeCount();
     }
 }
