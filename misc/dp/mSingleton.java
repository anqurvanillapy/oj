/**
 *  mSingleton
 *  ==========
 *
 *  A singleton pattern implemented in Java, using lazy initialization with
 *  double-checked locking.
 */

public class mSingleton {
    public static void main(String[] args) {
        System.out.println(Cargo.getInstance());
        System.out.println(Cargo.getInstance());
    }
}

class Cargo {
    // Note that keyword `volatile' is totally different from ISO C++, but
    // Microsoft C/C++ is similar to Java's, which strictly constrains the
    // synchronizations on main memory and doesn't allow CPUs to manipulate
    // the data on their caches. `volatile' is entirely in the context of
    // multithreading.
    private static volatile Cargo instance = null;

    private Cargo() { System.out.println("Freedom!"); }

    public static Cargo getInstance() {
        if (instance == null) {
            // Place a mutex lock.
            synchronized(Cargo.class) {
                if (instance == null) {
                    instance = new Cargo();
                }
            }
        }

        return instance;
    }
}
