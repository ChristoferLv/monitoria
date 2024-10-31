#include <stdio.h>
#include "utils.h"

void vector_insert(int n, int vet1[], int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (vet1[i] == -1)
        {
            vet1[i] = elem;
            printf("1\n");
            return;
        }
    }
    printf("0\n");
    return;
}

int main()
{
    int qtd = 10;
    int vet[] = {1, 2, 3, -1, -1, 7, -1, 8, 9, 10};
    print_vector(qtd, vet);
    vector_insert(qtd, vet, 44);
    print_vector(qtd, vet);
    vector_insert(qtd, vet, 55);
    print_vector(qtd, vet);
    vector_insert(qtd, vet, 66);
    print_vector(qtd, vet);
    vector_insert(qtd, vet, 77);
    print_vector(qtd, vet);

    return 0;
}