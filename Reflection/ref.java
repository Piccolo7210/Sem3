package Reflection;

import java.lang.reflect.*;
import java.util.*;

public class ref {
    public static void main(String[] args) throws IllegalAccessException {
        Cat mycat = new Cat("Bilai",5);
        System.out.println("My cat name: "+mycat.getName());

        Class c = mycat.getClass();
        Field[] fields = c.getDeclaredFields();
        for(Field e : fields) {
            if(e.getName().equals("Name")){
                e.setAccessible(true);
                e.set(mycat,"Halum");
            }
            System.out.println(e.getName());

        }
        System.out.printf("My cat name is now: "+mycat.getName());
    }
}
