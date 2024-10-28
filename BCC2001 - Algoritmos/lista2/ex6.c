#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    printf("Digite 4 números inteiros para checar o maior: ");
    printf("Digite o primeiro número: ");
    scanf("%d", &n1);
    printf("Digite o segundo número: ");
    scanf("%d", &n2);
    printf("Digite o terceiro número: ");
    scanf("%d", &n3);
    printf("Digite o quarto número: ");
    scanf("%d", &n4);

    printf("O maior número é: ");
    if(n1 > n2 && n1 > n3 && n1 > n4){
        printf("%d\n", n1);
    }else if(n2 > n1 && n2 > n3 && n2 > n4){
        printf("%d\n", n2);
    }else if(n3 > n1 && n3 > n2 && n3 > n4){
        printf("%d\n", n3);
    }else{
        printf("%d\n", n4);
    }

    //Outra forma de resolver
    // int maior = -9999999;
    // if(n1 > maior){
    //     maior = n1;
    // }
    // if(n2 > maior){
    //     maior = n2;
    // }
    // if(n3 > maior){
    //     maior = n3;
    // }
    // if(n4 > maior){
    //     maior = n4;
    // }
    // printf("O maior número é: %d", maior);
    
    return 0;
}