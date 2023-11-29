package Collection;
import java.util.LinkedList;
import java.util.Arrays;

public class UsingToArray
{
    // constructor creates LinkedList, adds elements and converts to array
    public UsingToArray()
    {
        String colors[] = { "black", "blue", "yellow" };

        LinkedList < String > links = new LinkedList< String >( );
        links.add( "red" );   // add as last item
        links.add( "pink" );      // add to the end
//        links.add( 3, "green" );  // add at 3rd index
//        links.addFirst( "cyan" ); // add as first item

// get LinkedList elements as an array
       // colors = links.toArray( new String[ links.size() ] );
        System.arraycopy(links.toArray(new String[0]),0,colors,0,links.size());
        System.out.println( "colors: " );
        for ( String color : colors )
            System.out.println( color );

        System.out.println(links.indexOf("black"));

    } // end UsingToArray constructor

    public static void main( String args[] )
    {
        new UsingToArray();
    } // end main
} // end class UsingToArray
