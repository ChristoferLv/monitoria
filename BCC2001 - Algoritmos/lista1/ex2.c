#include <stdio.h>

int main(){
    int a = 0, b = 0;
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    printf("A soma dos números é: %d\n", a + b);
    printf("A subtração dos números é: %d\n", a - b);

    return 0;
}