/**
 *  Philosophers
 *  ============
 *
 *  > From ch2d1
 *
 *  Dining philosophers problem.
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
