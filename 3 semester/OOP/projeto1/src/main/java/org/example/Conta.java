package org.example;

import javax.naming.InvalidNameException;

/**
 * Realiza operaçóes que tangem ao nível individual da conta, como depósito, saque e atualizações
 */
public class Conta {
    private int number;



    private int agencyNumber;
    private double  balance;
    private String name;
    private String address;
    private String cpf;
    private String birthday;
    private int password;

   private Extrato extrato;

    /**
     * Gets extrato
     * @return retorna a instância do extrato da conta
     */
    public Extrato getExtrato()
    {
        return this.extrato;
    }

    /**
     * sets Extrato
     * @param extrato
     */
    public void setExtrato(Extrato extrato)
    {
        this.extrato = extrato;
    }


    /**
     * gets the agencyNumber
     * @return
     */
    public int getAgencyNumber() {
        return agencyNumber;
    }

    /**
     * sets the agencyNumber
     * @param agencyNumber
     */
    public void setAgencyNumber(int agencyNumber) {
        this.agencyNumber = agencyNumber;
    }
    /**
     * Gets number.
     *
     * @return the number
     */

    public int getNumber() {
        return number;
    }

    /**
     * Sets number.
     *
     * @param number the number
     */
    public void setNumber(int number) {
        this.number = number;
    }

    /**
     * Gets balance.
     *
     * @return the balance
     */
    public double getBalance() {
        return balance;
    }

    /**
     * Sets balance.
     *
     * @param balance the balance
     */
    public void setBalance(double balance) {
        this.balance = balance;
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
     * Gets address.
     *
     * @return the address
     */
    public String getAddress() {
        return address;
    }

    /**
     * Sets address.
     *
     * @param address the address
     */
    public void setAddress(String address) {
        this.address = address;
    }

    /**
     * Gets cpf.
     *
     * @return the cpf
     */
    public String getCpf() {
        return cpf;
    }

    /**
     * Sets cpf.
     *
     * @param cpf the cpf
     */
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    /**
     * Gets birthday.
     *
     * @return the birthday
     */
    public String getBirthday() {
        return birthday;
    }

    /**
     * Sets birthday.
     *
     * @param birthday the birthday
     */
    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    /**
     * Gets password.
     *
     * @return the password
     */
    public int getPassword() {
        return password;
    }

    /**
     * Verifica se o usuário sabe a senha antiga e se a nova senha é válida
     *
     * @param oldPassword the old password
     * @param newPassword the new password
     */
    public void setPassword(int oldPassword, int newPassword) {
        if (oldPassword == this.password)
        {
            if(passwdValidation(newPassword))
                this.password = newPassword;
        }
    }

    /**
     * Deposita um dinheiro na conta.
     *
     * @param money the money
     */
    public void depositar(double money)
    {

        setBalance(money + getBalance());

    }

    /**
     *
     * Faz as verificações necessárias para sacar o dinheiro, como se é quantia suficiente e tratamento de tipo númerioo.
     * Retorna true se foi possível sacar
     * @param money the money
     */
    public boolean sacar(double money)
    {
        if (money > 0 && money <= this.getBalance())
        {
            setBalance(this.balance - money);
            return true;
        }
        return false;
    }

    /**
     * Valida a senha, impede de ser menor que 4 caracteres (insegura).
     *
     * @param password the password
     * @return the boolean
     */
    public boolean passwdValidation(int password)
    {
       if (password < 1000)
            return false;
               return true;
    }




}
