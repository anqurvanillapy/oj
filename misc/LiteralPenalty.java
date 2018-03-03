/**
 *  Literal penalty
 *  ===============
 *
 *  Using larget amount of literals brings performance penalty.
 */

public class LiteralPenalty {
    public static void main(String[] args) {
        // String s = "";
        // for (int i = 0; i < 100000; ++i) {
        //     s += "foo";
        // }

        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < 100000; ++i) {
            sb.append("foo");
        }
    }
}
