#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0;
    int acc = 0;
    printf("Informe o primeiro número: ");
    scanf("%d", &num1);
    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    for (int i = 0; i < num2; i++)
    {
        acc = acc + num1;
    }

    printf("%d", acc);

    return 0;
}