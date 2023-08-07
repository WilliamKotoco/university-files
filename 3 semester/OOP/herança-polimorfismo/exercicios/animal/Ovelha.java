public class Ovelha extends Animal
{

    public Ovelha(String name, int numberOfPaws)
    {
        super(name, numberOfPaws);
    }

    /*
     * Reescrevendo o emitir som, que é abstardo na superclasse.
     */
    @Override
    public void emitirSom()
    {
        System.out.printf(" MÉÉÉÉÉ");
    }
}