package Thread;

import java.util.*;
public class PrintTask implements Runnable{
    private final int sleeptime;
    private final String taskName;
    private final static Random generator = new Random();
    public PrintTask(String name) {
        taskName=name;
        sleeptime= 20000;
    }
    public  void run(){
        try {
            System.out.printf("Taskname - %s is going to sleepfor %d milliseconds.\n",taskName,sleeptime);
            Thread.sleep(sleeptime);
        }
        catch(InterruptedException e){
            System.out.printf("%s is terminated becasue of Exception %s .",taskName,e.toString());
        }
        System.out.println("Task "+taskName+" Done Sleeping.");
    }
    public void hello(){
        System.out.println("Hello\n");
    }

}

