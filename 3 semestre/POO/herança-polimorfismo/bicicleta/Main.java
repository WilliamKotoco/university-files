public class Main
{
    public static void main(String args[])
    {
        Bicicleta bike = new Bicicleta(10,20,30);
        BicicletaTurbinada bikeTurbinada = new BicicletaTurbinada(90,40,320,10);

//        BicicletaTurbinada bike2 = new Object();

        bike.displayInfo();
        System.out.println("");
        bikeTurbinada.displayInfo();
    }
}