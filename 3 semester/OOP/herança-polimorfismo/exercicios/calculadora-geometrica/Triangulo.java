/*
 *  Triângulo é uma espécie de Retângulo
 */
public class Triangulo extends Retangulo
{
    private double lado1,lado2;

    public Triangulo(double altura, double base,  double lado1, double lado2)
    {
        super(base, altura);
        this.lado1 = lado1;
        this.lado2 = lado2;
    }

    @Override
    public double area()
    {
        return (base*altura)/2;
    }

    @Override
    public double perimetro()
    {
        return base +lado1 + lado2;
    }
}
