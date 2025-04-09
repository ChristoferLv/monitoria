#include <stdio.h>
#include <string.h>

void removeInterSpaces(char text[])
{ //"Um      texto     ."
    size_t textTam = strlen(text);
    size_t space = 0;
    size_t totalMoves = 0;
    size_t indexSpace = 0;
    for (size_t i = 0; i < textTam + 1; i++)
    {
        if (indexSpace && text[i] == ' ')
        {
            totalMoves = totalMoves + 1;
        }
        else if (text[i] == ' ')
        {
            indexSpace = i;
        }
        else if (indexSpace)
        {
            if (indexSpace == i)
            {
                continue;
            }
            for (size_t j = i - totalMoves; j < i; j++)
            {
                if (text[j + totalMoves] == '\0')
                {
                    text[j-1] = text[j + totalMoves];
                    return;
                }
                text[j] = text[j + totalMoves];
            }
            for (size_t j = i; j < i + totalMoves; j++)
            {
                text[j] = ' ';
            }
            i = indexSpace + totalMoves;
            indexSpace = 0;
            totalMoves = 0;
        }
    }
}

int main()
{
    char texto[] = "JoHn  Do e  SILVA";
    removeInterSpaces(texto);
    printf("%s", texto);
    return 0;
}