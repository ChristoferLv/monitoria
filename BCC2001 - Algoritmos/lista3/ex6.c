#include <stdio.h>

int main()
{
    int val = 1, acc = 0, qtd = 0;
    printf("Digite um valor: ");
    scanf("%d", &val);
    while (val != 0)
    {
        qtd = qtd + 1;
        acc = acc + val;
        printf("Digite um valor: ");
        scanf("%d", &val);
    }

    printf("Soma: %d\n", acc);
    printf("Média: %f", ((float)acc / qtd));
    return 0;
}