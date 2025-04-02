#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int strTam(char str[]) // Utilizada para o Ex2_2
{
    int tam = 0;
    while (str[tam] != '\0')
    {
        tam = tam + 1;
    }
    return tam;
}

// Escreva uma função que recebe uma string como parâmetro e a imprime na tela, com cada
// caractere separado por um espaço. Você não pode utilizar strlen().
void print_string(char str[]) // Ex1
{
    int idx = 0;
    while (str[idx] != '\0')
    {
        printf("%c ", str[idx]);
        idx = idx + 1;
    }
}
// Escreva uma função que recebe uma string e a imprime ao contrário (da direita para esquerda).
// Faça duas versões da função : (1)utilizando strlen() e(2) não utilizando a função.
void print_string_reversed1(char str[]) // Ex2_1
{
    int size = strlen(str);
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

void print_string_reversed2(char str[]) // Ex2_1
{
    int size = strTam(str);
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

void string_report(char str[]) // Ex3
{
    int numLetras = 0;
    int numDigitos = 0;
    int numChar = 0;
    int tamString = strlen(str);
    for (int i = 0; i < tamString; i++)
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            {
                numLetras = numLetras + 1;
            }
            else if (str[i] >= 48 && str[i] <= 57)
            {
                numDigitos = numDigitos + 1;
            }
            else
            {
                numChar = numChar + 1;
            }
        }
    }
    printf("Numero de caracteres: %d - Numero de digitos: %d - Numero de caracteres especiais: %d", numLetras, numDigitos, numChar);
}

void string_to_upper(char str[]) // Ex4
{
    int tamString = strlen(str);
    for (int i = 0; i < tamString; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
    }
}

int strcmp_plus(const char s1[], const char s2[]) // Ex5
{
    char str1[50];
    char str2[50];
    strcpy(str1, s1);
    strcpy(str2, s2);
    size_t str1Tam = strlen(str1);
    size_t str2Tam = strlen(str2);
    string_to_upper(str1);
    string_to_upper(str2);
    size_t idx = 0;
    while (idx <= str1Tam && idx <= str2Tam)
    {
        if (str1[idx] < str2[idx])
        {
            return -1;
        }
        else if (str1[idx] > str2[idx])
        {
            return 1;
        }
        idx = idx + 1;
    }
    if (str1Tam > str2Tam)
    {
        return -1;
    }
    else if (str1Tam < str2Tam)
    {
        return 1;
    }
    return 0;
}

int count_words_plus(const char str[]) // Ex6
{
    size_t strTam = strlen(str);
    size_t numPalavras = 0;
    if (str[0] != ' ')
    {
        numPalavras = numPalavras + 1;
        if (strTam == 1)
            return 1;
    }
    for (size_t i = 1; i < strTam; i++)
    {
        if (str[i] != ' ' && str[i - 1] == ' ')
        {
            numPalavras = numPalavras + 1;
        }
    }
    return numPalavras;
}

void string_capitalize(char str[]) // Ex7
{
    size_t strTam = strlen(str);
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] = str[0] - 32;
    }
    for (size_t i = 1; i < strTam; i++)
    {
        if (str[i - 1] == ' ')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
        else
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
        }
    }
}

int string_compare(const char str1[], const char str2[]) // Ex8
{
    size_t str1Tam = strlen(str1);
    size_t str2Tam = strlen(str2);
    size_t idx = 0;
    while (idx <= str1Tam && idx <= str2Tam)
    {
        if (str1[idx] < str2[idx])
        {
            return -1;
        }
        else if (str1[idx] > str2[idx])
        {
            return 1;
        }
        idx = idx + 1;
    }
    if (str1Tam > str2Tam)
    {
        return -1;
    }
    else if (str1Tam < str2Tam)
    {
        return 1;
    }
    return 0;
}

void string_count(const char str[]) // Ex9
{
    char ocorrencias[26] = {0};
    size_t strSize = strlen(str);
    for (size_t i = 0; i < strSize; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            ocorrencias[str[i] - 'a'] = ocorrencias[str[i] - 'a'] + 1;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            ocorrencias[str[i] - 'A'] = ocorrencias[str[i] - 'A'] + 1;
        }
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (ocorrencias[i] != 0)
        {
            printf("%c: %d - %d%% | ", (char)('A' + i), ocorrencias[i], ocorrencias[i] * 100 / 26);
        }
    }
    printf("\n");
}

void string_trim(char str[]) // Ex10
{
    size_t strSize = strlen(str);
    size_t spacesCount = 0;
    for (int i = strSize - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            str[i + 1] = '\0';
            break;
        }
    }

    while (spacesCount < strSize && str[spacesCount] == ' ')
    {
        spacesCount = spacesCount + 1;
    }

    strSize = strlen(str);

    if (spacesCount > 0)
    {
        for (size_t i = 0; i < strSize - spacesCount + 1; i++)
        {
            str[i] = str[i + spacesCount];
        }
    }
}

int find_substring(const char str[], const char sub[]) // Ex11
{
    size_t idx = 0;
    size_t strSize = strlen(str);
    for (size_t i = 0; i < strSize; i++)
    {
        if (str[i] == sub[idx])
        {
            idx = idx + 1;
            if (sub[idx] == '\0')
            {
                return 1;
            }
        }
        else
        {
            idx = 0;
        }
    }
    return 0;
}

void cut_string(char str[], const char word[]) // Ex12
{
    size_t idx = 0;
    size_t strSize = strlen(str);
    for (size_t i = 0; i < strSize; i++)
    {
        if (str[i] == word[idx])
        {
            idx = idx + 1;
            if (word[idx] == '\0')
            {
                for (size_t j = i + 1; j < strSize; j++)
                {
                    str[j] = '\0';
                }
                return;
            }
        }
        else
        {
            idx = 0;
        }
    }
    return;
}

void int_to_string(int number, char converted[]) // Ex13
{
    size_t idx = 0;
    size_t remainder = 0;
    if (number == 0)
    {
        converted[idx] = '0';
        idx = idx + 1;
        converted[idx] = '\0';
    }
    while (number != 0)
    {
        remainder = number % 10;
        converted[idx] = '0' + remainder;
        idx = idx + 1;
        number = number / 10;
    }
    converted[idx] = '\0';
    int temp = 0;
    for (int i = 0; i < idx / 2; i++)
    {
        temp = converted[i];
        converted[i] = converted[idx - 1 - i];
        converted[idx - 1 - i] = temp;
    }
}

int string_to_int(const char number_str[]) // Ex14
{
    size_t tam = strlen(number_str);
    size_t result = 0;
    size_t power = round(pow(10,tam-1));
    for (size_t i = 0; i < tam; i++)
    {
        result = result + (number_str[i] - '0') * power;
        power = power / 10;
    }

    return result;
}

int main()
{
    char texto[] = "Teste22";
    print_string(texto);
    printf("\n");
    print_string_reversed1(texto);
    printf("\n");
    print_string_reversed2(texto);
    printf("\n");
    string_report(texto);
    printf("\n");
    string_to_upper(texto);
    printf("%s", texto);
    printf("\n");

    char textoParaCmp1[] = "aAbcde";
    char textoParaCmp2[] = "aAbcdE";
    printf("%d\n", strcmp_plus(textoParaCmp1, textoParaCmp2));

    char s[] = " first things first,  second   things   latter   ";
    printf("%d\n", count_words_plus(s)); // saída: 6

    char s2[] = "welCOME To COMPUTER programming !!";
    string_capitalize(s2);
    printf("%s\n", s2); // saída: Welcome To Computer Programming!!

    printf("%d\n", string_compare(textoParaCmp1, textoParaCmp2));

    char s3[] = "Hello World of Software Development";
    string_count(s3);

    char s4[] = "   hello world   ";
    string_trim(s4);
    printf("|%s|\n", s4); // saída: “hello world”

    char s5[] = "first things first, second things latter";
    int check = find_substring(s5, "second");
    printf("%d\n", check);

    char s6[] = "first things first, second things latter";
    cut_string(s6, "second");
    printf("%s\n", s6); // s = “first things first, second”

    char num[11];
    int_to_string(123456, num);
    printf("%s\n", num); // saída: “512” (string)

    int n = string_to_int("22343030"); // n = 1024
    printf("%d", n);
    return 0;
}