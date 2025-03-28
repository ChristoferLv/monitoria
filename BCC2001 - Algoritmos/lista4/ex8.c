#include <stdio.h>

int main(){
    int linhas = 0;
    int spaces = 0;
    printf("Digite o tamanho da árvore: ");
    scanf("%d", &linhas);
    spaces = linhas;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            if(j < spaces-1){
                printf(" ");
            }else{
                printf("[]");
            }
        }
        spaces = spaces - 1;
        printf("\n");
    }
    
    return 0;
}