#include <stdio.h>
#include <math.h>
#include "utils.h"

int find_max(int n, int vet[])
{
    int maior = vet[0];
    for (int i = 0; i < n; i++)
    {
        if (vet[i] > maior)
        {
            maior = vet[i];
        }
    }
    return maior;
}

void print_existent(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] != 0)
        {
            printf("O número %d apareceu %d vezes.\n", i, vet[i]);
        }
    }
}

void count_elements(int n, int vet[])
{
    int biggest = find_max(n, vet);
    int count[biggest];
    
    for (int i = 0; i < biggest; i++)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count[vet[i]] = count[vet[i]] + 1;
    }
    print_existent(biggest, count);
}

int main()
{

    int qtd = 8;
    int vet[] = {1, 1, 2, 3, 6, 6, 10, 12};
    count_elements(qtd, vet);

    return 0;
}