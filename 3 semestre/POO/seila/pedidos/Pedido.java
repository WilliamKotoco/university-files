public class Pedido {
    private Item item;
    private Cliente cliente;
    private int id; // id do pedido, único.
    private static int qtdPedidos;

    public static int getQtdPedidos() {
        return qtdPedidos;
    }

    public static void setQtdPedidos(int qtdPedidos) {
        Pedido.qtdPedidos = qtdPedidos;
    }

    public Item getItem() {
        return item;
    }

    public void setItem(Item item) {
        this.item = item;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void displayInformation()
    {
        System.out.println("Código do pedido: "+ this.getId());
        System.out.println("Cliente: " + getCliente().getNome());
        System.out.println("Endereço de entrega: " + getCliente().getEndereco());
        System.out.println("Item: " + getItem().getName());
        System.out.println("Preco: " + getItem().getPreco());

    }

}
