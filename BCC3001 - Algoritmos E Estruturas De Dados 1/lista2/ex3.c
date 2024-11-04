#include <stdio.h>
#include <string.h>

int print_content(const char *filepath)
{
    FILE *pFile;
    pFile = fopen(filepath, "r");
    if (pFile != NULL)
    {
        char* linha;
        while (fgets(linha, 20, pFile) != NULL)
        {
            printf("%s", linha);
        }
        
        fclose(pFile);
        return 1;
    }
    return 0;
}

int main()
{
    int resultado = -1;
    resultado = print_content("C:\\laragon\\teste2.txt");
    printf("%d", resultado);
    return 0;
}