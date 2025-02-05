#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if(str1Tam > str2Tam){
        return -1;
    }else if(str1Tam < str2Tam){
        return 1;
    }
    return 0;
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

    char textoParaCmp1[] = "aabcde";
    char textoParaCmp2[] = "aabcde";
    printf("%d\n", strcmp_plus(textoParaCmp1, textoParaCmp2));

    return 0;
}