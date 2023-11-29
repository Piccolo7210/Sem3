package Thread;
import java.util.*;
import java.lang.*;
public class prac implements Runnable{
    private final int sleeptime;
    private final String taskName;
    private final static Random generator = new Random() ;
    public prac(String name){
    sleeptime = generator.nextInt(500);
    taskName=name;
    }
    public void run() {
        try{
            System.out.println(taskName+" is going to sleep for "+sleeptime);
            Thread.sleep(sleeptime);
        }
        catch (InterruptedException e){
            System.out.println(e);
        }
        System.out.println("Sleeping done task: "+taskName);
    }
}
