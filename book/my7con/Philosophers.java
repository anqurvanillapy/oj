/**
 *  Philosophers
 *  ============
 *
 *  > From ch2d1
 *
 *  Dining philosophers problem.
 *
 *  XXX TODO:
 *  XXX
 *  XXX There are about 4 solutions to this problem, which need to be discussed
 *  XXX and implemented here.
 *  XXX
 *  XXX 1.  At most 4 philosophers are required to pick up the left chopstick
 *  XXX     simultaneously.
 *  XXX 2.  Use AND semaphore.
 *  XXX 3.  Odd-numbered philosophers pick up the left chopstick first, and
 *  XXX     even-numbered thinkers grab the right one first.
 *  XXX 4.  Number each chopstick. The first picked chopstick should be greater
 *  XXX     (less) than the second one.
 */

import java.util.*;

class Chopstick {
    private int id;
    public Chopstick(int id) { this.id = id; }
    public int getId() { return id; }
}
 
class Philosopher extends Thread {
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

public class Philosophers {
    public static void main(String[] args) throws InterruptedException {
        Chopstick[] chops = new Chopstick[5];
        Philosopher[] philos = new Philosopher[5];

        for (int i = 0; i < 5; ++i) chops[i] = new Chopstick(i);

        for (int i = 0; i < 5; ++i) {
            philos[i] = new Philosopher(chops[i], chops[(i + 1) % 5]);
            philos[i].start();
        }

        for (int i = 0; i < 5; ++i) philos[i].join();
    }
}
