
public class Circulo extends Forma  {

  private double raio;


  public Circulo(double raio) {
    this.raio = raio;
  }

  public double getRaio()
  {
    return raio;
  }

    @Override
  public double area() {
    return 3.14159 * raio * raio;
  }
  @Override
  public double perimetro() {
    return 3.14159 * raio * 2;
  }
}
