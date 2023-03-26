public class TesteMain
{
    public static void main(String[] args) {
        Teste obj1 = new Teste(10,20);
        obj1.move(obj1, 10, 20);
        
        System.out.printf("Teste: %d %d", obj1.x, obj1.y);
    }
}