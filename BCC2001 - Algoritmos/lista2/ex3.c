#include <stdio.h>

int main(){
    int num = 0;
    printf("Digite um número para a checagem de paridade: ");
    scanf("%d", &num);
    if(num % 2 == 0){
        printf("O número é par\n");
    }else{
        printf("O número é ímpar\n");
    }

    return 0;
}