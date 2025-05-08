#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Suporte
typedef struct
{
    char **words;
    size_t count;
    size_t capacity;
} ArrWords;

// Suporte
typedef struct
{
    char *text;
    size_t count;
    size_t capacity;
} Text;

// Suporte
typedef struct
{
    char *text;
    size_t qtd;
} Word_Qtd;

// Suporte
typedef struct
{
    Word_Qtd **words;
    size_t count;
    size_t capacity;
} WordsCount;

#define da_append_WordsArr(arr, item)                                                      \
    do                                                                                     \
    {                                                                                      \
        if ((arr)->count >= (arr)->capacity)                                               \
        {                                                                                  \
            if ((arr)->capacity == 0)                                                      \
                (arr)->capacity = 10;                                                      \
            else                                                                           \
                (arr)->capacity += 10;                                                     \
            (arr)->words = realloc((arr)->words, (arr)->capacity * sizeof(*(arr)->words)); \
        }                                                                                  \
                                                                                           \
        (arr)->words[(arr)->count++] = (item);                                             \
    } while (0);

#define da_append_WordCounter(arr, item)                                                   \
    do                                                                                     \
    {                                                                                      \
        if ((arr)->count >= (arr)->capacity)                                               \
        {                                                                                  \
            if ((arr)->capacity == 0)                                                      \
                (arr)->capacity = 10;                                                      \
            else                                                                           \
                (arr)->capacity += 10;                                                     \
            (arr)->words = realloc((arr)->words, (arr)->capacity * sizeof(*(arr)->words)); \
        }                                                                                  \
                                                                                           \
        (arr)->words[(arr)->count++] = (item);                                             \
    } while (0);

#define da_append(dinText, newText, sizePlus)                                                           \
    do                                                                                                  \
    {                                                                                                   \
        if (((dinText)->count + sizePlus) >= (dinText)->capacity)                                       \
        {                                                                                               \
            (dinText)->capacity = (dinText)->capacity + (dinText)->capacity + sizePlus;                 \
            (dinText)->text = realloc((dinText)->text, (dinText)->capacity * sizeof(*(dinText)->text)); \
        }                                                                                               \
        memcpy((dinText)->text + (dinText)->count, newText, sizePlus);                                  \
        (dinText)->count = (dinText)->count + sizePlus;                                                 \
    } while (0);

char *get_content(const char *file_path)
{                                       // Faz a leitura de conteúdo de texto de arquivo
    FILE *file = fopen(file_path, "r"); // para um vetor alocado em heap
    if (!file)
        return NULL;
    int str_size = 50;
    char *str = malloc(str_size * sizeof(char)); // aloca array de char para texto do arquivo
    str[0] = '\0';                               // string vazia, com NULL na primeira posição
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

char *get_content2(const char *file_path)
{                                       // Faz a leitura de conteúdo de texto de arquivo
    FILE *file = fopen(file_path, "r"); // para um vetor alocado em heap
    if (!file)
        return NULL;
    int str_size = 50;
    char *str = malloc(str_size * sizeof(char)); // aloca array de char para texto do arquivo
    str[0] = ' ';                                // string vazia, com NULL na primeira posição
    str[1] = '\0';                               // string vazia, com NULL na primeira posição
    char buffer[20];
    int buffer_counter = 1;
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

int replacechar(char *str, char orig, char rep)
{
    char *ix = str;
    int n = 0;
    while ((ix = strchr(ix, orig)) != NULL)
    {
        *ix++ = rep;
        n++;
    }
    return n;
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

int replace_word(const char *filepath, const char *old_str, const char *new_str)
{
    char *texto = get_content2(filepath);
    if (old_str == NULL || new_str == NULL || texto == NULL)
        return -1;

    size_t sizeOldWord = strlen(old_str);
    size_t sizeNewWord = strlen(new_str);

    if (sizeOldWord == 0)
        return -1;

    // Cria cópia editável do texto
    size_t sizeText = strlen(texto);
    char *oldText = malloc((sizeText + 1) * sizeof(char));
    if (oldText == NULL)
        return -1;

    strcpy(oldText, texto); // cópia segura
    oldText[sizeText] = '\0';

    Text newText = {0};
    size_t indc = 1;
    size_t pos = 1;
    int subs = 0;

    while ((pos + sizeOldWord) <= sizeText)
    {
        if (oldText[pos] == old_str[0] && is_delimiter(oldText[pos - 1]) && is_delimiter(oldText[pos + sizeOldWord]) && memcmp(oldText + pos, old_str, sizeOldWord) == 0)
        {
            da_append(&newText, oldText + indc, pos - indc);
            da_append(&newText, new_str, sizeNewWord);
            subs++;

            pos += sizeOldWord;
            indc = pos;
        }
        else
        {
            pos++;
        }
    }

    // Adiciona o restante do texto
    da_append(&newText, oldText + indc, sizeText - indc);
    da_append(&newText, "\0", 1);

    FILE *fP = fopen("text2.txt", "w");
    if (fP == NULL)
    {
        free(oldText);
        free(newText.text);
        return -1;
    }

    fputs(newText.text, fP);
    fclose(fP);

    free(oldText);
    free(newText.text);

    return subs;
}

void report_by_chars(const char *filepath)
{
    char *texto = get_content(filepath);
    char *tok = strtok(texto, " \t\n,.!?;:\"()[]{}<>-");
    int quantidades[100] = {0};
    size_t tam = 0;
    while (tok != NULL)
    {
        tam = strlen(tok);
        if (tam < 100)
        {
            quantidades[tam] = quantidades[tam] + 1;
        }
        tok = strtok(NULL, " \t\n,.!?;:\"()[]{}<>-");
    }
    for (size_t i = 0; i < 100; i++)
    {
        if (quantidades[i] != 0)
        {
            printf("Palavras com %d: %d\n", i, quantidades[i]);
        }
    }
    free(texto);
    printf("\n");
}

void count_all_words(const char *filepath)
{
    char *texto = get_content(filepath);
    char *tok = strtok(texto, " \t\n,.!?;:\"()[]{}<>-");
    WordsCount wordsCount = {0};
    size_t i = 0;
    while (tok != NULL)
    {
        for (i = 0; i < wordsCount.count; i++)
        {
            if (strcmp(wordsCount.words[i]->text, tok) == 0)
            {
                // printf("|%s| Encontrada, acrescentando\n");
                wordsCount.words[i]->qtd = wordsCount.words[i]->qtd + 1;
                break;
            }
        }
        if (i == wordsCount.count)
        {
            // printf("|%s| Não encontrada, adicionando ", tok);
            Word_Qtd *newWord_Qtd = malloc(sizeof(Word_Qtd));
            char *newWord = malloc(strlen(tok) + 1);
            strcpy(newWord, tok);
            newWord_Qtd->text = newWord;
            newWord_Qtd->qtd = 1;
            da_append_WordCounter(&wordsCount, newWord_Qtd);
        }
        tok = strtok(NULL, " \t\n,.!?;:\"()[]{}<>-");
    }
    for (size_t i = 0; i < wordsCount.count; i++)
    {
        printf("Existem %d plavas |%s|\n", wordsCount.words[i]->qtd, wordsCount.words[i]->text);
    }
    for (size_t i = 0; i < wordsCount.count; i++)
    {
        free(wordsCount.words[i]->text); // libera a string da palavra
        free(wordsCount.words[i]);       // libera a struct Word_Qtd
    }
    free(wordsCount.words); // libera o array de ponteiros para Word_Qtd
    free(texto);
    printf("\n");
}

char **get_words(const char *filepath, int letters, size_t *numFounds)
{
    char *texto = get_content(filepath);
    char *tok = strtok(texto, " \t\n,.!?;:\"()[]{}<>-");
    size_t founds = 0;
    ArrWords arrWords = {0};
    size_t i = 0;
    while (tok != NULL)
    {
        if (strlen(tok) == letters)
        {
            for (i = 0; i < arrWords.count; i++)
            {
                if (strcmp(arrWords.words[i], tok) == 0)
                {
                    break;
                }
            }
            if (i == arrWords.count)
            {
                char *foundWord = malloc((letters + 1) * sizeof(char));
                strcpy(foundWord, tok);
                foundWord[letters] = '\0';
                founds = founds + 1;
                da_append_WordsArr(&arrWords, foundWord);
            }
        }
        tok = strtok(NULL, " \t\n,.!?;:\"()[]{}<>-");
    }
    *numFounds = founds;
    return arrWords.words;
    free(texto);
    printf("\n");
}

typedef struct
{
    int id;
    char name[51];
    float price;
} Product;

int save_records(const char *filepath, int n, const Product *prods)
{
    FILE *pF = fopen(filepath, "w");
    if (pF == NULL)
        return 0;
    for (size_t i = 0; i < n; i++)
    {
        char *tempName = malloc((strlen(prods[i].name) + 1) * sizeof(char));
        strcpy(tempName, prods[i].name);
        tempName[strlen(prods[i].name)] = '\0';
        replacechar(tempName, ' ', '@');
        fprintf(pF, "%d,%s,%f\n", prods[i].id, prods[i].name, prods[i].price);
        free(tempName);
    }
    return 1;
}

int main()
{
    int count = 0;
    count = count_word("text.txt", "forest");
    printf("Ocorrencias: %d\n\n", count);

    int subs = 0;
    subs = replace_word("text.txt", "fox", "firefox");
    printf("Substituições: %d\n\n", subs);

    report_by_chars("textS.txt");
    printf("\n");
    count_all_words("text.txt");
    printf("\n");

    size_t numPalavras = 0;
    char **palavras = get_words("textS.txt", 3, &numPalavras);
    for (size_t i = 0; i < numPalavras; i++)
    {
        printf("|%s|\n", palavras[i]);
    }
    printf("\n");

    Product products[] = {
        {1, "Arroz", 10.5},
        {4, "Leite", 5.67},
        {7, "Iogurte", 12.70},
        {12, "Chocolate", 3.50}};

    int salvo = 0;
    salvo = save_records("records.csv", 4, products);

    return 0;
}