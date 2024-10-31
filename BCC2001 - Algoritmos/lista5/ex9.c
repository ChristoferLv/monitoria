#include <stdio.h>
#include "utils.h"

void vector_copy(int n, int vet2[], int vet1[])
{
    for (int i = 0; i < n; i++)
    {
        vet2[i] = vet1[i];
    }
}

int main()
{
    int qtd = 10;
    int vet1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vet2[10] = {0}; //Inicializa o vetor com 0

    printf("Vetor 1:\n");
    print_vector(qtd, vet1);
    printf("Vetor 2:\n");
    print_vector(qtd, vet2);

    vector_copy(qtd, vet2, vet1);

    printf("\nVetor 1:\n");
    print_vector(qtd, vet1);
    printf("Vetor 2:\n");
    print_vector(qtd, vet2);
    return 0;
}