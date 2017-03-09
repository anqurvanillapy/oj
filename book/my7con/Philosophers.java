/**
 *  Philosophers
 *  ============
 *
 *  > From ch2d1
 *
 *  Dining philosophers problem, but with the dead lock.
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

public class Philosophers {
    public static void main(String[] args) throws InterruptedException {
        Chopstick[] chops = new Chopstick[5];

        // 1. Dead lock.
        // Philosopher[] philos = new Philosopher[5];

        // 2. Solution that uses numbered chopsticks to pick up in some order.
        PhilosopherOrdered[] philos = new PhilosopherOrdered[5];

        for (int i = 0; i < 5; ++i) chops[i] = new Chopstick(i);

        for (int i = 0; i < 5; ++i) {
            // philos[i] = new Philosopher(chops[i], chops[(i + 1) % 5]);
            philos[i] = new PhilosopherOrdered(chops[i], chops[(i + 1) % 5]);
            philos[i].start();
        }

        for (int i = 0; i < 5; ++i) philos[i].join();
    }
}
