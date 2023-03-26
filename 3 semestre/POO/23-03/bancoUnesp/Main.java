import java.util.Scanner;
public class   Main
{
    public static void main(String[] args) {
        Conta conta1 = new Conta();
        Conta conta2 = new Conta();

        preencherConta(conta1);

        System.out.println("Conta " + conta1.getName() + "tem " + conta1.getMoney());
        conta1.deposito(30);
        System.out.println("Depois do depósito tem: " + conta1.getMoney());

        preencherConta(conta2);

        System.out.println("Conta " + conta2.getName() + "tem " + conta2.getMoney());
        conta2.saque(30);
        System.out.println("Depois do saque tem: " + conta2.getMoney());
    }

    public static void preencherConta(Conta conta)
    {
        String name, agencyName;
        long cpf;
        double money;
        int id, agencyNumber;
        conta.setAccountNumbers(Conta.getAccountNumbers() + 1);
        Agencia agencia = new Agencia();
        conta.setId(Conta.getAccountNumbers());
        Scanner input = new Scanner(System.in);
        System.out.println("Digite o nome do dono da conta: ");
        name = input.nextLine();
        conta.setName(name);
        System.out.println("Digite o cpf da conta");
        cpf = input.nextLong();
        conta.setCPF(cpf);
        System.out.println("Digite o dinheiro inicial da conta");
        money = input.nextDouble();
        conta.setMoney(money);
        System.out.println("Preenchendo dados da agência: ");
        System.out.println("Nome da agência: ");
        agencyName = input.nextLine();
        agencia.setNome(agencyName);
        System.out.println("Digite o número da agencia");
        agencyNumber = input.nextInt();
        agencia.setNumber(agencyNumber);


        conta.setAgencia(agencia);


    }
}