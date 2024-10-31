#include <stdio.h>
#include "utils.h"

void vector_defrag(int n, int vet[n])
{   
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (vet[j] != -1)
                {
                    vet[i] = vet[j];
                    vet[j] = -1;
                    break;
                }
            }
        }
    }
}

int main()
{
    int qtd = 10;
    int vet[] = {1, 2, -1, 4, -1, -1, 7, -1, 9, 10};
    print_vector(qtd, vet);
    vector_defrag(qtd, vet);
    print_vector(qtd, vet);

    return 0;
}