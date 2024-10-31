#include <stdio.h>
#include "utils.h"

void min_bills(int value, int n, int bills[])
{
    int remaining = 0;
    int qtds[n];
    remaining = value;
    for (int i = n - 1; i >= 0; i--)
    { // ASSUMINDO QUE AS NOTAS ESTÃO EM ORDEM CRESCENTE
        qtds[i] = remaining / bills[i];
        remaining = remaining % bills[i];
    }
    print_vector(n ,qtds);
    printf("São necessárias:\n");
    for (int i = 0; i < n; i++)
    {
        if (qtds[i] != 0)
        {
            printf("- %d notas de %d\n", qtds[i], bills[i]);
        }
    }
}

int main()
{
    int value = 1058;
    int n = 5;
    int bills[] = {1, 5, 10, 50, 100};

    min_bills(value, n, bills);

    return 0;
}