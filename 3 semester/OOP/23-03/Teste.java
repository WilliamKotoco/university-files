public class Teste
{
    int x,y;


public Teste(int x, int y)
{
    this.x = x;
    this.y = y;
}
    public void move(Teste circle, int x, int y)
{
    this.x += x;
    this.y += y;

    circle = new Teste(0,0);
    /*
     * Ele cria um novo circle na memória apontando para 0,0
     * e o circle antigo (o passado por parâmetro) continua existindo, logo conseguimos acessar o valor antigo na classe main
     */
}
}
