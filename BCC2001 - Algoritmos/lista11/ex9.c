#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_content(const char *file_path)
{                                       // Faz a leitura de conteúdo de texto de arquivo
    FILE *file = fopen(file_path, "r"); // para um vetor alocado em heap
    if (!file)
        return NULL;
    int str_size = 50;
    char *str = malloc(str_size * sizeof(char)); // aloca array de char para texto do arquivo
    str[0] = 0;                                  // string vazia, com NULL na primeira posição
    char buffer[20];
    int buffer_counter = 0;
    while (fgets(buffer, 20, file) != NULL)
    { // lê trechos de 19 chars do arquivo
        buffer_counter += strlen(buffer);
        if (buffer_counter >= str_size)
        { // se não cabe no vetor, realoca
            str_size += buffer_counter;
            char *new_str = realloc(str, str_size * sizeof(char));
            if (!new_str)
                break;
            str = new_str;
        }
        strcat(str, buffer); // concatena na string resultante
    }
    fclose(file);
    return str;
}

char **split(const char *str, int *n)
{
    int numWords = 0;
    char currentChar = str[0];
    int sep = 0;
    int k = 0;
    while (currentChar != '\0')
    {
        if (currentChar == ' ' || currentChar == '\n')
        {
            sep = 1;
        }

        if (currentChar != ' ' && currentChar != '\n')
        {
            if (sep == 1)
            {
                numWords = numWords + 1;
                sep = 0;
            }
        }
        currentChar = str[++k];
    }
    if (sep == 0 && currentChar == '\0')
    {
        numWords = numWords + 1;
    }

    
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
        if (currentChar == ' ' || currentChar == '\n')
        {
            if (sep == 0)
            {
                end = k;
                char *temp = malloc((end - start + 1) * sizeof(char));
                for (int i = 0; i < end - start + 1; i++)
                {
                    // printf("letra %c\n", str[i]);
                    temp[i] = str[start + i];
                }

                temp[end - start] = '\0';
                words[numWords] = temp;
                // printf("%s\n", temp);
                numWords = numWords + 1;
            }
            sep = 1;
        }

        if (currentChar != ' ' && currentChar != '\n')
        {
            if (sep == 1)
            {
                start = k;
                sep = 0;
            }
        }
        // printf("k-%d, %d-%d\n", k, start, end);
        currentChar = str[++k];
    }
    if (sep == 0 && currentChar == '\0')
    {
        end = k;
        char *temp = malloc((end - start + 1) * sizeof(char));
        for (int i = 0; i < end - start + 1; i++)
        {
            // printf("letra %c\n", str[i]);
            temp[i] = str[start + i];
        }

        temp[end - start] = '\0';
        words[numWords] = temp;
        // printf("%s\n", temp);
        numWords = numWords + 1;
    }
    return words;
}

char **get_words(const char *path, int *words_count)
{
    char *conteudo = get_content(path);
    char **palavras = split(conteudo, words_count);
    printf("{");
    for (int i = 0; i < *words_count; i++)
    {
        printf("\"%s\" ", palavras[i]);
    }
    printf("}\n");
    return palavras;
}

int main()
{
    char **resultado;
    int numPalavras = -1;
    resultado = get_words("C:\\laragon\\teste3.txt", &numPalavras);

    printf("Palavras: %d\n", numPalavras);
    return 0;
}