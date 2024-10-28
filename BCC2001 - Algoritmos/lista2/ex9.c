#include <stdio.h>

int main()
{
    int num = 0;
    printf("Digite um número de 5 digitos para ser desmontado.");
    scanf("%d", &num);
    if (num < 10000 || num > 99999)
    {
        printf("Número inválido\n");
        return 0;
    }
    printf("%d\n", num % 10);
    num = num / 10;
    printf("%d\n", num % 10);
    num = num / 10;
    printf("%d\n", num % 10);
    num = num / 10;
    printf("%d\n", num % 10);
    num = num / 10;
    printf("%d\n", num % 10);

    return 0;
}