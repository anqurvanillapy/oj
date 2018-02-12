/**
 *  Static Member Disorder
 *  ======================
 *
 *  Initialization of static members gets weird output due to disorder.
 */

import java.util.Calendar;

public class StaticMemberDisorder {
    private static final StaticMemberDisorder INSTANCE = new StaticMemberDisorder();

    private final int foo;
    // private final String foo;

    private static final int BAR = Calendar.getInstance().get(Calendar.YEAR);
    // Constants are prior.
    // private static final int BAR = 42;
    // private static final String BAR = "BAR";

    private StaticMemberDisorder() {
        foo = BAR;
    }

    // private String getFoo() {
    private int getFoo() {
        return foo;
    }

    public static void main(String[] args) {
        System.out.println(INSTANCE.getFoo());
        // Output: 0
    }
}
