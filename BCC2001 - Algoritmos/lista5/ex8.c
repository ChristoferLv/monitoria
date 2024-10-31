#include <stdio.h>
#include "utils.h"

void reverse(int n, int vet[])
{
    int temp = 0;
    for (int i = 0; i < n/2; i++)
    {
        temp = vet[i];
        vet[i] = vet[n - i -1];
        vet[n - i - 1] = temp;
    }
}

int main()
{
    int qtd = 10;
    int vet[] = {1, 2, 3, 4, 5, 7, 7, 8, 9, 10};
    print_vector(qtd, vet);
    reverse(qtd, vet);
    print_vector(qtd, vet);

    return 0;
}