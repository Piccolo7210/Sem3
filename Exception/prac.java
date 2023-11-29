package Exception;

import java.io.IOException;

public class prac {
    public static void main(String[] args) {
   try{
       chk();
   }
   catch (Exception e){
       System.out.println(e);
   }
    }
    public static void chk()throws IOException,ArithmeticException{
        try {
        throw new IOException("hello");
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Caught\n"+e);
        }
        finally {
            throw new ArithmeticException();
        }
    }
}
