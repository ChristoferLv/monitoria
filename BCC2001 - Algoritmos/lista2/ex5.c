#include <stdio.h>

int main(){
    float n1 = 0, n2 = 0, n3 = 0, media = 0;
    printf("Digite as notas no intervalor 0 e 10\n");
    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    media = (n1 + n2 + n3) / 3;
    printf("A média é: %.2f.\n", media);

    printf("Conceito: ");
    if(media >= 8.5){
        printf("A");
    }else if (media >= 7.0){
        printf("B");
    }else if (media >= 5.5){
        printf("C");
    }else{
        printf("F");
    }


    return 0;
}