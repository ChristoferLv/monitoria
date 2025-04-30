#include <stdio.h>

int check_or_create(const char *filepath)
{
    FILE *pFile;
    pFile = fopen(filepath, "w");
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
    resultado = check_or_create("C:\\laragon\\teste2.txt");
    printf("%d", resultado);
    return 0;
}