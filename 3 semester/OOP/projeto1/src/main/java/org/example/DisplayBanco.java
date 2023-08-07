package org.example;
import java.io.IOException;
import java.util.Scanner;

/**
 * O display banco vai ser a tela que conecta aos métodos da classe banco, que por sua vez servem como intermediário para realizar as operações principais.
 */
public class DisplayBanco  {

    /**
     * The Meu banco.
     */
    Banco meuBanco;


    /**
     * Realiza o login da conta, dando a opção de criar uma conta nova caso não tenha ou tentar novamente caso tenha errado alguma informação.
     *
     * @throws IOException the io exception
     */
    public void login() throws IOException {
        Scanner input = new Scanner(System.in);
        int agencyNumber;
        int accountNumber;
        int password;
        int flag;
        System.out.println("Olá, seja bem vindo ao  " +  meuBanco.getName());
        System.out.println("Digite o número da agência");
        agencyNumber = input.nextInt();
        System.out.println("Digite o número da conta: ");
        accountNumber = input.nextInt();
        System.out.println("Digite a senha: ");
        password = input.nextInt();
        Conta conta= new Conta();
        conta = meuBanco.logarCliente(agencyNumber, accountNumber, password);
        Extrato extrato = new Extrato();
        if (conta != null)
        {
            meuBanco.setContaLogada(conta);
            meuBanco.getContaLogada().setExtrato(extrato);
            conta = null;
            telaUsuario();
        }
        else
        {
            System.out.println("Não foi encontrada a conta. Verifique se digitou certo as credenciais. Caso não tenha uma conta, digite 1 para cadastrar ou 2 para tentar novamente");
            flag = input.nextInt();
            if(flag == 1)
            {
                cadastrar();
            }
            else
            {
                login();
            }
        }
    }

    /**
     * Construtor único, não pode existir um display banco sem ter um banco pronto.
     *
     * @param meuBanco the meu banco
     */
    public DisplayBanco(Banco meuBanco) {
        this.meuBanco = meuBanco;
    }

    /**
     * Cadastra uma conta nova
     *
     * @throws IOException the io exception
     */
    public void cadastrar() throws IOException {
        Scanner input = new Scanner(System.in);
         int agencyNumber;
         String name;
         String address;
         String cpf;
         String birthday;
         int password;
        System.out.println("Digite seu nome completo: ");
        name = input.nextLine();
        System.out.println("Digite seu cpf : ");
        cpf = input.nextLine();
        System.out.println("Digite a data de nascimento, no formato: XX/XX/XXXX");
        birthday = input.nextLine();
        System.out.println("Digite o endereço completo: ");
        address = input.nextLine();
        System.out.println("Digite o número da agência no qual se quer cadastrar");
        for(Agencia agencia : meuBanco.getAgencias())
        {
            System.out.println(agencia.getCod() + " " + agencia.getName());
        }
        agencyNumber = input.nextInt();
        System.out.println("Digite sua senha, com NO MÍNIMO 4 NÚMEROS");
        password = input.nextInt();

       boolean result =  meuBanco.cadastrarConta(agencyNumber, name, address, cpf, password, birthday);
       if (result == true)
           telaUsuario();
       else
           cadastrar();

    }

    /**
     * Chama as funcionalidades de consultar saldo, depósito, saque, transferência, pix e a opção de sair. Os métodos privados servem como intermediário para chamar os método da classe banco
     */
    public void telaUsuario() throws IOException {
        Scanner input = new Scanner(System.in);
        int op;
        System.out.println("Olá, " + meuBanco.getContaLogada().getName()+ " ,seja bem vindo! Digite o número da sua opção");
        System.out.println("1 - Consultar saldo");
        System.out.println("2 - Depósito");
        System.out.println("3 - Saque");
        System.out.println("4 - Transferência");
        System.out.println("5 - Pix");
        System.out.println("6 - Mostrar histórico de operações" );
        System.out.println("7- Sair");
        op = input.nextInt();
        switch(op)
        {
            case 1:
                consultarSaldo();
                break;
            case 2:
                deposito();
                break;
            case 3:
                saque();
                break;
            case 4:
                transferencia();
                break;
            case 5:
                pix();
                break;
            case 6:
                displayExtrato();
                break;
            case 7:
                sair();
                break;
        }
    }

    /**
     *  Interface para consultar o saldo. Não precisa passar pela interface do banco por ser um método que não exige operações complexas. Ao final, volta para a tela usuário
     * @throws IOException
     */
    private void consultarSaldo() throws IOException {
        Scanner input = new Scanner(System.in);
        int pausa;
        System.out.println("R$"+meuBanco.getContaLogada().getBalance());
        System.out.println("Digita 1 para continuar");
        pausa = input.nextInt();
        telaUsuario();
    }

    /**
     * Interface para realizar um depósito na conta. Recebe o dinheiro, faz uma validação básica e deposita diretamente na conta logada.
     * @throws IOException
     */
    private void deposito() throws IOException {
    Scanner input = new Scanner(System.in);
    double money;
    int pausa;
    System.out.println("Quantos reais deseja depositar ?");
    money = input.nextDouble();
    if (money > 0 ) {
        meuBanco.getContaLogada().depositar(money);
        System.out.println("Depósito realizado com sucesso");
        System.out.println("Digite 1 para continuar");
        pausa = input.nextInt();
        meuBanco.getContaLogada().getExtrato().setOperacoes("Depósito");
        meuBanco.getContaLogada().getExtrato().setDinheiroEnvolvido(money);




        telaUsuario();
    }
    else
    {
        System.out.println("Quantia inválida, tente novamente");


        deposito();
    }
    }

    /**
     * Interface intermediária para realizar um saque da conta. Recebe as informações e chama diretamente o método sacar da classe Conta, que está na instância contalogada.
     * Também mostra inválido caso não seja possível realizar o saque.
     * @throws IOException
     */
    private void saque() throws IOException {
        double money;
        int pausa;
        Scanner input = new Scanner(System.in);
        System.out.println("Digite a quantidade de dinheiro ");
        money = input.nextDouble();
       if  (meuBanco.getContaLogada().sacar(money))
       {
           System.out.println("Saque realizado com sucesso. DIgite 1 para continuar");
           pausa = input.nextInt();
           meuBanco.getContaLogada().getExtrato().setOperacoes("Saque");
           meuBanco.getContaLogada().getExtrato().setDinheiroEnvolvido(money * -1);

           telaUsuario();
       }
       else {
           System.out.println("Quantia inválida, tente novamente. Seu saldo é de  " + meuBanco.getContaLogada().getBalance());


           saque();
       }


    }

    /**
     * Interface para realizar a transferência bancária. Pede ao usuário as informações e chama o método de realizar transferência dentro do banco. Mostra se houve sucesso ou não
     * na transferência.
     * @throws IOException
     */
    private void transferencia() throws IOException {
        int pausa, agencyNumber, accountNumber;

        Scanner input = new Scanner(System.in);
        System.out.println("Digite o código da agência que se deseja realizar a transferência: ");
        for(Agencia agencia : meuBanco.getAgencias())
        {
            System.out.println(agencia.getCod() + " " + agencia.getName());
        }
        agencyNumber = input.nextInt();
        System.out.println("Digite o número da conta: ");
        accountNumber = input.nextInt();

        if(meuBanco.transferencia(agencyNumber, accountNumber))
        {
            System.out.println("Transferência realizado com sucesso");
            System.out.println("Digite 1 para continuar");
            pausa = input.nextInt();


            telaUsuario();
        }
        else
        {
            System.out.println("Algo deu errado, tente novamente");


            transferencia();
        }
    }

    /**
     * Pega as informações para realizar o pix, chama o metodo dentro do banco para realizar o pix e retorna se houve sucesso ou não
     * @throws IOException
     */
    private void pix() throws IOException {
        int pause;
        Scanner input = new Scanner(System.in);
        
        String cpf;
        System.out.println("Digite o CPF da conta que deseja transferir : ");
        cpf = input.nextLine();
        if(meuBanco.pix(cpf))
        {

            System.out.println("Pix realizado com sucesso, digite 1 para continuar");
            pause = input.nextInt();

             telaUsuario();
        }
        else
        {
            System.out.println("Algo deu errado, tente novamente");

            pix();
        }

    }

    /**
     * Sai da conta logada, permitindo que outro usuário possa usar o sistema.
     * @throws IOException
     */
    private void sair() throws IOException {
        meuBanco.deslogar();
        login();
    }

    private void displayExtrato() throws IOException {
        Scanner input = new Scanner(System.in);
        int pausaa;
        meuBanco.getContaLogada().getExtrato().displayExtrato();
        System.out.println("Digite 1 para continuar");
        pausaa = input.nextInt();
        telaUsuario();

    }
}
/*

 */