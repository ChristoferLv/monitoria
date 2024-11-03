#include <stdio.h>
#include <stdlib.h>

int **create_vector2D(int m, int n)
{
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    int val = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = val++;
        }
    }
}

int main()
{
    int rows = 3;
    int cols = 3;

    create_vector2D(rows, cols);

    return 0;
}