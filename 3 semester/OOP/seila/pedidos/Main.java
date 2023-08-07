public class Main {
    public static void main(String[] args)
    {
        Loja loja = new Loja();
        Item item = new Item("Mesa", 1, 500, 60);
        Item item2 = new Item("Trambolho", 2, 5600, 5.3);
        Item item3 = new Item("Caderno", 3, 34, 1.7);
        Item item4 = new Item("Trambolhinho", 4, 4000, 1);
        Pedido pedido = new Pedido();
        loja.getItens().add(item);
        loja.getItens().add(item2);
        loja.getItens().add(item3);
        loja.getItens().add(item4);


        Cliente cliente = new Cliente();
        cliente.setEndereco("Rua Teste do Testinho");
        cliente.setNome("Elis Istão Nosab Duzindo Da Silva");
        cliente.setMoney(3294);
      pedido = cliente.buyItem(loja);
      pedido.displayInformation();


    }

}
