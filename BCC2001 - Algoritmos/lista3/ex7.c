#include <stdio.h>

int main()
{
    int val = 1, menor = 9999999, maior = -9999999;
    printf("Digite um valor: ");
    scanf("%d", &val);
    while (val != 0)
    {
        if (val < menor)
        {
            menor = val;
        }
        if (val > maior)
        {
            maior = val;
        }
        printf("Digite um valor: ");
        scanf("%d", &val);
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    return 0;
}