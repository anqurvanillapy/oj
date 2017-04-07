/**
 *  mStream
 *  =======
 *
 *  A simple demo of java.util.stream that illustrates something like
 *  MapReduce pattern. Stream is a slight functional feature in Java 8 that
 *  stores immutable data and guarantees one-time access to them like a
 *  normal pipeline.
 *
 *  The demo calculates the sum of a list of integers with even numbers
 *  filtered.
 */

import java.util.*;

public class mStream {
    public static void main(String[] args) {
        int sum;
        List<Integer> l;

        l = new ArrayList<Integer>(Arrays.asList(0, 1, 2, 3, 4, 5));
        sum = l.stream()
               .filter(i -> i % 2 == 0)
               .mapToInt(i -> i * i)
               .sum();

        System.out.println(sum);
    }
}
