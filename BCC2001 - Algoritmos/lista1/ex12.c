#include <stdio.h>

int main(){
    int dias = 0;
    int restantes = 0;
    int anos = 0;
    int semanas = 0;
    printf("Digite o número de dias para o cálculo: \n");
    scanf("%d", &dias);
    anos = dias / 365;
    restantes = dias % 365;
    semanas = restantes / 7;
    restantes = restantes % 7;
    printf("Dias: %d = %d ano(s), %d semana(s) e %d dia(s)\n", dias, anos, semanas, restantes);
    return 0;
}