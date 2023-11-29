package Thread;

import java.util.Random;

 public class Consumer implements Runnable {
     private final static Random generator = new Random();
     private final Buffer sharedLocation; // reference to shared object

     // constructor
     public Consumer(Buffer shared) {
         sharedLocation = shared;
     } // end Consumer constructor

     // read sharedLocation&#39;s value 10 times and sum the values
     public void run() {
         int sum = 0;

         for (int count = 1; count <= 10; count++) {
             // sleep 0 to 3 seconds, read value from buffer and add to sum
             try {
                 Thread.sleep(generator.nextInt(3000));
                 sum += sharedLocation.get();
                 System.out.printf("\t\t\t%2d\n", sum);
             } // end try
             catch (InterruptedException e) {
                 e.printStackTrace();
             }
         }
         System.out.println("Consumer reads total value: "+sum+"\n Terminating Consumer");
     }
 }