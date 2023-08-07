package org.example;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

/**
 * Tipo banco que serve como um caixa eletrônico, permitindo servindo como uma interface para realizar todas as operações chamando as respectivas classes
 */
public class Banco implements NotaFiscal{
    private int num;
    private String name;
    private String cnpj;
    private String endereco;
    private Conta contaLogada;
    private ArrayList<Agencia> agencias = new ArrayList<>();

    /**
     * Gets num.
     *
     * @return the num
     */
    public int getNum() {
        return num;
    }

    /**
     * Sets num.
     *
     * @param num the num
     */
    public void setNum(int num) {
        this.num = num;
    }

    /**
     * Gets name.
     *
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * Sets name.
     *
     * @param name the name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Gets cnpj.
     *
     * @return the cnpj
     */
    public String getCnpj() {
        return cnpj;
    }

    /**
     * Sets cnpj.
     *
     * @param cnpj the cnpj
     */
    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    /**
     * Gets endereco.
     *
     * @return the endereco
     */
    public String getEndereco() {
        return endereco;
    }

    /**
     * Sets endereco.
     *
     * @param endereco the endereco
     */
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    /**
     * Gets conta logada.
     *
     * @return the conta logada
     */
    public Conta getContaLogada() {
        return contaLogada;
    }

    /**
     * Sets conta logada.
     *
     * @param contaLogada the conta logada
     */
    public void setContaLogada(Conta contaLogada) {
        this.contaLogada = contaLogada;
    }

    /**
     * Gets agencias.
     *
     * @return the agencias
     */
    public ArrayList<Agencia> getAgencias() {
        return agencias;
    }

    /**
     * Sets agencias.
     *
     * @param agencias the agencias
     */
    public void setAgencias(ArrayList<Agencia> agencias) {

        this.agencias = agencias;
    }


    /**
     * Busca se existe um cliente e retorna o objeto para ser referenciado no campo contaLogada da classe Banco, permitindo realizar operações
     *
     * @param numAgencia número da agência
     * @param numConta   número da conta
     * @param password   senha da conta
     */
    public Conta logarCliente(int numAgencia, int numConta, int password) {
        Agencia agencia = buscarAgencia(numAgencia);
        if (agencia != null) {
            Conta conta = agencia.buscarConta(numConta, password);
            if (conta != null) {
                return conta;

            }

        }
        return null;
    }






    /**
     * Cadastra a conta do usuário e retorna verdadeiro ou falso, validando as informações mandadas. O número da conta é criado aleatoriamente para simular um ID real.
     * Além disso, guarda a conta no banco de dados para ter o acesso depois.
     * @param name       the name
     * @param address    the address
     * @param cpf        the cpf
     * @param password   the password
     * @param birthday   the birthday
     */
    public boolean cadastrarConta(int numAgencia, String name, String address, String cpf, int password, String birthday) throws IOException {
        FileWriter contaFile = new FileWriter("contas.txt");
        // Primeiro fazer as verificações principais, depois tentar reforçar caso dê tepmpo
        String split[] = birthday.split("/");
        char nameArray[] = name.toCharArray();
        int flag;
        Scanner input = new Scanner(System.in);
        if(Integer.parseInt(split[0]) > 31 || Integer.parseInt(split[1]) > 12 || Integer.parseInt(split[2]) > 2023 || Integer.parseInt(split[2]) < 1940 ) {
            System.out.println("Data de aniverśario inválida");
            return false;
        }
        if(password < 1000) {
            System.out.println("Senha muito pequena");
            return false;
        }
        if(cpf.length() < 11) // TODO: se dar tempo fazer uma verificação completa
        {
            System.out.println("cpf inválido!");
            return false;
        }
        for(char c : nameArray)
        {
            if(Character.isDigit(c))
            {
                System.out.println("Nome inválid!");
                return false;
            }
        }
        if (numAgencia > agencias.size()) {
            System.out.println("Agência inválida!");
            return false;
        }
        Random random = new Random();
        num = random.nextInt((99999-1000000) +1 + 1000000); // gera um número de 6 digitos
        while(agencias.get(numAgencia).verifyExistence(num))
        {
            num = random.nextInt((99999-1000000) +1 + 1000000); // gera um número de 6 digitos

        }

        System.out.println("Conta criada, guarde seu número: " + num);
        Conta conta = new Conta();
        conta.setName(name);
        conta.setAgencyNumber(numAgencia);
        conta.setBalance(0);
        conta.setCpf(cpf);
        conta.setAddress(address);
        conta.setNumber(num);
        conta.setPassword(0, password);
        conta.setBirthday(birthday);
        agencias.get(numAgencia).setContas(conta);
        String fileAppend = name + "#"+birthday+"#"+address+"#"+cpf+"#0" + numAgencia+"#"+num+"#"+password;
        contaFile.append(fileAppend);
        contaFile.close();
        conta = null;
        System.out.println("Digite 1 para continuar");
        flag = input.nextInt();
     return  true;
    }

    /**
     * Busca a agência atráves do código. Retorna nulo se não encontrar
     *
     * @param cod the cod
     * @return the agencia
     */
    public Agencia buscarAgencia(int cod) {
        for(Agencia agencia: agencias)
        {
            if(agencia.getCod() == cod)
                return agencia;
        }
        return null;


    }



    /**
     * Transferencia. Recebe o número da agência e o número da conta para realizar a transferência, tirando dinheiro da conta que mandou e adicionando na conta que vai receber.
     *Retorna verdadeiro ou falso, dependendo do sucesso da operação
     * @param numAgencia the num agencia
     * @param numConta   the num conta
     */
    public boolean transferencia(int numAgencia, int numConta) {
        double money;
        Scanner input = new Scanner(System.in);
        System.out.println("Digite o quanto se quer transferir: ");
        money = input.nextDouble();

        if(numAgencia > 4)
            return false;
        for (Conta contas : getAgencias().get(numAgencia).getContas()){
            if (contas.getNumber() == numConta)
            {
                if (contaLogada.sacar(money)) {
                    contas.depositar(money);
                    NotaFiscal.emitirNota(getAgencias().get(numAgencia).getName(), contas.getName(), money);
                    contaLogada.getExtrato().setOperacoes("Transferência bancária");
                    contaLogada.getExtrato().setDinheiroEnvolvido(money * -1);


                    return true;
                }
                else
                {
                    System.out.println("Dinheiro inválido");
                    return false;
                }

            }
        }
        System.out.println("Conta não encontrada");
        return false;
    }

    /**
     * Desloga a conta, adicionando a conta logada como nula
     */
    public void deslogar() {
        contaLogada = null;
    }

    /**
     * Busca determinado CPF dentro de todas as contas. Na vida real, para realizar o pix é necessário colocar somente a chave, deixando com que o sistema procure
     * entre todas as agências, sendo um n*n gigante
     *
     * @param cpf the cpf
     */
    public boolean pix(String cpf) {
        Scanner input = new Scanner(System.in);
        boolean achou = false;
        double money;

        if (cpf.length() < 11) {
            System.out.println("CPF INVÁLIDO, tente novamente");
            return false;
        }
        System.out.println("Digite a quantidade: ");
        money = input.nextDouble();
        if (contaLogada.sacar(money)) {
            // o código abaixo vai procurar a chave de pix em literal todas as contadas cadastradas
            for (Agencia agencia : getAgencias()) {
                for (Conta conta : agencia.getContas()) {
                    if (cpf.equals(conta.getCpf())) {
                        achou = true;
                        conta.depositar(money);
                        NotaFiscal.emitirNota(cpf, money);
                        contaLogada.getExtrato().setOperacoes("Pix");
                        contaLogada.getExtrato().setDinheiroEnvolvido(money * -1);
                        return true;
                    }
                }
            }
        }
        System.out.println("Quantia inválida");
        return false;


    }


}
