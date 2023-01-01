#include <stdio.h>
int isValid(int size, int row, int column);
void findSolutions(int row, int column, int steps, int size, int arrivedColumn);

int matrix[25][25];
int first = 0;
int main()
{
    int size, arrivedColumn, startedColumn, steps, i, j;
    // arrivedColumn
    // startedCumun
    scanf("%d %d %d", &size, &startedColumn, &arrivedColumn);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    steps = 0;
    findSolutions(0, startedColumn, steps, size, arrivedColumn);
    printf("-1\n");

    return 0;
}
void findSolutions(int row, int column, int steps, int size, int arrivedColumn)
{
    if (row == size - 1 && column == arrivedColumn && matrix[row][column] == 0)
    {
        printf("%d\n", steps);
        exit(0);
    }
    if (isValid(size, row, column) == 0)
        return;
    matrix[row][column] = 1;
    findSolutions(row + 1, column, steps + 1, size, arrivedColumn);
    findSolutions(row, column + 1, steps + 1, size, arrivedColumn);
    findSolutions(row, column -1 , steps + 1, size, arrivedColumn);
    return;
}

int isValid(int size, int row, int column)
{
    if(row>=0 && column >=0 && row < size && column<size && matrix[row][column] == 0)
        return 1;
    else
        return 0;
}
