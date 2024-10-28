#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0, mdc = 0;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    for (int i = 1; i <= (num1 * num2) / 2 + 1; i++)
    {
        if ((num1 % i) == 0 && (num2 % i) == 0)
        {
            mdc = i;
        }
    }

    if (mdc == 0)
    {
        printf("Os números %d e %d não possuem MDC.", num1, num2);
    }
    else
    {
        printf("MDC = %d", mdc);
    }

    return 0;
}