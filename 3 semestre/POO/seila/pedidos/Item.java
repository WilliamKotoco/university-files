public class Item {
    private String name;
    private int id; // identificador do item, único.
    private double preco;

    public Item(String name, int id, double preco, double peso) {
        this.name = name;
        this.id = id;
        this.preco = preco;
        this.peso = peso;
    }

    private double peso;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }
}
