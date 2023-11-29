package Thread;
import java.util.concurrent.*;
public class MyMain {
    public static void main(String[] args) {
        prac t1 = new prac("task1");
        prac t2 = new prac("task2");
        ExecutorService executor = Executors.newCachedThreadPool();
        executor.execute(t1);
        executor.execute(t2);
        executor.shutdown();
        System.out.println("main shutdown");

    }
}
