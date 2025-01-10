#include <stdio.h>
#include <stdlib.h>



void print_vector2D(int m, int n, const int **v)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows = 3;
    int cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    print_vector2D(rows, cols, (const int **)matrix);

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    return 0;
}