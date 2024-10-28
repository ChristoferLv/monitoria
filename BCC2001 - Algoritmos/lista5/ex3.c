#include <stdio.h>

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

int main()
{
    int qtd = 10;
    int vet[] = {1, -2, -3, 4, -5, 60, -7, 8, 9, 10};
    printf("O maior número no vetor é %d", find_max(qtd, vet));

    return 0;
}