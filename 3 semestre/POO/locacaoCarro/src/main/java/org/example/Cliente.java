package org.example;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class Cliente {
    String nome;
    String cpf;

    ArrayList<Locacao> locacaos = new ArrayList<>();

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public ArrayList<Locacao> getLocacaos() {
        return locacaos;
    }

    public void setLocacaos(ArrayList<Locacao> locacaos) {
        this.locacaos = locacaos;
    }

    public Locacao rentACar(Concecionaria concecionaria)
    {
        Locacao locacao = new Locacao();
        Scanner input = new Scanner(System.in);
        String name;
        System.out.println("Digite o nome do carro que deseja buscar");
        name = input.nextLine();
        Carro carro = concecionaria.searchForCar(name);
        Date today = new Date();
        today.setTime(LocalTime.now());




    }
}
