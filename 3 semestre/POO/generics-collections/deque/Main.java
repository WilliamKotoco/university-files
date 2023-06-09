import java.util.Deque;
import java.util.LinkedList;
/**
 * It's an interface that extends the queue interface. It allows manipulating the 
 * last elements, so it can be used as a stack.
 */
public class Main
{
    private static Deque<String> stack = new LinkedList<>(); 
    public static void main(String[] args) {
        stack.addFirst("Element 1");
        stack.addFirst("Element 2");
        stack.addFirst("Element 3");
        // addFirst = push 
        System.out.println("Stack's top: " + stack.getFirst());
        // removeFirst = pop
        stack.removeFirst();
        System.out.println("Stack's top: " + stack.getFirst());

    }
}