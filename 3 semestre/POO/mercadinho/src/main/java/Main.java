public class Main {

    public static void main(String[] args) {
        Shampoo[] shampoos = new Shampoo[3];
        Leite[] leites = new Leite[3];
        Biscoito[] biscoitos = new Biscoito[3];


        shampoos[0] = new Shampoo("Shampoo Messi", 30, 1 );
        shampoos[1]  = new Shampoo("Cristiano Ronaldo", 2, 304);
        shampoos[2] = new Shampoo("Caça-Caspa", 10, 5);

        leites[0] = new Leite("Cumzone", 15, 100000);
        leites[1] = new Leite("Barriguinha", 10, 20);
        leites[2] = new Leite("Jacaré do mato", 21, 23);

        biscoitos[0] = new Biscoito("Carioquinha", 3, 329);
        biscoitos[1] = new Biscoito("Java café", 30, 1);
        biscoitos[2] = new Biscoito("Sono Crack", 0, 999);


        displayBest("biscoito", biscoitos);
        displayBest("leite", leites);
        displayBest("shampoos", shampoos);




    }
    public static void displayBest(String type, Produto[] prods)
    {
        Produto better;
        int flag = prods[0].compareTo(prods[1]);
        if (flag == 1)
            better = prods[0];
        else
            better = prods[1];
        flag = better.compareTo(prods[2]);
        if (flag == 1)
            System.out.println("O melhor " + type+ " é " + better.getName());
        else
            System.out.println("O melhor " + type+ " é " + prods[2].getName());

    }


}
