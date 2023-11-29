package Thread;
import java.util.*;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
public class PrintExecutor {
    public static void main(String args[]) {
        System.out.println("Creating threads");
        Runnable Task1 = new PrintTask("Task1");
        Runnable Task2 = new PrintTask("Task2");
        Runnable Task3 = new PrintTask("Task3");
//        ExecutorService executor = Executors.newCachedThreadPool();
        ExecutorService executor = Executors.newCachedThreadPool();
        System.out.println("Threads and executor have been created, now starting the task...");
        executor.execute(Task1);
        executor.execute(Task2);
        executor.execute(Task3);
        executor.shutdown();
        System.out.println("Task terminated.");
        //System.out.println("Task terminated.");
    }
}
