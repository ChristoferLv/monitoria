#include <stdio.h>
#include <string.h>

int append_string(const char *filepath, const char* text)
{
    FILE *pFile;
    pFile = fopen(filepath, "a");
    if (!pFile)
        return 0;
   fputs(text, pFile);
   return 1;
}

int main()
{
    int resultado = -1;
    char *texto = "Um texto para ser adicionado";
    resultado = append_string("C:\\laragon\\teste2.txt", texto);

    printf("%d", resultado);
    return 0;
}