// código feio tudo na main eu quero é que se foda
import java.util.Scanner;
public class Matriz
{
    public static void main(String[] args) {
        int row1, row2, col1, col2, i,j, k, sum = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("Digite o tamanho da primeira matriz, linhas e colunas, separados por espaço: ");
        row1 = input.nextInt();
        col1 = input.nextInt();

        System.out.println("Digite o tamanho da segunda matriz, linhas e colunas, separados por espaço: ");
        row2 = input.nextInt();
        col2 = input.nextInt();
    
        if (col1 == row2)
        {
            // agora basta realizar a multiplicação
        int[][] matriz1 = new int[row1][col1];
        int [][] matriz2 = new int[row2][col2];

        for ( i = 0;  i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
             System.out.println("DIgite os números da matriz1 ");
             matriz1[i][j] = input.nextInt();   
            }
        }

        for ( i = 0;  i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
             System.out.println("DIgite os números da matriz2 2");
             matriz2[i][j] = input.nextInt();   
            }
        }
        int[][] result = new int[row1][col2];
        
        for (i = 0; i < row1; i++) 
            {
                for (j=0; j < col2; j++) 
                {
                    sum = 0;
                    for (k=0; k < col1; k++ ) 
                       sum += matriz1[i][k] * matriz2[k][j];
                    result[i][j] = sum;
                }
            }


            for(i=0; i < row1; i++)
            for(j = 0; j < col2; j++)
                System.out.println(result[i][j] + " ");
        }
        
        else
            System.out.println("Matrizes não podem multiplicar");
        
        
    }

}
//coluna 1 linha 2