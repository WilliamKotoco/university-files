public class Calculator {


    public double calcular(double a, double b, char operacao) throws  ArithmeticException, InvalidOperationException
    {
        switch(operacao)
        {
            case '+':
                return a +b;
            case '-':
                return a-b;
            case '/':
                    if(b == 0)
                        throw new ArithmeticException("Divisão por zero!");
                    return a/b;
            case '*':
                return a*b;
            default:
                throw  new InvalidOperationException("Operação inválida");

        }
    }

}
