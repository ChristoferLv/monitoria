#include <stdio.h>

int main(){
    float val = 0;
    printf("Digite um valor real: ");
    scanf("%f", &val);

    printf("O número com duas casas de precisão é %.2f\n", val);
    printf("A parte inteira do número é %d\n", (int)val);
    printf("A representação do número em notação científica é %e\n", val);
    return 0;
}