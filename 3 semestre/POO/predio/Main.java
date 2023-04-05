import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        Scanner input = new Scanner(System.in);
        int andar, destino;

        Predio predio = new Predio(20);
        predio.setElevadores(predio.getQuantidadeAndares());

        Pessoa pessoa = new Pessoa();
        pessoa.setPredio(predio);


        for (int i = 0; i < 3; i++) {
            System.out.println("Digite o andar atual");
            andar = input.nextInt();
            pessoa.setAndarAtual(andar);
            System.out.println("Digite o andar de destino: ");
            destino = input.nextInt();
            pessoa.chamarElevador(destino);
        }



    }
}
