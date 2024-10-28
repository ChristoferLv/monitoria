#include <stdio.h>

int main()
{
    char letra = '\0';
    printf("Digite um caractere: ");
    scanf("%c", &letra);

    if ((letra >= 97 && letra <= 122) || letra >= 65 && letra <= 90)
    {
        printf("O caractere digitado é uma letra");
    }
    else if (letra >= 48 && letra <= 57)
    {
        printf("O caractere digitado é um número.");
    }
    else
    {
        printf("O caractere digitado é um símbolo.");
    }
    return 0;
}