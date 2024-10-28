#include <stdio.h>

int main()
{
    int num = 0, primo = 1;
    printf("Digite um número para encontrar os fatores: ");
    scanf("%d", &num);

    for (int i = 2; i < (num / 2) + 1; i++)
    {
        if ((num % i) == 0)
        {
            //Poderia ter usado função aqui
            int primo = 1;
            for (int j = 2; j < i; j++)
            {
                if ((i % j) == 0)
                {
                    primo = 0;
                }
            }
            if (primo)
            {
                printf("Fator %d\n", i);
            }
        }
    }

    return 0;
}