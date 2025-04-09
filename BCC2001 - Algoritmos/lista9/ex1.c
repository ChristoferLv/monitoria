#include <stdio.h>
#include <string.h>
#include <limits.h>

void print_addrs() // Ex1
{
    char v1;
    int v2;
    size_t v3;
    printf("%p - ", &v1);
    printf("%p - ", &v2);
    printf("%p\n", &v3);
}

void add(int *a, int *b) // Ex2
{
    *a = *a + *b;
}

void print_vector(int n, const int *v) // Ex3
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("]\n");
}

void print_vector_reverse(int n, const int *v) // Ex4
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *((v + n - 1) - i));
    }
    printf("]\n");
}

void get_min_max(int n, const int *v, int *min, int *max) // Ex5
{
    int maior = INT_MIN;
    int menor = INT_MAX;
    for (size_t i = 0; i < n; i++)
    {
        if (*(v + i) > maior)
        {
            maior = *(v + i);
        }
        if (*(v + i) < menor)
        {
            menor = *(v + i);
        }
    }
    *max = maior;
    *min = menor;
}

void print_vector2D(int rows, int cols, const int *v) // Ex6
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("%d ", *(v + (cols * i) + j));
        }
    }
    printf("\n");
}

void make_mirrored(char *str) // Ex7
{
    size_t tam = strlen(str);
    str = str + tam;
    *(str + tam + 1) = '\0';
    *(str) = '|';

    for (size_t i = 1; i < tam + 1; i++)
    {
        *(str + i) = *(str - i);
    }
}

int get_hamming_distance(const char *str1, const char *str2) // Ex8
{
    size_t dist = 0;
    for (size_t i = 0; *(str1 + i) != '\0' || *(str2 + i) != '\0'; i++)
    {
        if (*(str1 + i) != *(str2 + i))
        {
            dist = dist + 1;
        }
    }
    return dist;
}

int main()
{
    print_addrs();

    int a = 3;
    int b = 5;
    add(&a, &b);
    printf("%d\n", a);

    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8};
    print_vector(8, vector);

    print_vector_reverse(8, vector);

    int min = 0;
    int max = 0;
    get_min_max(8, vector, &min, &max);
    printf("Menor: %d - Maior: %d\n", min, max);

    int v[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    print_vector2D(3, 4, (int *)v);

    char name[40] = "John Doe";
    make_mirrored(name);
    printf("%s\n", name); // Saída "John Doe|eoD nhoJ"

    int dist = get_hamming_distance("banana", "cabana");
    printf("Distance: %d\n", dist);
    return 0;
}