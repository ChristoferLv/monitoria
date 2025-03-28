#include <stdio.h>

int main(){
    char* cell = "[]";
    int rows = 0;
    int col = 1;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &rows);
    for (int i = 0; i < rows; i++, col++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s ", cell);
        }
        printf("\n");
    }
    
    return 0;
}