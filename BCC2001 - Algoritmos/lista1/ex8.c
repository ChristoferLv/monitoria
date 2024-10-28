#include <stdio.h>

int main(){
    int a = 0, b = 0, c = 0;
    int pesoA = 0, pesoB = 0, pesoC = 0;
    printf("Estatísticas com números: ");
    
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o peso do primeiro número: ");
    scanf("%d", &pesoA);

    printf("Digite o segundo número: ");
    scanf("%d", &b);
    printf("Digite o peso do segundo número: ");
    scanf("%d", &pesoB);

    printf("Digite o terceiro número: ");
    scanf("%d", &c);
    printf("Digite o peso do terceiro número: ");
    scanf("%d", &pesoC);

    printf("A média simples dos três numeros é %f\n", (float)(a + b + c) / 3);
    printf("A média ponderada dos três números é %f\n", (float)((pesoA * a) + (pesoB * b) + (pesoC * c)) / (pesoA+pesoB+pesoC));
    

    return 0;
}