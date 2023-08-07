public class Main
{
    public static void main(String[] args) {
        Circulo circ = new Circulo(30);
        Triangulo triangulo = new Triangulo(3,4,5,3);
        Retangulo ret = new Retangulo(4,6);

        System.out.println("O círculo tem area " + circ.area() + 
        " e tem perimetro " + circ.perimetro());

        System.out.println("O retangulo tem area " + ret.area() + 
        " e tem perimetro " + ret.perimetro());

        
        System.out.println("O triangulo tem area " + triangulo.area() + 
        " e tem perimetro " + triangulo.perimetro());

    }
}