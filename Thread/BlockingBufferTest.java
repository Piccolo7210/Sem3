package Thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class BlockingBufferTest
{
    public static void main( String[] args )
    {
        // create new thread pool with two threads
        ExecutorService application = Executors.newCachedThreadPool();

        // create BlockingBuffer to store ints
        Buffer sharedLocation = new BlockingBuffer();

        System.out.println( "Action\t\tValue\tSum of Produced\tSum of Consumed" );
        System.out.println("------\t\t-----\t---------------\t---------------\n" );
        application.execute( new Producer( sharedLocation ) );
        application.execute( new Consumer( sharedLocation ) );

        application.shutdown(); // terminate application when tasks complete
    } // end main
} // end class SharedBufferTest