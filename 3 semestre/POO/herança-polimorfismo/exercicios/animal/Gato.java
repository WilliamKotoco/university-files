public class Gato extends Animal
{


    public Gato(String name, int numberOfPaws)
    {
        super(name, numberOfPaws);
    }

    @Override
    public void emitirSom()
    {
        System.out.printf(" MIAU");
    }
}