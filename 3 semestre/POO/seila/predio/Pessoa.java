import java.util.ArrayList;
public class Pessoa {
    private int andarAtual;
    Predio predio;
    private String nome;
    Elevadores elevadorParaPegar;

    public int getAndarAtual() {
        return andarAtual;
    }

    public void setAndarAtual(int andarAtual) {
        this.andarAtual = andarAtual;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Elevadores getElevadorParaPegar() {
        return elevadorParaPegar;
    }

    private void setElevadorParaPegar(Elevadores elevadorParaPegar) {
        this.elevadorParaPegar = elevadorParaPegar;
    }
    public void setPredio(Predio predio)
    {
        this.predio = predio;
    }
    public Predio getPredio()
    {return predio;}


    public void chamarElevador(int dest) throws InterruptedException {
        int closer = 0; // guarda o índice do elevador mais próximo da pessoa
        int biggestDistance = 20 ; // comparador para pegar a menor distância, começa no último andar
        ArrayList<Elevadores> elevadores = predio.getElevadores();
        // buscar o elevador com o andar mais próximo da pessoa
        for (int i = 0; i < predio.getElevadores().size(); i++)
        {
            if (Math.abs( elevadores.get(i).getAndarAtual() - andarAtual)  < biggestDistance )
            {
                biggestDistance = elevadores.get(i).getAndarAtual() - andarAtual;
                closer = i;
            }
        }
        // chama o método chamar do elevador que ta mais perto
        elevadores.get(closer).Chamar(andarAtual, dest);


    }






}
