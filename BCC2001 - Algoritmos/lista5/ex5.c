#include <stdio.h>
#include "utils.h"

void read_vector(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite o %d número: ", i + 1);
        scanf("%d", &vet[i]);
    }
}

int main()
{
    const int n = 10;
    int vet[n];
    read_vector(n, vet);
    print_vector(n, vet);

    return 0;
}