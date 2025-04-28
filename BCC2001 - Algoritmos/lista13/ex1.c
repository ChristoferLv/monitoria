#include <stdio.h>
#include <stdlib.h>

// Suporte
void print_array(int n, const int *v) // Ex3
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("]\n");
}

void write_array(const char *filepath, const int *v, int n)
{
    FILE *pFile;
    pFile = fopen(filepath, "wb");
    if (pFile == NULL)
        return;

    fwrite(v, sizeof(int), n, pFile);
    fclose(pFile);
    return;
}

int *read_array(const char *filepath, int *n)
{
    FILE *pFile;
    pFile = fopen(filepath, "rb");
    if (pFile == NULL)
        return NULL;
    fseek(pFile, 0, SEEK_END);
    long tamanho_bytes = ftell(pFile);
    *n = (tamanho_bytes / sizeof(int));

    int *arr = malloc(tamanho_bytes);
    fseek(pFile, 0, SEEK_SET);
    fread(arr, sizeof(int), *n, pFile);
    fclose(pFile);
    return arr;
}

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cria arquivo 'dados.bin' com conteúdo de 'v'
    write_array("C:\\laragon\\dados.bin", v, 10);

    int n;
    // lê arquivo 'dados.bin' para 'v'. Preenche o tamanho de 'v' em 'n'.
    int *v2 = read_array("C:\\laragon\\dados.bin", &n);
    print_array(n, v2);
    free(v2);
    return 0;
}