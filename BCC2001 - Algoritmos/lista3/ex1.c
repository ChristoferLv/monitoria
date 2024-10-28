#include <stdio.h>

int main(){
    int linhas = 0;
    printf("Informe o número de linhas: ");
    scanf("%d", &linhas);

    for (int i = linhas; i > 0; i--)
    {
        printf("Linha %d\n", i);
    }
    

    return 0;
}