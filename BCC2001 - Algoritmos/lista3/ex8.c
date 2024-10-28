#include <stdio.h>

int main()
{
    int val = 0;
    int a = 1, b = 1, acc = 0;
    printf("Digite o termo: ");
    scanf("%d", &val);
    if (val == 1 || val == 2)
    {
        printf("O n-ésimo termo da série de Fibonacci é 1");
    }
    else
    {
        for (int i = 2; i < val; i++)
        {
            acc = a + b;
            a = b;
            b = acc;
        }
        printf("O n-ésimo termo da série de Fibonacci é %d", acc);
    }

    return 0;
}