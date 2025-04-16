#include <stdio.h>
#include <string.h>
#include <limits.h>

struct rect
{
    int x, y, width, height; // é possível declarar os campos em uma só linha
};
typedef struct rect Rect;

struct point
{
    int x, y; // é possível declarar os campos em uma só linha
    char symbol;
};
typedef struct point Point;

void print_addrs() // Ex1
{
    char v1;
    int v2;
    size_t v3;
    printf("%p - ", &v1);
    printf("%p - ", &v2);
    printf("%p\n", &v3);
}

void add(int *a, int *b) // Ex2
{
    *a = *a + *b;
}

void print_vector(int n, const int *v) // Ex3
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("]\n");
}

void print_vector_reverse(int n, const int *v) // Ex4
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *((v + n - 1) - i));
    }
    printf("]\n");
}

void get_min_max(int n, const int *v, int *min, int *max) // Ex5
{
    int maior = INT_MIN;
    int menor = INT_MAX;
    for (size_t i = 0; i < n; i++)
    {
        if (*(v + i) > maior)
        {
            maior = *(v + i);
        }
        if (*(v + i) < menor)
        {
            menor = *(v + i);
        }
    }
    *max = maior;
    *min = menor;
}

void print_vector2D(int rows, int cols, const int *v) // Ex6
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("%d ", *(v + (cols * i) + j));
        }
    }
    printf("\n");
}

void make_mirrored(char *str) // Ex7
{
    size_t tam = strlen(str);
    str = str + tam;
    *(str + tam + 1) = '\0';
    *(str) = '|';

    for (size_t i = 1; i < tam + 1; i++)
    {
        *(str + i) = *(str - i);
    }
}

int get_hamming_distance(const char *str1, const char *str2) // Ex8
{
    size_t dist = 0;
    for (size_t i = 0; *(str1 + i) != '\0' || *(str2 + i) != '\0'; i++)
    {
        if (*(str1 + i) != *(str2 + i))
        {
            dist = dist + 1;
        }
    }
    return dist;
}

char *find_most_similar(const char *str, int n, char list[n][50]) // Ex9
{
    size_t most = INT_MAX;
    size_t pos = 0;
    size_t temp = 0;
    for (size_t i = 0; i < n; i++)
    {
        temp = get_hamming_distance(list[i], str);
        if (temp < most)
        {
            most = temp;
            pos = i;
        }
    }
    return list[pos];
}

void print_board(Rect *board) // Ex10
{
    for (size_t i = 0; i < board->y; i++)
    {
        printf("\n");
    }
    for (size_t i = 0; i < board->height; i++)
    {
        for (size_t j = 0; j < board->x; j++)
        {
            printf(" ");
        }
        for (size_t j = 0; j < board->width; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}

void print_board2(Point *point, Rect *board) // Ex11
{
    for (size_t i = 0; i < board->y; i++)
    {
        printf("\n");
    }
    for (size_t i = 0; i < board->height; i++)
    {
        for (size_t j = 0; j < board->x; j++)
        {
            printf(" ");
        }
        for (size_t j = 0; j < board->width; j++)
        {
            if (i == point->y && j == point->x)
            {
                printf("%c", point->symbol);
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void print_board3(Point points[], size_t size, Rect *board) // Ex12
{
    char buffer[board->height][board->width];
    for (size_t i = 0; i < board->height; i++)
    {
        for (size_t j = 0; j < board->width; j++)
        {
            buffer[i][j] = '#';
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        buffer[points[i].x][points[i].y] = points[i].symbol;
    }

    for (size_t i = 0; i < board->y; i++)
    {
        printf("\n");
    }
    for (size_t i = 0; i < board->height; i++)
    {
        for (size_t j = 0; j < board->x; j++)
        {
            printf(" ");
        }
        for (size_t j = 0; j < board->width; j++)
        {
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    print_addrs();

    int a = 3;
    int b = 5;
    add(&a, &b);
    printf("%d\n", a);

    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8};
    print_vector(8, vector);

    print_vector_reverse(8, vector);

    int min = 0;
    int max = 0;
    get_min_max(8, vector, &min, &max);
    printf("Menor: %d - Maior: %d\n", min, max);

    int v[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    print_vector2D(3, 4, (int *)v);

    char name[40] = "John Doe";
    make_mirrored(name);
    printf("%s\n", name); // Saída "John Doe|eoD nhoJ"

    int dist = get_hamming_distance("banana", "cabana");
    printf("Distance: %d\n", dist);

    char words[][50] = {"cabana", "savana", "bacana", "halana"};
    char *most_similar = find_most_similar("banana", 4, words);
    printf("%s\n", most_similar); // "bacana"

    printf("_____________________________________________________\n");
    Rect rect = {5, 5, 10, 10}; // posição 5,5 (x,y) e dimensões 10x10 (width,height)
    print_board(&rect);

    printf("_____________________________________________________\n");
    Rect rect2 = {5, 5, 10, 10}; // posição 5,5 (x,y) e dimensões 10x10 (width,height)
    Point point = {2, 4, 'A'};   // posição 0,0 dentro do tablado
    print_board2(&point, &rect2);

    printf("_____________________________________________________\n");
    Rect rect3 = {5, 5, 10, 10}; // posição 5,5 (x,y) e dimensões 10x10 (width,height)
    Point points2[] = {{0, 0, 'A'}, {2, 7, 'B'}, {9, 9, 'C'}};
    size_t size = 3;
    print_board3(points2, size, &rect3);

    return 0;
}