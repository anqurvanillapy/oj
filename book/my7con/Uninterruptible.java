/**
 *  Uninterruptible Dead Lock 
 *  =========================
 *
 *  An intentional implementation of a dead lock which is uninterruptible.
 */

public class Uninterruptible {
    public static void main(String[] args) throws InterruptedException {
        final Object res1 = new Object();
        final Object res2 = new Object();

        Thread t1 = new Thread() {
            public void run() {
                try {
                    // synchronized is a keyword, hence the whitespace :)
                    synchronized (res1) {
                        Thread.sleep(1000);
                        synchronized (res2) { /* nop */ }
                    }
                } catch (InterruptedException e) {
                    System.out.println("t1 interrupted");
                }
            }
        };

        Thread t2 = new Thread() {
            public void run() {
                try {
                    synchronized (res2) {
                        Thread.sleep(1000);
                        synchronized (res1) { /* nop */ }
                     }
                } catch (InterruptedException e) {
                    System.out.println("t2 interrupted");
                }
            }
        };

        t1.start(); t2.start();
        Thread.sleep(2000);
        t1.interrupt(); t1.interrupt();
        t1.join(); t2.join();
    }
}
