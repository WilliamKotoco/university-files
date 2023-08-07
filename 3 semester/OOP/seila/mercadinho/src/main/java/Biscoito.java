
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
    public int compareTo(Object biscoito)
    {
        Biscoito biscoito1 = (Biscoito) biscoito;
        if (this.cancerigenos > biscoito1.getCancerigenos() ) // inventei
        {
            return -1;
        }
        else if (this.cancerigenos < biscoito1.getCancerigenos() )
            return 1;
        else
            return 0;
    }


}