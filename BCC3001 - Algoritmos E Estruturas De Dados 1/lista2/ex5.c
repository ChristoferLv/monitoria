#include <stdio.h>
#include <string.h>

int save_string(const char *filepath, const char *text)
{
    FILE *pFile;
    pFile = fopen(filepath, "w");
    if (!pFile)
        return 0;
   fputs(text, pFile);
   return 1;
}

int main()
{
    int resultado = -1;
    char *texto = "Um texto para ser escrito";
    resultado = save_string("C:\\laragon\\teste2.txt", texto);

    printf("%d", resultado);
    return 0;
}