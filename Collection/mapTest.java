package Collection;

import java.util.*;

public class mapTest {
    private final static String str ="To be or not to be: that is the question Whether 'tis nobler to suffer";
    Map<String,Integer> map ;
    public mapTest(){
        map =new HashMap<String,Integer>();
        Scanner sc = new Scanner(System.in);
        createMap();
        displayMap();
    }
    public void createMap(){
        StringTokenizer tokenizer = new StringTokenizer(str);
        while(tokenizer.hasMoreTokens()){
            String word = tokenizer.nextToken().toLowerCase();
            if(map.containsKey(word)){
                map.put(word,map.get(word)+1);
            }
            else {
                map.put(word,1);
            }
        }
    }
    public void displayMap(){
        Set<String> keys = map.keySet();
        SortedSet< String> sortedKeys = new TreeSet<String>(keys);
        System.out.println("KEY        VALUE");
        for(String s: sortedKeys){
            System.out.println(s+"          "+map.get(s));
        }
    }

    public static void main(String[] args) {
        new mapTest();
    }
}
