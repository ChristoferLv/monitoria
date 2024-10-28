#include <stdio.h>

int main(){
    int valor = 0;
    printf("Digite o npumero da tabuada valor: ");
    scanf("%d", &valor);
    printf("Tabuada do %d\n", valor);
    printf("%d x  1 = %2d\n", valor, valor * 1);
    printf("%d x  2 = %2d\n", valor, valor * 2);
    printf("%d x  3 = %2d\n", valor, valor * 3);
    printf("%d x  4 = %2d\n", valor, valor * 4);
    printf("%d x  5 = %2d\n", valor, valor * 5);
    printf("%d x  6 = %2d\n", valor, valor * 6);
    printf("%d x  7 = %2d\n", valor, valor * 7);
    printf("%d x  8 = %2d\n", valor, valor * 8);
    printf("%d x  9 = %2d\n", valor, valor * 9);
    printf("%d x 10 = %2d\n", valor, valor * 10);

    return 0;
}