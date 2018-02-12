public class VarArgs {
    private static void varPrint(String... strs) {
        for (String s : strs) {
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        varPrint("foo", "bar", "baz");
    }
}
