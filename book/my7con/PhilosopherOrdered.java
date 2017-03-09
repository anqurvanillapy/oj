/**
 *  PhilosopherOrdered
 *  ==================
 *
 *  A solution to the dining philosophers problem that uses the numbered
 *  chopsticks to pick up them in some order, avoiding the dead lock.
 */

import java.util.*;

public class PhilosopherOrdered extends Thread {
    private Chopstick first, second;
    private Random random;

    public PhilosopherOrdered(Chopstick left, Chopstick right) {
        if (left.getId() < right.getId()) {
            first = left;
            second = right;
        } else {
            first = right;
            second = left;
        }
        random = new Random();
    }

    public void run() {
        try {
            while (true) {
                System.out.println(this + " thinking...");
                Thread.sleep(random.nextInt(1000));

                System.out.println(this + " picks left");
                synchronized(first) {
                    System.out.println(this + " picks right");
                    synchronized(second) {
                        System.out.println(this + " eating...");
                        Thread.sleep(random.nextInt(1000));
                    }
                }
            }
        } catch (InterruptedException e) { /* nop */ }
    }
}
