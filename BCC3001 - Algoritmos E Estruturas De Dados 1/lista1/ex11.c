#include <stdio.h>
#include <stdlib.h>

char **split(const char *str, int *n)
{
    int numWords = 0;
    char currentChar = str[0];
    int sep = 0;
    int k = 0;
    while (currentChar != '\0')
    {
        if (currentChar == ' ')
        {
            sep = 1;
        }

        if (currentChar != ' ')
        {
            if (sep == 1)
            {
                numWords = numWords + 1;
                sep = 0;
            }
        }
        currentChar = str[k++];
    }
    printf("%d\n", numWords);
    *n = numWords;

    char **words = malloc(numWords * sizeof(char **));
    currentChar = str[0];
    k = 0;
    sep = 1;
    numWords = 0;
    int start = 0;
    int end = 0;
    while (currentChar != '\0')
    {
        if (currentChar == ' ')
        {
            if (sep == 0)
            {
                end = k;
                char *temp = malloc((end - start + 1) * sizeof(char));
                for (int i = 0; i < end-start+1; i++)
                {
                    printf("letra %c\n", str[i]);
                    temp[i] = str[start+i];
                }
                
                temp[end-start] = '\0';
                words[numWords] = temp;
                printf("%s\n", temp);
                numWords = numWords + 1;
            }
            sep = 1;
        }

        if (currentChar != ' ')
        {
            if (sep == 1)
            {
                start = k;
                sep = 0;
            }
        }
        printf("k-%d, %d-%d\n", k, start, end);
        currentChar = str[++k];
    }
    return words;
}

int main()
{
    char str[] = " Texto de teste ";

    int size = 0;
    char **tokens = split(str, &size);

    for (int i = 0; i < size; i++)
        printf("%s\n", tokens[i]); // imprime as palavras encontradas
    // libera vetor de strings alocado na heap

    for (int i = 0; i < size; i++)
        free(tokens[i]);

    free(tokens);
    return 0;
}