#include <stdio.h>

void print_even(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        if ((vet[i] % 2) == 0)
        {
            printf("%d\n", vet[i]);
        }
    }
}

int main()
{
    int qtd = 10;
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_even(qtd, vet);

    return 0;
}