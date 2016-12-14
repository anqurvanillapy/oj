/**
 *  MemMystery
 *  ==========
 *
 *  > From ch2d1
 *
 *  An example of memory visibility with race conditions.
 */

public class MemMystery {
    static boolean ready = false;
    static int answer = 0;

    static Thread tSetAnswer = new Thread() {
        public void run() {
            answer = 42;
            ready = true;
        }
    };

    static Thread tGetAnswer = new Thread() {
        public void run() {
            if (ready) {
                System.out.println("The answer of life: " + answer);
            } else {
                System.out.println("The answer is unknown.");
            }
        }
    };

    public static void main(String[] args) throws InterruptedException {
        tSetAnswer.start(); tGetAnswer.start();
        tSetAnswer.join();  tGetAnswer.join();
        // "The answer of life: 0" would possibly be displayed. The execution of
        // the thread tSetAnswer could be out of order.
    }
}
