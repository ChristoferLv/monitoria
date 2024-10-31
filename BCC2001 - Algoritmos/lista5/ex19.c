#include <stdio.h>
#include "utils.h"

int is_in(int val, int n, int v1[])
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

void vector_intersection(int n1, int v1[n1], int n2, int v2[n2], int v3[])
{
    int pointer = 0;

    for (int i = 0; i < n1; i++)
    {
        if (is_in(v1[i], n2, v2))
        {
            v3[pointer] = v1[i];
            pointer = pointer + 1;
        }
    }
}

int main()
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[3] = {2, 3, 8};
    int v3[3] = {0};
    vector_intersection(5, v1, 3, v2, v3); // v3 = {1,2,3,4,5,8,0,0}
    print_vector(3, v3);
    return 0;
}