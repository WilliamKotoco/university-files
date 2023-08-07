public class BicicletaTurbinada extends Bicicleta
{
    // além de ter todos os campos da super (classe Bicicleta), tem:
    private double speedup;

    public BicicletaTurbinada(double velocity, int marcha, int cadencia, double speedup)
    {
        super(velocity, marcha, cadencia); // chama o construtor do super para preencher as info
        this.speedup = speedup;
    }

    @Override
    public void displayInfo()
    {
        super.displayInfo();
        System.out.println("O turbo aumenta a velocidade em " + speedup);
    }
}