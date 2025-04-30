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

int main()
{
    char* resultado;
    resultado = get_content("C:\\laragon\\teste2.txt");

    printf("%s", resultado);
    return 0;
}