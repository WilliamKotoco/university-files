import java.util.ArrayList;
public class Loja {
    ArrayList<Item> itens = new ArrayList<>();

    public ArrayList<Item> getItens() {
        return itens;

    }

    public void setItens(Item item) {
        itens.add(item);
    }

    public Item searchForItem(String nome)
    {
        for (Item item : getItens())
        {
            if (nome.equals(item.getName()))
                return item;
        }
        return null;
    }
    public Item searchForItem(int id)
    {
        // procura por id dessa vez
        for(Item item : getItens())
        {
            if (id == item.getId())
                return item;
        }
        return null;
    }
}



