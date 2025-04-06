#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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

void print_reversed(int rows, int cols, int m[rows][cols]) // Ex2
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

void print_min_max(int rows, int cols, int m[rows][cols]) // Ex3
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

float average(int rows, int cols, int m[rows][cols]) // Ex4
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

void init_values(int rows, int cols, int m[rows][cols], int start, int step) // Ex5
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            m[i][j] = start + ((i * cols * step) + j * step);
        }
    }
}

void init_random(int rows, int cols, int m[rows][cols], int min, int max) // Ex6
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

int max_line(int rows, int cols, int m[rows][cols]) // Ex7
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

void put_totals(int rows, int cols, int m[rows][cols]) // Ex8
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

int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2])
{
    if (r1 != r2 || c1 != c2)
    {
        return 0;
    }

    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c1; j++)
        {
            if (m1[i][j] != m2[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols],
         int m3[rows][cols])
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2])
{
    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c1; j++)
        {
            m2[j][i] = m1[i][j];
        }
    }
}

void switch_diagonals(int d, int m1[d][d])
{
    int temp = 0;
    for (size_t i = 0; i < d; i++)
    {
        temp = m1[i][i];
        m1[i][i] = m1[i][d - i - 1];
        m1[i][d - i - 1] = temp;
    }
}

void pascal_triangle(int n)
{
    int pasc[n][n + 1];
    init_values(n, n + 1, pasc, 0, 0);
    pasc[0][1] = 1;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n + 1; j++)
        {
            pasc[i + 1][j + 1] = pasc[i][j] + pasc[i][j + 1];
        }
    }
    print_matrix(n, n + 1, pasc);
}

int check_upper_triangle(int d, int m[d][d])
{
    for (size_t i = 1; i < d; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (m[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int check_symmetric(int d, int m[d][d])
{
    for (size_t i = 0; i < d; i++)
    {
        for (size_t j = 0; j < d; j++)
        {
            if (m[i][j] != m[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

void print_strings(int n, int len, char list[n][len])
{
    for (int i = 0; i < n; i++)
    {
        printf("%s - ", list[i]);
    }
}

void print_strings_minmax(int n, int len, char list[n][len]){
    int maior = INT_MIN;
    int menor = INT_MAX;
    int temp = 0;
    for (size_t i = 0; i < n; i++)
    {
        
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
    int equal = 0;
    equal = matrix_equals(5, 5, mat, 4, 5, mat2);
    printf("Igual? %d\n", equal);
    int mat3[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}, // O último elemento de cada linha receberá a soma
        {13, 14, 15, 16} // da linha.
    };
    int mat4[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}, // O último elemento de cada linha receberá a soma
        {13, 14, 15, 16} // da linha.
    };
    int mat5[4][4];
    sum(4, 4, mat3, mat4, mat5);
    print_matrix(4, 4, mat5);
    int mat6[2][3] = {
        {1, 2, 3},
        {5, 6, 7},
    };
    int mat7[3][2];
    transpose(2, 3, mat6, 3, 2, mat7);
    print_matrix(3, 2, mat7);
    int mat8[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    switch_diagonals(3, mat8);
    print_matrix(3, 3, mat8);
    pascal_triangle(6);
    int mat9[4][4] = {
        {1, 2, 3, 7},
        {0, 5, 6, 7},
        {0, 0, 9, 7},
        {0, 0, 0, 7}};
    int triangle = 0;
    triangle = check_upper_triangle(4, mat9);
    printf("UP triangle? %d\n", triangle);
    int mat10[4][4] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 9, 11},
        {4, 7, 11, 0}};
    int syme = 0;
    syme = check_symmetric(4, mat10);
    printf("Symetric? %d\n", syme);
    char v3[6][20] = {"John", "Mary", "Jake", "Finn", "Ada", "Michael"};
    print_strings(6, 20, v3);
    return 0;
}