package org.example;

import java.util.ArrayList;

public class Concecionaria {
    private ArrayList<Carro> carros = new ArrayList<Carro>();

    public ArrayList getCarros()
    {
        return carros;
    }
    public void setCarros(Carro carro)
    {
        carros.add(carro);
    }
    public Carro searchForCar(String name)
    {
        for (Carro car : carros)
        {
            if (car.equals(name))
                return car;
        }
        return null;
    }



}

