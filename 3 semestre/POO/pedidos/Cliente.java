import java.util.ArrayList;
import java.util.Scanner;

public class Cliente {
    private String endereco;
    private String nome;
    double money;
    ArrayList<Pedido> pedidos = new ArrayList<>();

    public ArrayList<Pedido> getPedidos() {
        return pedidos;
    }

    public void setPedidos(ArrayList<Pedido> pedidos) {
        this.pedidos = pedidos;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(double money) {
        this.money = money;
    }

    public Pedido buyItem(Loja loja)
    {
        int op;
        Scanner input = new Scanner(System.in);
        Pedido pedido = new Pedido();
        pedido.setCliente(this);
        System.out.println("[1] pesquisar pelo nome \n [2] pesquisar pelo id?");
        op = input.nextInt();
        if(op == 1)
        {
            String name;
            System.out.println("Digite o nome: ");
            name = input.nextLine();
           pedido.setItem(loja.searchForItem(name));
        }
        else
        {
            int id;
            System.out.println("Digite o id: ");
            id = input.nextInt();
            pedido.setItem(loja.searchForItem(id));
        }
        pedido.setId(pedido.getQtdPedidos() + 1);
        pedido.setQtdPedidos(Pedido.getQtdPedidos() +1);
        pedidos.add(pedido);
        return pedido;

    }

}
