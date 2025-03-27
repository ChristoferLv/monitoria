#include <stdio.h>

int main(){
    int input = 0;
    int result = 0;
    int multpl = 1;
    printf("Digite um número para ser convertido: ");
    scanf("%d", &input);
    while (input > 0)
    {
        if(input%2 == 1){
            result = result + multpl;
        }
        multpl = multpl * 10;
        input = input / 2;
    }
    printf("Número convertido: %d", result);
    return 0;
}