#include <stdio.h>
#include <string.h>

int strTam(char str[]){
    int tam = 0;
    while (str[tam] != '\0')
    {
        tam = tam + 1;
    }
    return tam;
}

void print_string(char str[]){
    int idx = 0;
    while (str[idx] != '\0')
    {
        printf("%c ", str[idx]);
        idx = idx + 1;
    }
    
}

void print_string_reversed(char str[]){
    int size = strlen(str);
    for (int i = size-1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

int main(){
    char *texto = "Teste";
    print_string(texto);
    printf("\n");
    print_string_reversed(texto);
    return 0;
}