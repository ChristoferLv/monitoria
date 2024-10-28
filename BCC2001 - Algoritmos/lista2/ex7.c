#include <stdio.h>

int main()
{
    int n1 = 0, n2 = 0, n3 = 0;
    printf("ESCREVE NUMEROS EM ORDEM CRESCENTE\n");
    printf("Digite o primeiro número: ");
    scanf("%d", &n1);
    printf("Digite o segundo número: ");
    scanf("%d", &n2);
    printf("Digite o terceiro número: ");
    scanf("%d", &n3);

    printf("A ordem é: ");
    if (n1 < n2)
    {
        // Realiza a troca entre duas variaveis
        n1 = n1 + n2;
        n2 = n1 - n2;
        n1 = n1 - n2;
    }
    if (n2 < n3)
    {
        n2 = n2 + n3;
        n3 = n2 - n3;
        n2 = n2 - n3;
    }
    if (n1 < n2)
    {
        n1 = n1 + n2;
        n2 = n1 - n2;
        n1 = n1 - n2;
    }
    printf("%d %d %d\n", n1, n2, n3);

    // Outra forma de realizar a troca
    //  int temp;
    //  temp = n1;
    //  n1 = n2;
    //  n2 = temp;

    // Outra forma de resolver o problema
    // int maior1 = 0, maior2 = 0, maior3 = 0;
    // if (n1 > n2)
    // {
    //     if (n1 > n3)
    //     {
    //         maior1 = n1;
    //         if (n2 > n3)
    //         {
    //             maior2 = n2;
    //             maior3 = n3;
    //         }
    //         else
    //         {
    //             maior2 = n3;
    //             maior3 = n2;
    //         }
    //     }
    // }
    // else if (n2 > n3)
    // {
    //     maior1 = n2;
    //     if (n1 > n3)
    //     {
    //         maior2 = n1;
    //         maior3 = n3;
    //     }
    //     else
    //     {
    //         maior2 = n3;
    //         maior3 = n1;
    //     }
    // }
    // else
    // {
    //     maior1 = n3;
    //     if (n1 > n2)
    //     {
    //         maior2 = n1;
    //         maior3 = n2;
    //     }
    //     else
    //     {
    //         maior2 = n2;
    //         maior3 = n1;
    //     }
    // }
    // printf("A ordem é: %d %d %d\n", maior1, maior2, maior3);

    return 0;
}