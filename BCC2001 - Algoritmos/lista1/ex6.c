#include <stdio.h>

int main()
{
    const float PI = 3.141593;
    int raio = 0;
    printf("Medidas de um círculo!\n");
    printf("Digite o raio do círculo: \n");
    scanf("%d", &raio);
    printf("O diâmetro do círculo é %d\n", 2 * raio);
    printf("A circunferência do círculo é %f\n", 2 * PI * raio);
    printf("A área do círculo é %f\n", PI * raio * raio);

    return 0;
}