/**
 *  Boolean Expression
 *  ==================
 *
 *  Interesting scenerios of the evaluation of boolean expressions. Perhaps
 *  it's a context of compile-time optimization.
 */

public class booleanExpr {
    public static void main(String[] args) {
        String s = null;

        // These two would not throw NullPointerException since s != null
        // guarantees the value of && expression is false, thus the next
        // factor would be skipped. The next is similar.
        System.out.println((s != null) && (s.length() > 0));
        System.out.println((s == null) || (s.length() == 0));

        // Operators & and | require both of the operands to be evaluated,
        // thus the following two would throw NullPointerException.
        // System.out.println((s != null) & (s.length() > 0));
        // System.out.println((s == null) | (s.length() == 0));
    }
}
