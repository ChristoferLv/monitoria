#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int *create_vector(int n)
{
    int *vet = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        vet[i] = 0;
    }
    return vet;
}

int main()
{
    int *v1 = create_vector(7); // aloca array de 7 inteiros na heap
    print_vector(7, v1);        // imprime 0,0,0,0,0,0,0
    free(v1);

    return 0;
}