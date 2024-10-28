#include <stdio.h>

int main()
{
    int num = 0;
    int acc = 0;
    printf("Informe o número: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        acc = acc + (2 * i + 1);
        printf("%d ", i + 1);
        if (i + 1 < num)
        {
            printf("+ ");
        }
    }

    printf("= %d", acc);

    return 0;
}