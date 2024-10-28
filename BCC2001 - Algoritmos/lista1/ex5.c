#include <stdio.h>

int main(){
    const float PI = 3.141593;
    int graus = 0;
    printf("Conversor de graus para radianos!\n");
printf("Digite o ângulo em graus: \n");
    scanf("%d", &graus);
    printf("O ângulo em radianos é: %f\n", graus * PI / 180);

    return 0;
}