#include <stdio.h>
#include "utils.h"

void merge(int n1, int v1[], int n2, int v2[], int v3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            v3[k] = v1[i];
            i = i + 1;
            k = k + 1;
        }
        else
        {
            v3[k] = v2[j];
            j = j + 1;
            k = k + 1;
        }
    }

    while (i < n1)
    {
        v3[k] = v1[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < n2)
    {
        v3[k] = v2[j];
        j = j + 1;
        k = k + 1;
    }
}

int main()
{
    int qtd1 = 10;
    int vet1[10] = {1, 2, 7, 8, 9, 11, 11, 13, 15, 17};
    int qtd2 = 10;
    int vet2[10] = {3, 5, 6, 7, 10, 11, 12, 14, 16, 17};
    int vet3[20] = {0}; // Inicializa o vetor com 0

    print_vector(qtd1, vet1);
    print_vector(qtd2, vet2);
    merge(qtd1, vet1, qtd2, vet2, vet3);
    print_vector((qtd1 + qtd2), vet3);
    return 0;
}