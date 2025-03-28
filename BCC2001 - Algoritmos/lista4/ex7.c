#include <stdio.h>

int main(){
    char* cell = "[]";
    char* blanck = "  ";
    int rows = 0;
    int wichCols = 1;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if((rows - j) <= (i+1)){
                printf("%s ", cell);
            }else{
                printf("%s ", blanck);
            }
        }
        printf("\n");
    }
    return 0;
}