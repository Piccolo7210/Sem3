package Thread;

import java.util.*;
public class ArrayWriter implements Runnable {

    private final SimpleArray sharedArray;
    private final int StartValue;
    public ArrayWriter(int value ,SimpleArray obj){
        sharedArray = obj;
        StartValue = value;
    }
    public void run() {

        for(int i=StartValue;i<StartValue+3;i++) sharedArray.add(i);
    }
}

