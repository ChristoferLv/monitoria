#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

int *get_largest(int n, int *v, int max)
{
    int *vet = (int *)malloc(max * sizeof(int));
    for (int i = 0; i < max; i++)
    {
        vet[i] = INT_MIN;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (v[i] > vet[j])
            {
                for (int k = max - 1; k > j; k--)
                {
                    vet[k] = vet[k - 1];
                }
                vet[j] = v[i];
                break;
            }
        }
    }
    return vet;
}

int main()
{
    int v0[] = {6, 10, 2, 1, 2, 3, 9};
    int *v1 = get_largest(7, v0, 4); 
    print_vector(4, v1);             
    free(v1);

    return 0;
}