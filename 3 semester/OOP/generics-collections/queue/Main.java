import java.util.Queue;
import java.util.LinkedList;
public class Main
{
    private  static Queue<Integer> queue;
    public static void main(String[] args) {
        /*
         * Queue is an interface. It's implemented in a LinkedList
         */
        queue = new LinkedList<>();
        queue.add(10);
        queue.add(324);
        queue.add(303);
        for (Integer value : queue)
        {
            System.out.println(value);  
        }

        System.out.println("First element: " +  queue.peek()); // retrives the first element
        queue.remove(); // remove the first element 
        System.out.println("First element: " +  queue.peek()); // retrives the first element

        

        
    }
}