#include <stdio.h>

int main(){
    int num = 0;
    printf("Digite um número para ser calculado seu módulo: ");
    scanf("%d", &num);
    
    if(num < 0){
        num = num * -1;
    }
    printf("O módulo do número é: %d\n", num);

    //Outra forma de resolver
    // if(num < 0){
    //     printf("O módulo do número é: %d\n", -num);
    // }else{
    //     printf("O módulo do número é: %d\n", num);
    // }

    return 0;
}