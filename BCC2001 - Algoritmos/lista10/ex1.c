#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void print_vector(int n, const int *v) // Suporte
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("]\n");
}

int compare(const void *a, const void *b) // Suporte
{
    const int *valA = (const int *)a;
    const int *valB = (const int *)b;
    return *valB - *valA;
}

int *create_vector(int n) // Ex1
{
    int *v = calloc(n, sizeof(int));
    return v;
}

//============================================================================ // Ex2
int *get_largest(int n, int *v, int max) // Sem ordenar
{
    int *maiores = calloc(max, sizeof(int));
    // int menor = 0;
    maiores[0] = v[0];
    maiores[1] = v[0];
    for (size_t i = 0; i < n; i++)
    {
        if (v[i] > maiores[0])
        {
            maiores[1] = maiores[0];
            maiores[0] = v[i];
            continue;
        }
        if (v[i] > maiores[1])
        {
            maiores[1] = v[i];
        }
    }
    return maiores;
}

int *get_largest_sort(int n, int *v, int max) // Ordenando
{
    int *maiores = calloc(max, sizeof(int));
    qsort(v, n, sizeof(int), compare);
    for (size_t i = 0; i < max; i++)
    {
        maiores[i] = v[i];
    }
    return maiores;
}

char *copy_string(const char *str) // Ex3
{
    size_t tamanho = strlen(str);
    char *newString = malloc((tamanho + 1) * sizeof(char));
    for (size_t i = 0; i < tamanho; i++)
    {
        newString[i] = str[i];
    }
    newString[tamanho] = '\0';
    return newString;
}

char *copy_reverse(const char *str) // Ex4
{
    size_t tamanho = strlen(str);
    char *newString = malloc((tamanho + 1) * sizeof(char));
    for (size_t i = 0; i < tamanho; i++)
    {
        newString[i] = str[tamanho - 1 - i];
    }
    newString[tamanho] = '\0';
    return newString;
}

char *concat_string(const char *str1, const char *str2) // Ex5
{
    size_t tam1 = strlen(str1);
    size_t tam2 = strlen(str2);
    char *newString = malloc((tam1 + tam2 + 1) * sizeof(char));

    for (size_t i = 0; i < tam1; i++)
    {
        newString[i] = str1[i];
    }
    for (size_t i = 0; i < tam1; i++)
    {
        newString[i + tam1] = str2[i];
    }
    newString[tam1 + tam2] = '\0';
    return newString;
}

int *array_union(int n1, const int *v1, int n2, const int *v2, int *newTam) // Ex6
{
    bool found = 0;
    size_t index = 0;
    int *indexer = malloc(n2 * sizeof(int));
    for (size_t i = 0; i < n2; i++)
    {
        for (size_t j = 0; j < n1; j++)
        {
            if (v2[i] == v1[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            indexer[index] = i;
            index = index + 1;
        }
        found = false;
    }
    int *uni = malloc((n1 + index) * sizeof(int));
    for (size_t i = 0; i < n1; i++)
    {
        uni[i] = v1[i];
    }
    for (size_t i = 0; i < index; i++)
    {
        uni[n1 + i] = v2[indexer[i]];
    }
    free(indexer);
    *newTam = n1 + index;
    return uni;
}

int *array_intersection(int n1, const int *v1, int n2, const int *v2, int *newTam) // Ex7
{
    size_t index = 0;
    int *indexer = NULL;
    if (n1 > n2)
    {
        indexer = malloc(n1 * sizeof(int));
    }
    else
    {
        indexer = malloc(n2 * sizeof(int));
    }
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j])
            {
                indexer[index] = v1[i];
                index = index + 1;
            }
        }
    }
    int *inter = malloc((index) * sizeof(int));
    for (size_t i = 0; i < index; i++)
    {
        inter[i] = indexer[i];
    }
    free(indexer);
    *newTam = index;
    return inter;
}

int **create_vector2D(int m, int n) // Ex9
{
    size_t count = 0;
    int **linhas = malloc(m * sizeof(int *));
    for (size_t i = 0; i < m; i++)
    {
        linhas[i] = malloc(n * sizeof(int));

        for (size_t j = 0; j < n; j++)
        {
            linhas[i][j] = count++;
        }
    }
    return linhas;
}

void print_vector2D(int m, int n, int **v) // Ex8
{
    printf("\n");
    for (size_t i = 0; i < m; i++)
    {
        printf("[");
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

int **transpose(int m, int n, int v[m][n]) // Ex10
{
    int **newMat = create_vector2D(n, m);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            newMat[j][i] = v[i][j];
        }
    }
    return newMat;
}

char **split(const char *str, int *n) // Ex11
{
    size_t idx = 0;
    size_t wordStart = INT_MAX;
    size_t wordEnd = 0;
    bool space = false;

    int capacity = 2;
    char **palavras = malloc(capacity * sizeof(char *));
    size_t idxPalavra = 0;
    while (str[idx] == ' ')
    {
        idx = idx + 1;
        space = true;
    }
    while (str[idx] != '\0')
    {
        if (idxPalavra >= capacity)
        {
            capacity = capacity + 5;
            palavras = realloc(palavras, capacity * sizeof(char *));
        }
        
        if (space && str[idx] != ' ')
        {
            wordStart = idx;
            space = false;
        }
        if (!space && str[idx] == ' ')
        {
            wordEnd = idx;
            space = true;
        }
        if (wordEnd > wordStart)
        {
            char *newWord = malloc((wordEnd - wordStart + 1) * sizeof(char));
            newWord[wordEnd - wordStart] = '\0';
            memcpy(newWord, str+wordStart, wordEnd - wordStart);
            palavras[idxPalavra] = newWord;
            idxPalavra = idxPalavra + 1;
            wordStart = INT_MAX;
        }
        idx = idx+1;
    }
    *n = idxPalavra;
    return palavras;
}

int main()
{
    int *v1 = create_vector(7); // aloca array de 7 inteiros na heap
    print_vector(7, v1);        // imprime 0,0,0,0,0,0,0
    free(v1);

    int v0[] = {6, 10, 2, 1, 2, 3, 9};
    int *v2 = get_largest(7, v0, 2); // retorna vetor com os 2 maiores valores de v0
    print_vector(2, v2);
    int *v2_2 = get_largest_sort(7, v0, 2); // retorna vetor com os 2 maiores valores de v0
    print_vector(2, v2_2);                  // imprime 10,9
    free(v2);
    free(v2_2);

    char umastring[] = "Texto123";
    char *copia = copy_string(umastring);
    printf("|%s|\n", copia);
    free(copia);

    char umastring2[] = "Texto123";
    char *copia2 = copy_reverse(umastring2);
    printf("|%s|\n", copia2);
    free(copia2);

    char texto1[] = "Texto1";
    char texto2[] = "Texto2";
    char *concat = concat_string(texto1, texto2);
    printf("|%s|\n", concat);
    free(concat);

    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {6, 2, 3, 7};
    int newtam = 0;
    int *uni = array_union(5, nums1, 4, nums2, &newtam);
    print_vector(newtam, uni);
    free(uni);

    int nums3[] = {1, 2, 3, 4, 5};
    int nums4[] = {6, 2, 3, 7};
    int newtam2 = 0;
    int *inter = array_intersection(5, nums3, 4, nums4, &newtam2);
    print_vector(newtam2, inter);
    free(inter);

    int **vetor = create_vector2D(3, 4);
    print_vector2D(3, 4, vetor);
    free(vetor);

    int v[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    int **vtransposta = transpose(3, 4, v);
    print_vector2D(4, 3, vtransposta);
    free(vtransposta);

    char str[] = " Texto de teste com varias palavras ";
    int size = 0;
    char **tokens = split(str, &size); // devolve vetor de strings com as palavras
    for (int i = 0; i < size; i++)
        printf("|%s|\n", tokens[i]); // imprime as palavras encontradas
    // // libera vetor de strings alocado na heap
    // for (int i = 0; i < size; i++)
    //     free(tokens[i]);
    // free(tokens);
    return 0;
}