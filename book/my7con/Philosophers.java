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
 
 class Philosopher extends Thread {
    private Chopstick left, right;
    private Random random;

    public Philosopher(Chopstick left, right) {
        this.left = left;
        this.right = right;
        random = new Random();
    }

    public void run() {
        try {
            while (true) {
                Thread.sleep(random.nextInt(100));          // Think
                synchronized(left) {                        // Pick left
                    synchronized(right) {                   // Pick right
                        Thread.sleep(random.nextInt(100));  // Eat
                    }
                }
            }
        } catch (InterruptedException e) {}
    }
}

public class Philosophers {
    public static void main(String[] args) {
        Chopstick[] chopsticks = new Chopstick[5];

        for (int i = 0; i < 5; ++i) {
            // TODO
        }
    }
}
