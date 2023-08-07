public class Shampoo extends Produto
{
    private int irritability;

    public Shampoo(String name, double price, int irritability)
    {
        super(name, price);
        this.irritability = irritability;
    }

    public void setIrritability(int irritability) {
        this.irritability = irritability;
    }

    public int getIrritability() {
        return irritability;
    }

    @Override
    public int compareTo(Shampoo shamps)
    {
        if(this.irritability > shamps.getIrritability())
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
