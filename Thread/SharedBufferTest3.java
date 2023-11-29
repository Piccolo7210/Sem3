package Thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SharedBufferTest3 {
    public static void main( String[] args )
    {
        // create a newCachedThreadPool
        ExecutorService application = Executors.newCachedThreadPool();

        // create SynchronizedBuffer to store ints
        Buffer sharedLocation = new SynchronizedBuffer2();

        System.out.printf( "%-40s%s\t\t%s\n%-40s%s\n\n", "Operation",
                "Buffer", "Occupied", "---------", "------\t\t--------" );

        // execute the Producer and Consumer tasks
        application.execute( new Producer( sharedLocation ) );
        application.execute( new Consumer( sharedLocation ) );

        application.shutdown();
    } // end main
}