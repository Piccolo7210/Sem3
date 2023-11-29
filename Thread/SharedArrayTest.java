package Thread;
import java.util.*;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.ExecutorService;
public class SharedArrayTest {
    public static void main(String args[]) {
       SimpleArray sharedArray = new SimpleArray(6);
       ArrayWriter writer1 = new ArrayWriter(1,sharedArray);
        ArrayWriter writer2 = new ArrayWriter(10,sharedArray);
       ExecutorService executor = Executors.newCachedThreadPool();
       executor.execute(writer1);
       executor.execute(writer2);
       executor.shutdown();
        try {
            boolean taskEnd = executor.awaitTermination(1,TimeUnit.MINUTES);
            if(taskEnd) {
                System.out.printf("%s",sharedArray);
            }
            else {
                System.out.println("Time out while wating for task to be finished.");
            }
        }
        catch (InterruptedException e) {
            System.out.println("Interrupted.");
        }

    }
}

