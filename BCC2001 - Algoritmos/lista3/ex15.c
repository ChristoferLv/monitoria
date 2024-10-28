#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0, mmc = 0, mult = 0;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    mult = num1 * num2;
    for (int i = mult; i >= 2; i--)
    {
        if ((i % num1) == 0 && (i % num2) == 0)
        {
            mmc = i;
        }
    }

    printf("MMC = %d", mmc);

    return 0;
}