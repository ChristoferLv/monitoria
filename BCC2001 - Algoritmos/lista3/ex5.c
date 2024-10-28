#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0;
    int acc = 0, res = 0, i;
    printf("Informe o primeiro número: ");
    scanf("%d", &num1);
    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    acc = num1;
    for (i = 0; acc >= 0; i++)
    {
        acc = acc - num2;
    }
    res = num2 + acc;

    printf("%d / %d = %d\n", num1, num2, i-1);
    printf("%d %% %d = %d", num1, num2, res);

    return 0;
}