#include <stdio.h>
#include "utils.h"

void vector_concat(int n1, int v1[n1], int n2, int v2[n2], int v3[])
{
    for (int i = 0; i < n1; i++)
    {
        v3[i] = v1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        v3[n1+i] = v2[i];
    }
}

int main()
{
    int qtd1 = 10;
    int vet1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int qtd2 = 10;
    int vet2[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int vet3[20] = {0}; // Inicializa o vetor com 0

    print_vector(qtd1, vet1);
    print_vector(qtd2, vet2);
    vector_concat(qtd1, vet1, qtd2, vet2, vet3);
    print_vector((qtd1 + qtd2), vet3);
    return 0;
}