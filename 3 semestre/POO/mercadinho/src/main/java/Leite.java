public class Leite extends Produto
{
    private int durationInDays;

    public Leite(String name, double price, int intdurationInDays)
    {
        super(name, price);
        this.durationInDays = durationInDays;
    }

    public int getDurationInDays() {
        return durationInDays;
    }

    public void setDurationInDays(int durationInDays) {
        this.durationInDays = durationInDays;
    }

    @Override
    public int compareTo(Object obj)
    {
        Leite leite = (Leite) obj;
        if ((this.durationInDays > leite.getDurationInDays() )) // 0.5 por dia
        {
            return 1;
        }
        if (this.durationInDays < leite.getDurationInDays() )) // 0.5 por dia
        {
            return -1;
        }
        else {
            return 0;
        }

    }
}