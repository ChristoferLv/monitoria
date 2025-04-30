#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Suporte
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

int is_delimiter(char c)
{
    return c == ' ' || c == '\n' || c == '\t' || c == '\0' || ispunct(c);
}

int count_word(const char *filepath, const char *word)
{
    char *texto = get_content(filepath);
    int tamWord = strlen(word);
    int tamText = strlen(texto);
    int acc = 0;
    char *window = malloc(sizeof(char) * (tamWord + 1));
    window[tamWord] = '\0';
    for (size_t i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] == word[0] && (i + tamWord) <= tamText)
        {
            memcpy(window, (texto + i), sizeof(char) * tamWord);
            if (strcmp(window, word) == 0)
            {
                if ((i == 0 || is_delimiter(texto[i - 1])) && is_delimiter(texto[i + tamWord]))
                {
                    acc = acc + 1;
                }
            }
        }
    }
    return acc;
}

int main()
{
    int count = 0;
    count = count_word("text.txt", "forest");
    printf("Ocorrencias: %d", count);
    return 0;
}