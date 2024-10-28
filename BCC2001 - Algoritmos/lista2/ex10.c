#include <stdio.h>

int main()
{
    char letra = '\0';
    printf("Digite uma letra: ");
    scanf("%c", &letra);

    if (letra >= 97 && letra <= 122)
    {
        letra = letra - 32;
    }
    else if (!(letra >= 65) || !(letra <= 90))
    {
        printf("O caractere digitado não é letra.");
        return 0;
    }

    printf("A letra digitada foi: %c\n", letra);
    return 0;
}