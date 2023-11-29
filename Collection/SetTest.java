package Collection;

 import org.w3c.dom.ls.LSOutput;

 import java.util.*;

public class SetTest
 {
 private static final String colors[] = { "red","white","blue",
 "green", "gray", "orange", "tan", "white", "cyan",
 "peach", "gray", "orange" };

         // create and output ArrayList
         public SetTest()
         {
        List<String > list = Arrays.asList( colors );
        System.out.printf( "ArrayList: %s\n", list );
        printNonDuplicates( list );
        }
     private void printNonDuplicates( Collection<String> collection )
         {

      SortedSet <String>  set = new TreeSet<String >( collection );

     System.out.println( "\nNonduplicates are:" );

      for ( String s : set )
      System.out.printf( "%s ", s );

      System.out.println();
             System.out.println("Head set of orange: \n");
             //System.out.println(set.tailSet("orange"));
             } // end method printNonDuplicates


 public static void main( String args[] )
 {
 new SetTest();
 } // end main
 } // end class