/**
 *  RaceCond
 *  ========
 *
 *  > From ch2d1
 *
 *  An example of race conditions.
 */

class Counter {
    private int count = 0;
    public void increment() { ++count; }    // Not synchronized, hence the race
    // public synchronized void increment() { ++count; }
    public int getCount() { return count; } // Not a thread-safe method 
}

public class RaceCond {
    // The main thread should report exception to await other threads
    public static void main(String[] args) throws InterruptedException {
        final Counter counter = new Counter();
        class CountingThread extends Thread {
            public void run() {
                for (int i = 0; i < 1000; ++i) counter.increment();
            }
        }

        CountingThread t1 = new CountingThread();
        CountingThread t2 = new CountingThread();
        t1.start(); t2.start();
        t1.join();  t2.join();
        System.out.println(counter.getCount());
    }
}
