#include <stdio.h>
#include "utils.h"

void set_positive(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            vet[i] = vet[i] * (-1);
        }
    }
}

int main()
{
    int qtd = 10;
    int vet[] = {1, -2, -3, 4, -5, 6, -7, 8, 9, 10};
    set_positive(qtd, vet);
    print_vector(qtd, vet);

    return 0;
}