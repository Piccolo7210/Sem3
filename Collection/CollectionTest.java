package Collection;

import java.util.*;

public class CollectionTest
{
    private static final String[] colors = { "MAGENTA", "RED", "WHITE", "BLUE", "CYAN" };
    private static final String[] removeColors = { "RED", "WHITE", "BLUE","YELLOW" };
    // create ArrayList, add Colors to it and manipulate it
    public CollectionTest()
    {
        List< String > list = new ArrayList< String >();
        List< String > removeList = new ArrayList< String >();
        // add elements in colors array to list
		for ( String color : colors )
			list.add( color );
//        list= Arrays.asList(colors);
        // add elements in removeColors to removeList
        for ( String color : removeColors )
            removeList.add( color );
        list.addAll(removeList);
        list.subList(5,9).clear();
        System.out.println( "ArrayList: " );
        // output list contents
        for ( int count = 0; count < list.size(); count++ )
            System.out.printf( "%s ", list.get( count ) );
        // remove colors contained in removeList
        removeColors( list, removeList );
        System.out.println( "\n\nArrayList after calling removeColors: " );
// output list contents
        for ( String color : list )
            System.out.printf( "%s ", color );
    } // end CollectionTest constructor
    // remove colors specified in collection2 from collection1
    private void removeColors( Collection< String > collection1, Collection< String > collection2 )
    {
        // get iterator
        Iterator< String > iterator = collection1.iterator();
        // loop while collection has items
        while ( iterator.hasNext() )
            if ( collection2.contains( iterator.next() ) )
                iterator.remove(); // remove current Color
    } // end method removeColors

    public static void main( String args[] )
    {
        new CollectionTest();
    } // end main
} // end class CollectionTest