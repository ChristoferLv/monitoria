#include <stdio.h>
#include "utils.h"

void vector_remove(int n, int vet1[], int pos)
{
    if (pos < 0 || pos >= n)
    {
        return;
    }
    vet1[pos] = -1;
}

int main()
{
    int qtd = 10;
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector_remove(qtd, vet, 2);
    print_vector(qtd, vet);
    vector_remove(qtd, vet, 5);
    print_vector(qtd, vet);
    vector_remove(qtd, vet, 7);
    print_vector(qtd, vet);
    vector_remove(qtd, vet, 12);
    print_vector(qtd, vet);

    return 0;
}