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
    public int compareTo(Object obj)
    {
        Shampoo shampoo = (Shampoo)  obj;
        if(this.irritability > shampoo.getIrritability())
        {
            return -1;
        }
        else if(this.irritability < shampoo.getIrritability())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
