#include <stdio.h>
#include "utils.h"

void replace_all(int n, int vet[], int elem)
{
    int maior = vet[0];
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == elem)
        {
            vet[i] = -1;
        }
    }
}

int main()
{
    int qtd = 12;
    int vet[] = {1, 2, 3, 4, 3, 5, 1, 2, 3, 5, 3, 7};
    print_vector(qtd, vet);
    replace_all(qtd, vet, 3);
    print_vector(qtd, vet);

    return 0;
}