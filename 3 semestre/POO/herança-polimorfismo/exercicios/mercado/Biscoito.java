
public class Biscoito extends Produto
{

    private int cancerigenos;
    
    public Biscoito(String name, double price, int cancerigenos)
    {
        super(name, price);
        this.cancerigenos = cancerigenos;
    }

    public int getCancerigenos() {
        return cancerigenos;
    }

    public void setCancerigenos(int cancerigenos) {
        this.cancerigenos = cancerigenos;
    }

    @Override
    public int compareTo(Biscoito biscoito)
    {
        if (this.cancerigenos > biscoito.getCancerigenos()) // inventei
        {
            return 0;
        }
        else
            return 1;
    }
}