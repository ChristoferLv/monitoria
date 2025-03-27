#include <stdio.h>

int main(){
    int input = 0;
    int sum = 0;
    printf("Digite um número para verificar se é perfeito: ");
    scanf("%d", &input);
    for (int i = 1; i <= (input/2); i++)
    {
        if(input % i == 0){
            sum = sum + i;
        }
    }
    if(input == sum){
        printf("O número %d é perfeito.", input);
    }else{
        printf("O número %d não é perfeito.", input);
    }
    
    return 0;
}