import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
public class Main
{
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("text.txt");
        Scanner input = new Scanner(file);
        /*
         * ler um txt e mostrar as 10 palavras mais frequentes, usando HashMap.
         */
        Map<String, Integer> words = new HashMap<>();
        while(input.hasNextLine())
        {
            String linha = input.nextLine();
            String[] palavras = linha.split(" ");
            for (String word : palavras)
            {
                if(words.containsKey(word))
                    words.put(word, words.get(word)+1);
                else
                    words.put(word, 1);
            }

        }


    }
    }
