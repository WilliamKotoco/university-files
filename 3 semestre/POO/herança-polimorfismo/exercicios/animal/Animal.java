public abstract class  Animal
{
    protected String name;
    protected int numberOfPaws;


    public Animal(String name, int numberOfPaws)
    {
        this.name = name;
        this.numberOfPaws = numberOfPaws;
    }

    public abstract void emitirSom(); //deve ser reescrito pelas classes
}