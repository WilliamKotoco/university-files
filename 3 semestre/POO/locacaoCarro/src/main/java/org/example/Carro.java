package org.example;

public class Carro {
    private String modelo;
    private String placa;
    private Double pricePerDay;

    public Carro(String modelo, String placa, Double pricePerDay) {
        this.modelo = modelo;
        this.placa = placa;
        this.pricePerDay = pricePerDay;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public Double getPricePerDay() {
        return pricePerDay;
    }

    public void setPricePerDay(Double pricePerDay) {
        this.pricePerDay = pricePerDay;
    }
}
