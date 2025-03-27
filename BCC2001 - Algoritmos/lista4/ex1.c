#include <stdio.h>

int main(){
    int input = 0;
    int inverse = 0;
    printf("Digite um número para ser invertido: ");
    scanf("%d", &input);
    while (input != 0)
    {
        inverse = inverse * 10;
        inverse = inverse + (input % 10);
        input = input / 10;
    }
    printf("Número invertido: %d", inverse);
    return 0;
}