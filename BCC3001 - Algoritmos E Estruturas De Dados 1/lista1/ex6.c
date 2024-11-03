#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int is_in(int val, int n, int *v1)
{
    for (int i = 0; i < n; i++)
    {
        if (v1[i] == val)
        {
            return 1;
        }
    }
    return 0;
}

int *array_union(int n1, const int *v1, int n2, const int *v2)
{

    int *v3 = (int *)calloc((n1 + n2), sizeof(int));

    int pointer = 0;
    for (int i = 0; i < n1; i++)
    {
        v3[i] = v1[i];
    }

    pointer = n1;

    for (int i = 0; i < n2; i++)
    {
        if (!is_in(v2[i], pointer, v3))
        {
            v3[pointer] = v2[i];
            pointer = pointer + 1;
        }
    }
    return v3;
}

int main()
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[3] = {2, 3, 8};
    int *v3 = array_union(5, v1, 3, v2); 
    print_vector(8, v3);


    free(v3);
    return 0;
}