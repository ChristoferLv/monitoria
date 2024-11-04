#include <stdio.h>
#include <string.h>

int count_lines(const char *filepath)
{
    FILE *pFile;
    pFile = fopen(filepath, "r");
    int numLines = 0;
    if (pFile != NULL)
    {
        char ch;
        while ((ch = fgetc(pFile)) != EOF)
        {
            if (ch == '\n')
            {
                numLines = numLines + 1;
            }
        }
        fclose(pFile);
        return numLines + 1;
    }
    return -1;
}

int main()
{
    int resultado = -1;
    resultado = count_lines("C:\\laragon\\teste2.txt");
    printf("%d", resultado);
    return 0;
}