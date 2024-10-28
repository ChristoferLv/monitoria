#include <stdio.h>

int main(){
    int a = 0, b = 0, c = 0;
    printf("Estatísticas com números: ");
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    printf("Digite o terceiro número: ");
    scanf("%d", &c);
    printf("A média simples dos três numeros é %f\n", (float)(a + b + c) / 3);
    printf("A média ponderada dos três números é %f\n", (float)((1 * a) + (5 * b) + (4 * c)) / 10);
    //Também é possível fazer
    //printf("A média ponderada dos três números é %f\n", (float)((0.1 * a) + (0.5 * b) + (0.4 * c)));

    return 0;
}