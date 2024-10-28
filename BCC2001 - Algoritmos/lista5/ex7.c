#include <stdio.h>
#include <math.h>

void distances(int n, int points[])
{
    float distance = 0;
    for (int i = 0; i < n; i = i + 4)
    {
        distance = sqrt((points[i + 1] - points[i]) * (points[i + 1] - points[i]) + (points[i + 3] - points[i + 2]) * (points[i + 3] - points[i + 2]));
        printf("%f\n", distance);
    }
}

int main()
{
    int qtd = 8;
    int vet[] = {1, 2, 3, 4, 5, 7, 7, 8};
    distances(qtd, vet);
    return 0;
}