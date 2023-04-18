package org.example;

import java.lang.reflect.Array;
import java.util.LinkedList;
import java.util.List;

/**
 * Realiza operações de adminstração das contas, principalmente retornar se determinada conta pertence a essa agência.
 */
public class Agencia {
    private int cod;
    private String name;
    private String enderecos;
    private List<Conta> contas = new LinkedList<>();

    /**
     * Gets cod.
     *
     * @return the cod
     */
    public int getCod() {
        return cod;
    }

    /**
     * Sets cod.
     *
     * @param cod the cod
     */
    public void setCod(int cod) {
        this.cod = cod;
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
     * Gets enderecos.
     *
     * @return the enderecos
     */
    public String getEnderecos() {
        return enderecos;
    }

    /**
     * Sets enderecos.
     *
     * @param enderecos the enderecos
     */
    public void setEnderecos(String enderecos) {
        this.enderecos = enderecos;
    }

    /**
     * Gets contas.
     *
     * @return the contas
     */
    public List<Conta> getContas() {
        return contas;
    }

    public void setContas(Conta conta) {
        contas.add(conta);
    }

    /**
     * Cadastrar conta.
     *
     * @param conta the conta
     */


    /**
     * Busca a conta e retorna ela, caso não encontrar retorna nulo
     *
     * @param num      número da conta
     * @param Password senha
     * @return a conta ou nulo
     */
    public Conta buscarConta(int num, int Password) {
        for (Conta account : contas)
        {
            if(account.getNumber() == num)
            {
              if(account.getPassword() == Password)
                    return account;
            }
        }
        return null;
    }

    /**
     * Verifica se existe determinada conta dentro dessa agência em específico. É usado para operações dentro
     *
     * @param num número da conta
     * @return verdadeiro se existe, falso se não existe
     */
    public boolean verifyExistence(int num) {
        for (Conta account : contas) {
            if (account.getNumber() == num) {
                return true;
            }
        }
        return false;

    }

}
