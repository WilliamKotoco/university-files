import java.lang.Comparable;

public abstract class Produto implements Comparable
{
    private String name;
    private double price;

    public Produto(String name, double price)
    {
        this.name = name;
        this.price = price;
    }

    public void setName(String name)
    {
        this.name = name;
    }
    public void setPrice(double price)
    {
        this.price = price;
    }
    public String getName(){return name;}
    public double getPrice(){return price;}

   