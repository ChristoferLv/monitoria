#include <stdio.h>

int is_sorted(int n, int vet[])
{
    int maior = vet[0];
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < maior)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int qtd = 10;
    int vet[] = {1,2,3,4,5,7,7,8,9,10};
    if (is_sorted(qtd, vet))
    {
        printf("O vetor está ordenado de forma crescente.");
    }
    else
    {
        printf("O vetor não está ordenado de forma crescente.");
    }

    return 0;
}