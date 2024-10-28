#include <stdio.h>

int main()
{
    int num = 0;
    printf("Digite um ano para verificar se é bissexto: ");
    scanf("%d", &num);
    if ((num % 4 == 0 && num % 100 != 0) || num % 400 == 0)
    {
        printf("O ano é bissexto\n");
    }
    else
    {
        printf("O ano não é bissexto\n");
    }

    return 0;
}