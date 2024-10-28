#include <stdio.h>

int main(){
    int num = 0;
    printf("Digite um número para ser escrito por extenso: ");
    scanf("%d", &num);
    
    if(num < 0 || num > 9){
        printf("Número inválido\n");
        return 0;
    }

    if(num == 0){
        printf("Zero\n");
    }else if(num == 1){
        printf("Um\n");
    }else if(num == 2){
        printf("Dois\n");
    }else if(num == 3){
        printf("Três\n");
    }else if(num == 4){
        printf("Quatro\n");
    }else if(num == 5){
        printf("Cinco\n");
    }else if(num == 6){
        printf("Seis\n");
    }else if(num == 7){
        printf("Sete\n");
    }else if(num == 8){
        printf("Oito\n");
    }else if(num == 9){
        printf("Nove\n");
    }
    
    return 0;
}