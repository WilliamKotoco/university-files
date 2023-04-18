package org.example;

import java.sql.SQLOutput;

/**
 * Interface nota fiscal, que mostra uma nota fiscal para as operações de pix e transferência.
 */

public interface NotaFiscal {

    /**
     * Emite a nota fiscal de um pix, mostrando pra quem foi enviado e a quantia.
     * @param cpf
     * @param money
     */
    static void emitirNota(String cpf, double money)
    {
        System.out.println("------------ NOTA FISCAL ------------ ");
        System.out.println("PIX");
        System.out.println("ENVIADO PARA CHAVE: " + cpf);
        System.out.println("QUANTIA: " + money);
        System.out.println("------------------------");

    }

    /**
     * Emite a nota fiscal de uma transferência bancária, mostrando para qual agência foi enviada, quem recebeu e a quantia.
     * @param agencyName
     * @param accoutName
     * @param money
     */
    static void emitirNota(String agencyName, String accoutName, double money)
    {
        System.out.println("------------ NOTA FISCAL ------------ ");
        System.out.println("Transferência");
        System.out.println("ENVIADO PARA A AGÊNCIA: " + agencyName);
        System.out.println("ENVIADO PARA CONTA: " + accoutName);
        System.out.println("QUANTIA: " + money);
        System.out.println("------------------------");
    }


}
