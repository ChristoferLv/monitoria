#include <stdio.h>

int main(){
    int a = 0, b = 0;
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    printf("O resto com \% é: %d\n", a % b);
    
    // O resto de uma divisão pode ser encontrado por dividendo - (dividendo / divisor) * divisor
    printf("O resto sem \% é: %d\n", (int) a - (int)(a / b) * b);

    return 0;
}