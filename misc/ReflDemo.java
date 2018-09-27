/**
 *  Reflection
 *  ==========
 *
 *  Use java.lang.reflec to create generic getters/setters and retrieve getters/
 *  setters from a class.  Note that it is just a bad practice due to the
 *  tradeoff of no compile-time checking.
 */

import java.lang.reflect.Method;
import java.lang.reflect.Field;

public class ReflDemo {
    public static void main(String[] args) {
        Foo foo = new Foo("foo", 42);

        System.out.println(foo.callGetter("a"));
        System.out.println(foo.callGetter("b"));

        foo.callSetter("a", "bar");
        foo.callSetter("b", 69);

        System.out.println(foo.callGetter("a"));
        System.out.println(foo.callGetter("b"));

        listGettersAndSetters(foo.getClass());
    }

    @SuppressWarnings("rawtypes")
    static void listGettersAndSetters(Class clazz) {
        Method[] methods = clazz.getMethods();

        // Only works for public ones.
        for (Method method : methods) {
            if (isGetter(method))
                System.out.println("getter: " + method);
            if (isSetter(method))
                System.out.println("setter: " + method);
        }
    }

    static boolean isGetter(Method method) {
        if (!method.getName().startsWith("get"))
            return false;
        if (method.getParameterTypes().length != 0)
            return false;
        if (void.class.equals(method.getReturnType()))
            return false;
        return true;
    }

    static boolean isSetter(Method method) {
        if (!method.getName().startsWith("set"))
            return false;
        if (method.getParameterTypes().length != 1)
            return false;
        return true;
    }
}

class Foo {
    private String a;
    private int b;

    public Foo(String a, int b) {
        this.a = a;
        this.b = b;
    }

    public String getA() {
        return this.a;
    }

    public void setA(String a) {
        this.a = a;
    }

    public Object callGetter(String name) {
        Object ret = null;

        try {
            Field field = getClass().getDeclaredField(name);
            field.setAccessible(true);

            ret = field.get(this);

            field.setAccessible(false);
        } catch (NoSuchFieldException | IllegalAccessException e) {
            e.printStackTrace();
        }

        return ret;
    }

    public void callSetter(String name, Object value) {
        try {
            Field field = getClass().getDeclaredField(name);
            field.setAccessible(true);

            if (value instanceof String)
            field.set(this, (String) value);
            else if (value instanceof Integer)
            field.set(this, (Integer) value);

            field.setAccessible(false);
        } catch (NoSuchFieldException | IllegalAccessException e) {
            /* nop */
        }
    }
}
