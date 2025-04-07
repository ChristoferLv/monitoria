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

int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]) // Ex9
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

void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], // Ex10
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

void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]) // Ex11
{
    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c1; j++)
        {
            m2[j][i] = m1[i][j];
        }
    }
}

void switch_diagonals(int d, int m1[d][d]) // Ex12
{
    int temp = 0;
    for (size_t i = 0; i < d; i++)
    {
        temp = m1[i][i];
        m1[i][i] = m1[i][d - i - 1];
        m1[i][d - i - 1] = temp;
    }
}

void pascal_triangle(int n) // Ex13
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

int check_upper_triangle(int d, int m[d][d]) // Ex14
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

int check_identity(int rows, int cols, int m[rows][cols]) // Ex15
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = i; j < cols; j++)
        {
            if (i == j)
            {
                if (m[i][j] != 1)
                {
                    return 0;
                }
                continue;
            }
            if (m[i][j] != 0)
            {
                return 0;
            }
            if (m[j][i] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_symmetric(int d, int m[d][d]) // Ex16
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

void print_strings(int n, int len, char list[n][len]) // Ex17
{
    for (int i = 0; i < n; i++)
    {
        printf("%s - ", list[i]);
    }
    printf("\n");
}

void print_strings_minmax(int n, int len, char list[n][len]) // Ex18
{
    int maior = INT_MIN;
    int menor = INT_MAX;
    int temp = 0;
    for (size_t i = 0; i < n; i++)
    {
        temp = strlen(list[i]);
        if (temp > maior)
        {
            maior = temp;
        }
        if (temp < menor)
        {
            menor = temp;
        }
    }
    printf("Menor: ");
    for (size_t i = 0; i < n; i++)
    {
        if (strlen(list[i]) == menor)
        {
            printf("%s, ", list[i]);
        }
    }
    printf("\n");
    printf("Maior: ");
    for (size_t i = 0; i < n; i++)
    {
        if (strlen(list[i]) == maior)
        {
            printf("%s, ", list[i]);
        }
    }
    printf("\n");
}

int count_words_plus(const char str[]) // Ex19-sup
{
    size_t strTam = strlen(str);
    size_t numPalavras = 0;
    if (str[0] != ' ')
    {
        numPalavras = numPalavras + 1;
        if (strTam == 1)
            return 1;
    }
    for (size_t i = 1; i < strTam; i++)
    {
        if (str[i] != ' ' && str[i - 1] == ' ')
        {
            numPalavras = numPalavras + 1;
        }
    }
    return numPalavras;
}

int count_words(int n, int len, char lines[n][len]) // Ex19
{
    int words = 0;
    for (size_t i = 0; i < n; i++)
    {
        words = words + count_words_plus(lines[i]);
    }
    return words;
}
int numOccurrences(const char str[], const char sub[]) // Ex20-sup
{
    size_t occurrences = 0;
    size_t idx = 0;
    size_t strSize = strlen(str);
    for (size_t i = 0; i < strSize; i++)
    {
        if (str[i] == sub[idx])
        {
            idx = idx + 1;
            if (sub[idx] == '\0')
            {
                occurrences = occurrences + 1;
            }
        }
        else
        {
            idx = 0;
        }
    }
    return occurrences;
}
int count_occurrences(int n, int len, char lines[n][len], char word[]) // Ex20
{
    int occurrences = 0;
    for (size_t i = 0; i < n; i++)
    {
        occurrences = occurrences + numOccurrences(lines[i], word);
    }
    return occurrences;
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
    int mat10[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    int ident = 0;
    ident = check_identity(3, 3, mat10);
    printf("Identity? %d\n", ident);
    int mat11[4][4] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 9, 11},
        {4, 7, 11, 0}};
    int syme = 0;
    syme = check_symmetric(4, mat11);
    printf("Symetric? %d\n", syme);
    char v3[6][20] = {"John", "Mary", "Jake", "Finn", "Ada", "Michael"};
    print_strings(6, 20, v3);
    char v4[6][20] = {"Joh", "Mariane", "Jak", "Samuel", "Ada", "Michelangelo"};
    print_strings_minmax(6, 20, v4);
    char v5[2][200] = {
        " Computer programming is the process of designing and building an "
        "executable computer program for accomplishing a specific computing task.",
        " Programming involves tasks such as analysis, generating algorithms, "
        "profiling algorithms accuracy and resource consumption, and the "
        "implementation of algorithms in a chosen programming language."};
    int count = count_words(2, 200, v5);
    printf("Numero de palavras: %d\n", count);
    char v6[5][200] = {
        "computer programming is the process of designing and building an "
        "executable computer program for accomplishing a specific computing task.",

        "programming involves tasks such as analysis, generating algorithms, "
        "profiling algorithms accuracy and resource consumption, and the "
        "implementation of algorithms in a chosen programming language.",

        "the source code of a program is written in one or more programming "
        "languages.",

        "the purpose of programming is to find a sequence of instructions that "
        "will automate the performance of a task for solving a given problem.",

        "the process of programming thus often requires expertise in several "
        "different subjects, including knowledge of the application domain, "
        "specialized algorithms, and formal logic."};
    int count2 = count_occurrences(5, 200, v6, "programming");
    printf("Numero de ocorrencias: %d\n", count2);
    return 0;
}