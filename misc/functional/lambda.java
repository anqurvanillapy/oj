/**
 *  Lambda
 *  ======
 *
 *  Some various usages of lambda expression.
 */

import java.util.*;

public class lambda {
    public static void main(String[] args) {
        // Different definitions of lambda with a likewise implementation
        // of an anonymous class.
        Operator<Integer> add = (Integer a, Integer b) -> a + b;
        Operator<Integer> sub = (a, b) -> a - b;
        Operator<Integer> mul = (a, b) -> { return a * b; };
        Operator<Integer> div = new Operator<Integer>() {
            @Override
            public Integer operateBinary(Integer a, Integer b) {
                return a / b;
            }
        };

        List<Operator<Integer>> ol = new ArrayList<Operator<Integer>>();
        ol.add(add);
        ol.add(sub);
        ol.add(mul);
        ol.add(div);

        for (Operator<Integer> o : ol) {
            System.out.println(o.operateBinary(420, 42));
        }
    }

    interface Operator<T> {
        public T operateBinary(T a, T b);
    }
}
