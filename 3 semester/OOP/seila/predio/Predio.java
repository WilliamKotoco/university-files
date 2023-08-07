import java.util.ArrayList;

public class Predio {
    private int quantidadeAndares;
    private ArrayList<Elevadores>  elevadores = new ArrayList<>();

    public Predio(int quantidadeAndares) {
        this.quantidadeAndares = quantidadeAndares;
    }

    public int getQuantidadeAndares() {
        return quantidadeAndares;
    }

    public void setQuantidadeAndares(int quantidadeAndares) {
        this.quantidadeAndares = quantidadeAndares;
    }

    public ArrayList<Elevadores> getElevadores() {
        return elevadores;
    }

    public void setElevadores(int qtd) {

        for (int i = 0; i < qtd; i++)
        {
            Elevadores elevador = new Elevadores();
            elevadores.add(elevador);
        }
    }
}