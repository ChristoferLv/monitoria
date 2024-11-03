#include <stdio.h>
#include <stdlib.h>

void print_vector2D(int m, int n, int **v)
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

int **transpose(int m, int n, int v[m][n])
{
    int **tMatriz = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        tMatriz[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++){
            tMatriz[j][i] = v[i][j];
        }
    }
    return tMatriz;
}

int main()
{
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int **tMatriz = transpose(3,3,matriz);
    print_vector2D(3,3,tMatriz);

    for(int i = 0; i < 3; i++){
        free(tMatriz[i]);
    }
    return 0;
}