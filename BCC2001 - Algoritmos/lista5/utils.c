#include <stdio.h>

void print_vector(int n, int vet[])
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("]\n");
}