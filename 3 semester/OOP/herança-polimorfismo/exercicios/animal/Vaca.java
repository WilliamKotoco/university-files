public class Vaca extends Animal
{

    public Vaca(String name, int numberOfPaws)
    {
        super(name, numberOfPaws);
    }
    @Override
    public void emitirSom()
    {
        System.out.printf(" MUUUUUUUUUUU");
    }
}