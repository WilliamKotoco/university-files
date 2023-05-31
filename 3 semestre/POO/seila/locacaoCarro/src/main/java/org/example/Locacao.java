package org.example;

import java.util.Date
public class Locacao {
private Carro carro;
private Cliente cliente;
private Date start, end;


public void displayInformation()
{
    long timeDifferenceSeconds = end.getTime() - start.getTime();
    int differenceInDays = (int) Math.floor(timeDifferenceSeconds/ 86_400_000);
    double price = carro.getPricePerDay() * differenceInDays;

}

}
