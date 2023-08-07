public class Bicicleta
{
    private double velocity;
    private int marcha;
    private int cadencia;


    public Bicicleta(double velocity, int marcha, int cadencia)
    {
        this.velocity = velocity;
        this.marcha = marcha;
        this.cadencia = cadencia;
    }
    public void displayInfo()
    {
        System.out.println("Velocidade: " + velocity);
        System.out.println("Marcha: " + marcha);
        System.out.println("Cadencia: " + cadencia);
    }
}