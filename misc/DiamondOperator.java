/**
 *  Diamond Operator
 *  ================
 *
 *  Type parameters ignored for sufficiently-close context implications.
 */

public class DiamondOperator {
    public static void main(String[] args) {
        Pair<String, Integer> kv = new Pair<>("foo", 42);
        System.out.println(kv);
    }
}

class Pair<FirstType, SecondType> {
    private final FirstType first;
    private final SecondType second;

    public Pair(FirstType first, SecondType second) {
        this.first = first;
        this.second = second;
    }

    public String toString() {
        return "(" + first + ", " + second + ")";
    }
}
