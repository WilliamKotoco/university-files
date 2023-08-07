public class Main {
    public static void main(String[] args) {
    Calculator calculator = new Calculator();
    try{
        System.out.println(calculator.calcular(10, 20, '*'));
        System.out.println(calculator.calcular(10, 20, '+'));
    calculator.calcular(10, 0, '/');
    calculator.calcular(10,0,'s');
    }
    catch (ArithmeticException | InvalidOperationException e)
    {
        System.out.println(e.getMessage());
    }
    finally {
        System.out.println("Calculadora fechando");
    }
    }
}
