#include <stdio.h>
#include "utils.h"

void max_sum_slice2(int n, int v[])
{
    int restart = 1;

    int biggest_sum = -99999;
    int biggest_start = -1;
    int biggest_end = -1;

    int current_sum = -99999;
    int current_start = -1;
    int current_end = -1;

    for (int i = 0; i < n; i++)
    {
        current_start = i;
        current_sum = 0;
        for (int j = i; j < n; j++)
        {
            current_sum = current_sum + v[j];
            if (current_sum > biggest_sum)
            {
                biggest_start = current_start;
                biggest_end = j;
                biggest_sum = current_sum;
            }
        }
    }
    printf("Soma: %d, Start: %d, End: %d", biggest_sum, biggest_start, biggest_end);
}

int main()
{
    int qtd = 12;
    int vet[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
    max_sum_slice2(qtd, vet);

    return 0;
}