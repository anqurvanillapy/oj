/**
 *  Philosopher
 *  ===========
 *
 *  Running thread of the philosopher, in the dining philosophers problem.
 */

import java.util.*;

public class Philosopher extends Thread {
    private Chopstick left, right;
    private Random random;

    public Philosopher(Chopstick left, Chopstick right) {
        this.left = left;
        this.right = right;
        random = new Random();
    }

    public void run() {
        try {
            while (true) {
                System.out.println(this + " thinking...");
                Thread.sleep(random.nextInt(1000));

                System.out.println(this + " picks left");
                synchronized(left) {
                    System.out.println(this + " picks right");
                    synchronized(right) {
                        System.out.println(this + " eating...");
                        Thread.sleep(random.nextInt(1000));
                    }
                }
            }
        } catch (InterruptedException e) { /* nop */ }
    }
}
