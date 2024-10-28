#include <stdio.h>

int main(){
    char operador = '\0';
    int a = 0, b = 0;
    
    printf("[ CALCULADORA SIMPLEX ]");
    printf("\n Digite a operação desejada (+ - * / \%): ");
    scanf("%c", &operador);
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    switch(operador){
        case '+':
            printf("\n %d + %d = %d", a, b, a + b);
            break;
        case '-':
            printf("\n %d - %d = %d", a, b, a - b);
            break;
        case '*':
            printf("\n %d * %d = %d", a, b, a * b);
            break;
        case '/':
            printf("\n %d / %d = %.2f", a, b, (float)a / b);
            break;
        case '%':
            printf("\n %d %% %d = %d", a, b, a % b);
            break;
        default:
            printf("\n Operador inválido.");
    }

    return 0;
}