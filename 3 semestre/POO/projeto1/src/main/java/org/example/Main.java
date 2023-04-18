package org.example;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        File bancoFile = new File("/home/willao/Documentos/GitHub/Arquivos-Faculdade/3 semestre/POO/projeto1/src/main/java/org/example/banco.txt");
        File agenciaFile = new File("/home/willao/Documentos/GitHub/Arquivos-Faculdade/3 semestre/POO/projeto1/src/main/java/org/example/agencias.txt");
        File contasFile = new File("/home/willao/Documentos/GitHub/Arquivos-Faculdade/3 semestre/POO/projeto1/src/main/java/org/example/contas.txt");
        Scanner scanner = null;
        Banco banco = new Banco();
        scanner = new Scanner(bancoFile);
        Scanner scanner2 = new Scanner(agenciaFile);
        Scanner scanner3 = new Scanner(contasFile);
        ArrayList<Agencia> agencias = new ArrayList<>();
      //  List<Conta> contas = new LinkedList<>();


        while (scanner.hasNextLine()) {
            String linha = scanner.nextLine();
            String[] campos = linha.split("#");
            banco.setName(campos[0]);
            banco.setNum(Integer.parseInt(campos[1]));
            banco.setCnpj(campos[2]);
            banco.setEndereco(campos[3]);
            while (scanner2.hasNextLine()) {
                Agencia tmp = new Agencia();
                String linha2 = scanner2.nextLine();
                String[] campos2 = linha2.split("#");
                tmp.setName(campos2[0]);
                tmp.setCod(Integer.parseInt(campos2[1]));
                tmp.setEnderecos(campos2[2]);
                agencias.add(tmp);
            }
            banco.setAgencias(agencias);

        }
        while (scanner3.hasNextLine())
        {
            String linha3 = scanner3.nextLine();
            String[] campos3 = linha3.split("#");
            Conta conta = new Conta();
            conta.setName(campos3[0]);
            conta.setBirthday(campos3[1]);
            conta.setAddress(campos3[2]);
            conta.setCpf(campos3[3]);
            conta.setBalance(Double.parseDouble(campos3[4]));
            conta.setAgencyNumber(Integer.parseInt(campos3[5]));
            conta.setNumber(Integer.parseInt(campos3[6]));
            conta.setPassword(0, Integer.parseInt(campos3[7]));

            banco.getAgencias().get(conta.getAgencyNumber()).setContas(conta);


        }


        DisplayBanco displayBanco = new DisplayBanco(banco);
        displayBanco.login();
    }
}