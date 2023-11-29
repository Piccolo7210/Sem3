package Thread;
import java.util.*;
public class SimpleArray {
    private final int arr[];
    private int writeindex = 0;
    private final static Random generator = new Random();
    public SimpleArray(int size) {
        arr= new int [size];
    }
    public synchronized void add (int value) {
        int position = writeindex;

        arr[position]=value;
        System.out.printf("%s wrote %d in index of %d.\n",Thread.currentThread().getName(),value,position);
        writeindex++;
        System.out.printf("Next Index to write is %d.\n",writeindex);
        try {
            Thread.sleep(generator.nextInt(500));
        }
        catch(InterruptedException e) {
            System.out.println("Exception.");
        }
    }
    public String toString() {
        String arrayString;
        arrayString="\nContents of the array is :\n";
        for(int i=0;i<arr.length;i++) {
            arrayString+=arr[i]+" ";
        }
        return arrayString;
    }
}
