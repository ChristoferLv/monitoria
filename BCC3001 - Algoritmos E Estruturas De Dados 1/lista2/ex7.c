#include <stdio.h>
#include <string.h>

int save_lines(const char *filepath, int n, char* text_lines[n])
{
    FILE *pFile;
    pFile = fopen(filepath, "a");
    char* line = "\n";
    if (!pFile)
        return 0;
    for (int i = 0; i < n; i++)
    {
        fputs(text_lines[i], pFile);
        fputs(line, pFile);
    }

    return 1;
}

int main()
{
    int resultado = -1;
    char* texto[] = {"sds", "bsdf", "dsdfaf"};
    resultado = save_lines("C:\\laragon\\teste2.txt", 3, texto);

    printf("%d", resultado);
    return 0;
}