package Thread;
import java.util.*;
public class Printtest {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        System.out.println("Creating Threads....");

        Runnable Task2 = new PrintTask("Task2");
        Runnable Task3 = new PrintTask("Task3");
        Thread t1 = new Thread( new PrintTask("Task1"));
        Thread t2 = new Thread(Task2);
        Thread t3 = new Thread(Task3);
        System.out.println("Threads have been created, now starting the task...");
        t1.start();
        t2.start();
        t3.start();
        System.out.println("Task terminated.");
    }

}
