#include <stdio.h>

int main()
{
    int numOriginal = 0, numTemp = 0, digito = 1, numContrario = 0;

    printf("Digite um número para a verificação: ");
    scanf("%d", &numOriginal);

    if ((numOriginal / 10) == 0)
    {
        printf("O número é palíndromo!");
        return 0;
    }

    numTemp = numOriginal;
    digito = numTemp % 10;
    while (digito != 0)
    {
        numContrario = (numContrario * 10) + digito;
        numTemp = numTemp / 10;
        digito = numTemp % 10;
    }

    if (numContrario == numOriginal)
    {
        printf("O número digitado é palíndromo");
    }
    else
    {
        printf("O número digitado não é palíndromo");
    }

    return 0;
}