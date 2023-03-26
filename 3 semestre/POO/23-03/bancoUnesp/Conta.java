public class Conta
{

    static int accountNumbers;
    String name;
    long CPF;
    int id;

    double money;
    Agencia agencia;



    public static void setAccountNumbers(int accountNumbers) {
        Conta.accountNumbers = accountNumbers;
    }

    public static int getAccountNumbers() {return accountNumbers;}
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getCPF() {
        return CPF;
    }

    public void setCPF(long CPF) {
        this.CPF = CPF;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(double money) {
        this.money = money;
    }

    public Agencia getAgencia() {
        return agencia;
    }

    public void setAgencia(Agencia agencia) {
        this.agencia = agencia;
    }

    public void deposito(double money)
    {
        if (money > 0)
            this.money += money;
        else
            System.out.println("Quantia inválida! ");
    }

    public void saque(double money)
    {
        if (money > 0)
            this.money = this.money - money;
        else
            System.out.println("Quantia inválida! ");
    }
}
