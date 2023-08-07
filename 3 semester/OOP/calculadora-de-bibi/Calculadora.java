public interface Calculadora {

    public static int somar(int a, int b)
    {return a+b;
    }
    public static double somar(double a, double b)
    {
        return a+b;
    }


    public static int subtrair(int a, int b)
    {return a-b;
    }
    public static double subtrair(double a, double b)
    {
        return a-b;
    }

    public static String subtrair(String a, String b)
    {

        return Double.toString(Double.parseDouble(a) - Double.parseDouble(b));
    }

    public static int multiplicar(int a, int b)
    {return a*b;
    }
    public static double multiplicar(double a, double b)
    {
        return a*b;
    }

    public static String multiplicar(String a, String b)
    {

        return Double.toString(Double.parseDouble(a) * Double.parseDouble(b));
    }


    public static int dividir(int a, int b)
    {
        if (b == 0)
        {
            System.out.println("Número inválido");
            return 0;
        }
        return (a/b);
    }
    public static double dividir(double a, double b)
    {
        if (b == 0)
        {
            System.out.println("Número inválido");
            return 0;
        }
        return (a/b);
    }

    public static String dividir(String a, String b)
    {
    double n1 = Double.parseDouble(a);
    double n2 = Double.parseDouble(b);
    if (n2 == 0 )
    {
        return "Número inválido!";
    }
    return Double.toString(n1/n2);
    }



}
