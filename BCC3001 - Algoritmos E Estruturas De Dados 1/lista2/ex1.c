#include <stdio.h>

int file_exists(const char *filepath)
{
    FILE *pFile;
    pFile = fopen(filepath, "r");
    if (pFile != NULL)
    {
        fclose(pFile);
        return 1;
    }
    return 0;
}

int main()
{
    int resultado = -1;
    resultado = file_exists("C:\\laragon\\teste.txt");
    printf("%d", resultado);
    return 0;
}