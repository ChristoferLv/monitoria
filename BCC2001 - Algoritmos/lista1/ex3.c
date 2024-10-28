#include <stdio.h>

int main()
{
    int largura = 0, comprimento = 0;
    printf("Digite a largura do retângulo: ");
    scanf("%d", &largura);
    printf("Digite o comprimento do retângulo: ");
    scanf("%d", &comprimento);
    printf("O perímetro do retângulo é: %d\n", (2 * largura + 2 * comprimento));
    printf("A área do retângulo é: %d\n", largura * comprimento);

    return 0;
}