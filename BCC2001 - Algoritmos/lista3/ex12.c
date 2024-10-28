#include <stdio.h>

int main()
{
    int num = 0, primo = 1;
    printf("Digite um número para verificar se ele é primo: ");
    scanf("%d", &num);

    for (int i = 2; i < (num / 2) + 1; i++)
    {
        if ((num % i) == 0)
        {
            primo = 0;
        }
    }

    if (primo == 1)
    {
        printf("O número digitado é primo!");
    }
    else
    {
        printf("O número digitado não é primo!");
    }

    return 0;
}