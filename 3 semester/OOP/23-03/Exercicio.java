public class Exercicio
{

    // substituir object por number e ir vendo, prova que Boolean não herda de Number.
    public static void main(String[] args) {
        Integer intObj = Integer.valueOf(123);
        Long longObj = Long.valueOf(1234567890);
        Double doubleObj =  Double.valueOf(12.34);
        Boolean boolObj =  Boolean.valueOf(true);
        Object[] objArray = {intObj, longObj, doubleObj, boolObj};

        for (int i = 0; i < objArray.length; i++) {
            if (objArray[i] instanceof Object)
                System.out.println(objArray[i].toString()+ " é um object: ");
            else
                System.out.println(objArray[i] + " não é um object: ");
                                                 }
                                        }
}