#include <stdio.h>

int main(){
    char* cell = "[]";
    int rows = 0;
    int cols = 0;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &rows);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%s ", cell);
        }
        printf("\n");
    }
    
    return 0;
}