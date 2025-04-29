#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <io.h>

// Suporte
typedef struct
{
    int *items;
    size_t count;
    size_t capacity;
} NumArr;

#define da_append(xs, x)                                                               \
    do                                                                                 \
    {                                                                                  \
        if ((xs)->count >= (xs)->capacity)                                             \
        {                                                                              \
            if ((xs)->capacity == 0)                                                   \
                (xs)->capacity = 10;                                                   \
            else                                                                       \
                (xs)->capacity += 19;                                                  \
            (xs)->items = realloc((xs)->items, (xs)->capacity * sizeof(*(xs)->items)); \
        }                                                                              \
                                                                                       \
        (xs)->items[(xs)->count++] = (x);                                              \
    } while (0);

void print_array(int n, const int *v) // Ex3
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("]\n");
}

typedef struct
{
    int id;
    char name[51];
} Movie;

int verify_movies(const char *filepath, Movie *original, int n)
{
    FILE *fp = fopen(filepath, "rb");
    if (!fp)
    {
        perror("Erro ao abrir arquivo para leitura");
        return 0;
    }

    Movie *lidos = malloc(n * sizeof(Movie));
    if (!lidos)
    {
        fclose(fp);
        return 0;
    }
    fseek(fp, 0, SEEK_SET);
    fread(lidos, sizeof(Movie), n, fp);
    fclose(fp);

    for (int i = 0; i < n; i++)
    {
        // printf("|%d-%d||%s - %s|\n",lidos[i].id, original[i].id,lidos[i].name, original[i].name);
        if (lidos[i].id != original[i].id || strcmp(lidos[i].name, original[i].name) != 0)
        {
            free(lidos);
            return 0;
        }
    }

    free(lidos);
    return 1; // OK
}

int print_movies(const char *filepath)
{
    FILE *fp = fopen(filepath, "rb");
    if (!fp)
    {
        perror("Erro ao abrir arquivo para leitura");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long tamanho_bytes = ftell(fp);
    int numFilmes = (tamanho_bytes / sizeof(Movie));

    Movie *lidos = malloc(numFilmes * sizeof(Movie));
    if (!lidos)
    {
        fclose(fp);
        return 0;
    }
    fseek(fp, 0, SEEK_SET);
    fread(lidos, sizeof(Movie), numFilmes, fp);
    fclose(fp);

    for (int i = 0; i < numFilmes; i++)
    {
        printf("%d, |%s|\n", lidos[i].id, lidos[i].name);
    }

    return 1; // OK
}

void write_array(const char *filepath, const int *v, int n) // Ex1
{
    FILE *pFile;
    pFile = fopen(filepath, "wb");
    if (pFile == NULL)
        return;

    fwrite(v, sizeof(int), n, pFile);
    fclose(pFile);
    return;
}

int *read_array(const char *filepath, int *n) // Ex2
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

void write_all_movies(const char *filepath, const Movie *list, int n) // Ex3
{
    FILE *pFile;
    pFile = fopen(filepath, "wb");
    if (pFile == NULL)
        return;
    fseek(pFile, 0, SEEK_SET);
    fwrite(list, sizeof(Movie), n, pFile);
    fclose(pFile);
    return;
}

int count_movies(const char *filepath) // Ex4
{
    FILE *pFile;
    pFile = fopen(filepath, "rb");
    if (pFile == NULL)
        return -1;
    fseek(pFile, 0, SEEK_END);
    long tamanho_bytes = ftell(pFile);
    fclose(pFile);
    return (tamanho_bytes / sizeof(Movie));
}

Movie read_movie(const char *filepath, int pos) // Ex5
{
    FILE *pFile;
    Movie movie;
    pFile = fopen(filepath, "rb");
    if (pFile == NULL)
    {
        memset(&movie, 0, sizeof(Movie));
        return movie;
    }
    fseek(pFile, sizeof(Movie) * pos, SEEK_SET);
    size_t tam = count_movies(filepath);
    if (tam == -1 || pos > tam)
    {
        memset(&movie, 0, sizeof(Movie));
        return movie;
    }
    fread(&movie, sizeof(Movie), 1, pFile);
    fclose(pFile);
    return movie;
}

int find_movie(const char *filepath, long id) // Ex6
{
    FILE *pFile;
    Movie movie;
    pFile = fopen(filepath, "rb");
    if (pFile == NULL)
    {
        return -1;
    }
    size_t tam = count_movies(filepath);
    for (size_t i = 0; i < tam; i++)
    {
        fseek(pFile, sizeof(Movie) * i, SEEK_SET);
        fread(&movie, sizeof(Movie), 1, pFile);
        if (movie.id == id)
        {
            return i;
        }
    }
    fclose(pFile);
    return -1;
}

int add_movie(const char *filepath, const Movie *movie) // Ex7
{
    FILE *pFile;
    pFile = fopen(filepath, "ab");
    if (pFile == NULL)
        return 0;
    fseek(pFile, 0, SEEK_END);
    fwrite(movie, sizeof(Movie), 1, pFile);
    fclose(pFile);
    return 1;
}

int update_movie(const char *filepath, const Movie *movie) // Ex8
{
    int pos = find_movie(filepath, movie->id);
    FILE *pFile;
    pFile = fopen(filepath, "r+");
    if (pFile == NULL || pos == -1)
        return 0;
    fseek(pFile, sizeof(Movie) * pos, SEEK_SET);
    fwrite(movie, sizeof(Movie), 1, pFile);
    fclose(pFile);
    return 1;
}

int delete_movie(const char *filepath, long id) // Ex9
{
    int pos = find_movie(filepath, id);
    FILE *pFile;
    pFile = fopen(filepath, "rb+");
    if (pFile == NULL || pos == -1)
        return 0;
    fseek(pFile, sizeof(Movie) * pos, SEEK_SET);
    int val = -1;
    fwrite(&val, sizeof(int), 1, pFile);
    fclose(pFile);
    return 1;
}

int insert_sorted(const char *filepath, const Movie *movie) // Ex10
{
    int numMovies = count_movies(filepath);
    FILE *pFile;
    Movie currMovie;
    int posToAdd = -1;
    pFile = fopen(filepath, "rb+");
    if (pFile == NULL)
    {
        return -1;
    }
    for (size_t i = 0; i < numMovies; i++)
    {
        fseek(pFile, sizeof(Movie) * i, SEEK_SET);
        fread(&currMovie, sizeof(Movie), 1, pFile);
        if (currMovie.id > movie->id)
        {
            posToAdd = i;
            break;
        }
    }
    // Se filme deve ser inserido no final do arquivo
    if (posToAdd == -1)
    {
        fseek(pFile, 0, SEEK_END);
        fwrite(movie, sizeof(Movie), 1, pFile);
        fclose(pFile);
        return 1; // Retorna a posição inserida
    }

    // Se filme deve ser inserido no meio
    Movie *fileMovies = malloc((numMovies - posToAdd) * sizeof(Movie));
    if (!fileMovies)
    {
        fclose(pFile);
        return -1;
    }

    // Lê todos os filmes que serão deslocados
    fseek(pFile, sizeof(Movie) * posToAdd, SEEK_SET);
    fread(fileMovies, sizeof(Movie), (numMovies - posToAdd), pFile);

    // Reposiciona para escrever o filme e os seguintes
    fseek(pFile, sizeof(Movie) * posToAdd, SEEK_SET);
    fwrite(movie, sizeof(Movie), 1, pFile);
    fwrite(fileMovies, sizeof(Movie), (numMovies - posToAdd), pFile);

    free(fileMovies);
    fclose(pFile);
    return posToAdd; // Retorna a posição inserida
}

int defrag(const char *filepath) // Ex11
{
    int numMovies = count_movies(filepath);
    FILE *pFile;
    Movie currMovie;
    int idx = 0;
    NumArr valids = {0};
    pFile = fopen(filepath, "rb+");
    if (pFile == NULL)
    {
        return 0;
    }
    for (size_t i = 0; i < numMovies; i++)
    {
        fseek(pFile, sizeof(Movie) * i, SEEK_SET);
        fread(&currMovie, sizeof(Movie), 1, pFile);
        if (currMovie.id != -1)
        {
            da_append(&valids, i);
        }
    }
    for (size_t i = 0; i < valids.count; i++)
    {
        fseek(pFile, sizeof(Movie) * valids.items[i], SEEK_SET);
        fread(&currMovie, sizeof(Movie), 1, pFile);
        fseek(pFile, sizeof(Movie) * idx, SEEK_SET);
        fwrite(&currMovie, sizeof(Movie), 1, pFile);
        idx = idx + 1;
    }

    int fd = _fileno(pFile);
    _chsize(fd, sizeof(Movie) * valids.count);
    free(valids.items);
    valids.items = NULL;
    valids.count = 0;
    valids.items = 0;
    fclose(pFile);
    return 1; // Retorna a posição inserida
}

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cria arquivo 'dados.bin' com conteúdo de 'v'
    write_array("dados.bin", v, 10);

    int n;
    // lê arquivo 'dados.bin' para 'v'. Preenche o tamanho de 'v' em 'n'.
    int *v2 = read_array("dados.bin", &n);
    print_array(n, v2);
    free(v2);

    Movie list[] = {
        {6, "They Live"},
        {11, "Big Trouble in Little China"},
        {10, "The Thing"},
        {1, "In the Mouth of Madness"},
        {8, "Ghosts of Mars"},
        {23, "Halloween"},
        {7, "Village of the Damned"}};
    // cria arquivo 'dados.bin' com conteúdo de 'list'
    write_all_movies("movies.bin", list, 7);
    printf("Verificação: %d\n", verify_movies("movies.bin", list, 7));

    // considerando o exemplo do exercício anterior
    int size = count_movies("movies.bin"); // size = 7
    printf("Size: %d\n", size);

    // considerando o exemplo do exercício 3
    Movie movie = read_movie("movies.bin", 4); // movie = {8,"Ghosts of Mars "}
    printf("Movie.id: %d, Movie.name: %s\n", movie.id, movie.name);

    // considerando o exemplo do exercício 3
    long pos = find_movie("movies.bin", 23); // pos = 5
    printf("Filme encontrado em: %ld\n", pos);

    Movie newMovie = {18, "Um filne"};
    int result = add_movie("movies.bin", &newMovie);
    printf("Result: %d\n", result);
    long pos2 = find_movie("movies.bin", 18); // pos = 5
    printf("Filme encontrado em: %ld\n", pos2);
    Movie movie2 = read_movie("movies.bin", pos2);
    printf("Movie.id: %d, Movie.name: %s\n", movie2.id, movie2.name);

    Movie updatedMovie = {18, "Um filme"};
    int result2 = update_movie("movies.bin", &updatedMovie);
    printf("Result: %d\n", result2);
    long pos3 = find_movie("movies.bin", 18); // pos = 5
    printf("Filme encontrado em: %ld\n", pos3);
    Movie movie3 = read_movie("movies.bin", pos3);
    printf("Movie.id: %d, Movie.name: %s\n", movie3.id, movie3.name);

    int result3 = delete_movie("movies.bin", 1);
    printf("Result Delete: %d\n", result3);

    Movie newMovie2 = {9, "Um filme ordenado"};
    insert_sorted("movies.bin", &newMovie2);
    print_movies("movies.bin");

    Movie list2[] = {
        {15, "Escape from New York"},
        {3, "Christine"},
        {19, "Prince of Darkness"},
        {5, "Assault on Precinct 13"},
        {17, "Memoirs of an Invisible Man"},
        {22, "Starman"},
        {9, "The Fog"}};
    FILE *temp = fopen("moviesSorted.bin", "wb");
    fclose(temp);
    for (size_t i = 0; i < 7; i++)
    {
        insert_sorted("moviesSorted.bin", &list2[i]);
    }
    for (size_t i = 0; i < 7; i++)
    {
        insert_sorted("moviesSorted.bin", &list[i]);
    }
    // Ordem -> 1 3 5 6 7 8 9 10 11 15 17 19 22 23
    delete_movie("moviesSorted.bin", 1);
    delete_movie("moviesSorted.bin", 7);
    delete_movie("moviesSorted.bin", 10);
    delete_movie("moviesSorted.bin", 15);
    delete_movie("moviesSorted.bin", 23);
    printf("\n\n");
    print_movies("moviesSorted.bin");
    defrag("moviesSorted.bin");
    printf("\n\n");
    print_movies("moviesSorted.bin");
    return 0;
}