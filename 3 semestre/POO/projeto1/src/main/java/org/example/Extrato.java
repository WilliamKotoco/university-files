package org.example;

import java.util.ArrayList;

/**
 * Tipo extrato mostra as informações de todas as transferências, pix, saques e depósitos realizados em ordem.
 */
public class Extrato {
    private ArrayList<String> operacoes = new ArrayList<>();
    private ArrayList<Double> dinheiroEnvolvido = new ArrayList<Double>();


    /**
     * Adiciona a operação na lista de operações
     * @param operacao
     */
    public void setOperacoes(String operacao)
    {
        operacoes.add(operacao);
    }

    /**
     * Adiciona o dinheiro na lista de operações
     * @param money
     */
    public void setDinheiroEnvolvido(double money)
    {
        dinheiroEnvolvido.add(money);
    }

    /**
     * Mostra to.do histórico de gastos da conta.
     */
    public void displayExtrato()
    {
    for(int i =0; i < operacoes.size(); i++)
    {
        System.out.println(operacoes.get(i) + " " + dinheiroEnvolvido.get(i));
    }




    }



}
