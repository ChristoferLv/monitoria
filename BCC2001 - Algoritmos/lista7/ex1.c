#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_matrix(int rows, int cols, int m[rows][cols]) // Ex1
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void print_reversed(int rows, int cols, int m[rows][cols])
{
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 0; j--)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void print_min_max(int rows, int cols, int m[rows][cols])
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 0; j--)
        {
            if (m[i][j] < min)
            {
                min = m[i][j];
            }
            if (m[i][j] > max)
            {
                max = m[i][j];
            }
        }
    }
    printf("Maior: %d - Menor: %d", max, min);
}

float average(int rows, int cols, int m[rows][cols])
{
    int sum = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            sum = sum + m[i][j];
        }
    }
    return sum / (rows * cols);
}

void init_values(int rows, int cols, int m[rows][cols], int start, int step)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            m[i][j] = start + ((i * cols * step) + j * step);
        }
    }
}

void init_random(int rows, int cols, int m[rows][cols], int min, int max)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            int new_rand = rand() % max + min;
            m[i][j] = new_rand;
        }
    }
}

int max_line(int rows, int cols, int m[rows][cols])
{
    int max = INT_MIN;
    int sum = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            sum = sum + m[i][j];
            if (sum > max)
            {
                max = sum;
            }
        }
        sum = 0;
    }
    return max;
}

void put_totals(int rows, int cols, int m[rows][cols])
{
    int sum = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols - 1; j++)
        {
            sum = sum + m[i][j];
        }
        m[i][cols - 1] = sum;
        sum = 0;
    }
}

int main()
{
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    print_matrix(3, 3, mat1);
    print_reversed(3, 3, mat1);
    print_min_max(3, 3, mat1);
    float avg = average(3, 3, mat1);
    printf("\n");
    printf("Média: %.2f\n", avg);
    int v[4][6];
    init_values(4, 6, v, 10, 2); // start=10, step=2
    print_matrix(4, 6, v);
    printf("\n");
    int v2[4][6];
    init_random(4, 6, v2, 5, 50); // start=10, step=2
    print_matrix(4, 6, v2);
    printf("\n");
    int mat[5][5] = {
        {1, 2, 3, 4, 5},  // soma: 15
        {2, 4, 6, 8, 10}, // soma: 30 ← esta linha possui a maior soma
        {1, 2, 3, 4, 7},  // soma: 17
        {2, 0, 6, 1, 10}, // soma: 19
        {7, 3, 4, 0, 0}   // soma: 14
    };
    int res = max_line(5, 5, mat);
    printf("Maior soma: %d\n", res); // imprime 30
    int mat2[4][5] = {
        {1, 2, 3, 4, 0},
        {2, 4, 6, 8, 0},
        {3, 6, 9, 12, 0}, // O último elemento de cada linha receberá a soma
        {4, 8, 12, 16, 0} // da linha.
    };
    put_totals(4, 5, mat2);
    print_matrix(4, 5, mat2);

    return 0;
}