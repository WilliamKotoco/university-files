public class Retangulo extends Forma
{
    protected double base;
    protected double altura;


        public Retangulo(double altura, double base)
        {
            this.base = base;
            this.altura = altura;
        }
    @Override
    public double area()
    {
        return base*altura;
    }

    @Override
    public double perimetro()
    {
        return 2*(base+altura);
    }

    
}