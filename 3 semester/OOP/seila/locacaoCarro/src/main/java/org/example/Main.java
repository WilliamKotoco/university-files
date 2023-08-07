package org.example;

public class Main {
    public static void main(String[] args) {

        Carro carro = new Carro("Chevrolet Prisma", "DLH434", 240.0);
        Carro carro2 = new Carro("Cadillac Fleetwood", "HMF523", 1000.0);
        Carro carro3 = new Carro("Carrinho Do Leite", "CUM699", 30.6);

        Concecionaria concecionaria = new Concecionaria();
        concecionaria.getCarros().add(carro);
        concecionaria.getCarros().add(carro2);
        concecionaria.getCarros().add(carro3);

        Cliente cliente = new Cliente();
        cliente.setNome("Elis Estaoaqui martins");
        cliente.setCpf("253623626311");
        Cliente cliente2 = new Cliente();
        cliente2.setNome("Roubarão Meuque Jao");
        cliente2.setCpf("12345677080");





    }
}