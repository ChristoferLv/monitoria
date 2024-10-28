#include <stdio.h>

int main(){
    int a = 0, b = 0;
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    printf("A multiplicação dos números é: %d\n", a*b);
    printf("A divisão inteira dos números é: %d\n", a/b);
    printf("A divisão float do número é: %f\n", (float)a/b);

    return 0;
}