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
    public int compareTo(Leite leite)
    {
        if ((this.getPrice() / this.durationInDays) > leite.getPrice() / leite.getDurationInDays();) // 0.5 por dia
        {
            return 0;
        }
        else
            return 1;
    }
}