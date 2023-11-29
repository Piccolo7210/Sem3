package Thread;

import java.util.concurrent.*;

public class BlockingBuffer implements Buffer {
    public final ArrayBlockingQueue<Integer> buffer;// end BlockingBuffer constructor
    public BlockingBuffer(){
        buffer = new ArrayBlockingQueue<Integer>(1);
    }
    // place value into buffer
    public void set(int value) throws InterruptedException {
        buffer.put(value); // place value in buffer
        System.out.printf("%s%2d\t%s%d", "Producer writes", value, " Buffer cells occupied: ", buffer.size());
    } // end method set

    public int get() throws InterruptedException {
        int readValue = 0; // initialize value read from buffer

        readValue = buffer.take(); // remove value from buffer
        System.out.printf("%s%2d\t%s%d", "Consumer reads",
                readValue, "Buffer cells occupied: ", buffer.size());

        return readValue;
    } // end method get
} // end class BlockingBuffer
