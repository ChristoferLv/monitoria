#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

struct contact
{
    int id;
    char name[51];
    char email[51];
    int type;
};
typedef struct contact Contact;

struct employee
{
    char name[50];
    float salary;
    int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};
typedef struct employee Employee;

void print_point(Point p) // Ex1
{
    printf("(%.2f,%.2f)\n", p.x, p.y);
}

float distance2D(Point p1, Point p2) // Ex2
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void distance_vector(int n, Point v[]) // Ex3
{
    for (size_t i = 0; i < n; i += 2)
    {
        printf("%.2f - ", distance2D(v[i], v[i + 1]));
    }
    printf("\n");
}

void random_points(int n, Point v[]) // Ex4
{
    for (size_t i = 0; i < n; i++)
    {
        float rand_number1 = rand() / (float)RAND_MAX * 100 - 50;
        float rand_number2 = rand() / (float)RAND_MAX * 100 - 50;
        v[i].x = rand_number1;
        v[i].y = rand_number2;
    }
}

void nearest_points(int n, Point v[]) // Ex5
{
    Point ponto1;
    Point ponto2;
    float dist = INT_MAX;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (distance2D(v[i], v[j]) < dist)
            {
                dist = distance2D(v[i], v[j]);
                ponto1 = v[i];
                ponto2 = v[j];
            }
        }
    }
    printf("Distância: %.2f, Ponto 1: (%.2f, %.2f), Ponto 2: (%.2f, %.2f)\n", dist, ponto1.x, ponto1.y, ponto2.x, ponto2.y);
}

void print_contact(Contact c, int n, char type_names[n][50]) // Ex6
{
    printf("%d, %s, %s, %s\n", c.id, c.name, c.email, type_names[c.type]);
}

void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50]) // Ex7
{
    for (size_t i = 0; i < n2; i++)
    {
        printf("%s\n", types[i]);
        for (size_t j = 0; j < n1; j++)
        {
            if (list[j].type == i)
            {
                printf("    %d, %s, %s, %s\n", list[j].id, list[j].name, list[j].email, types[list[j].type]);
            }
        }
    }
}

void print_best3(int n, Employee v[n]) // Ex8
{
    int best1 = 0;
    int best2 = 0;
    int best3 = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (v[i].salary > v[best1].salary)
        {
            best3 = best2;
            best2 = best1;
            best1 = i;
            continue;
        }
        if (v[i].salary > v[best2].salary)
        {
            best3 = best2;
            best2 = i;
            continue;
        }
        if (v[i].salary > v[best3].salary)
        {
            best3 = i;
        }
    }
    printf("1: %s, 2: %s, 3: %s\n", v[best1].name, v[best2].name, v[best3].name);
}

void income_report(int n, Employee v[n]) // Ex9
{
    char types[][50] = {"Developer", "Designer", "Manager"};
    float total = 0;
    float temp = 0;
    size_t qtd = 0;
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", types[i]);
        for (size_t j = 0; j < n; j++)
        {
            if (v[j].type == i)
            {
                temp = temp + v[j].salary;
                qtd++;
            }
        }
        printf("    Média: %.2f\n", (temp / qtd));
        total = total + temp;
        temp = 0;
        qtd = 0;
    }
    printf("Total: %.2f, Média Geral: %.2f\n", total, (total / n));
}

//============================================================================ // Ex10
void removeSpecial(char text[])
{
    size_t i, j = 0;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) || text[i] == ' ')
        {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';
}

void removeInterSpaces(char text[])
{ //"Um      texto     ."
    size_t tam = strlen(text);
    char temp[tam + 1];
    size_t tempIndex = 0;
    size_t space = 0;
    for (size_t i = 0; i < tam; i++)
    {
        if (text[i] == ' ' && space)
        {
            continue;
        }
        else if (text[i] == ' ')
        {
            space = 1;
            temp[tempIndex] = ' ';
            tempIndex++;
        }
        else
        {
            space = 0;
            temp[tempIndex] = text[i];
            tempIndex++;
        }
    }
    // copia de volta para text
    for (size_t i = 0; (temp[i] != '\0'); i++)
    {
        text[i] = temp[i];
    }
    text[tempIndex] = '\0';
}

void string_trim(char str[])
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

void string_capitalize(char str[])
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
void fix_name(char name[]) // Ex10
{
    // printf("|%s|\n", name);
    removeSpecial(name);
    // printf("|%s|\n", name);
    string_trim(name);
    // printf("|%s|\n", name);
    removeInterSpaces(name);
    // printf("|%s|\n", name);
    string_capitalize(name);
    // printf("|%s|\n", name);
}
//============================================================================ // Ex10
void createEmail(char email[], char name[])
{
    size_t tam = strlen(name);
    size_t i;
    for (i = 0; i < tam; i++)
    {
        if (name[i] == ' ')
        {
            email[i] = '.'; // Usando '->' para acessar o campo do ponteiro
        }
        else
        {
            email[i] = name[i];
        }
    }
    email[i] = '\0'; // Finaliza a string
    strcat(email, "@mail.br");
}

Contact create_contact(int id, char name[], int type) // Ex11
{
    //printf("------EX11-----\n");
    Contact newContact;
    newContact.id = id;
    newContact.type = type;
    strcpy(newContact.name, name);
    fix_name(newContact.name);
    createEmail(newContact.email, newContact.name);
    return newContact;
}

bool check_name(char *name, char *nameCmp)
{
    // Para evitar modificar a string original, trabalhamos com uma cópia
    char temp_name[51]; // Assumindo que o nome não excederá 50 caracteres + nulo
    strncpy(temp_name, name, sizeof(temp_name) - 1);
    temp_name[sizeof(temp_name) - 1] = '\0';

    char *tok = strtok(temp_name, " ");
    while (tok != NULL)
    {
        if (strcmp(tok,nameCmp) == 0)
            return true;
        tok = strtok(NULL, " ");
    }
    return false;
}

void fill_contact_list(int n, Contact list[n], char names[][18]) // Ex12
{
    srand(time(NULL));
    int id = 1;
    int type = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (check_name(names[i], "Doe"))
            type = 0;
        else
        {
            type = rand() % 4 + 1;
        }
        list[i] = create_contact(id, names[i], type);
        id = id + 1;
    }
}

int find_by_name(int n1, Contact list[n1], int n2, char names[n2][10]) // Ex13
{
    int count = 0;
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < n2; j++)
        {
            if (check_name(list[i].name, names[j]))
            {
                count = count + 1;
            }
        }
    }
    return count;
}

int main()
{
    Point ponto = {1.5675, 2.4353};
    print_point(ponto);

    Point p1 = {-2.0f, 7.5f};
    Point p2 = {5.0f, 12.4f};
    float dist = distance2D(p1, p2);
    printf("Distancia: %.2f\n", dist);

    Point points[] = {{-2.0f, 7.5f}, {5.0f, 12.4f}, {1.5675, 2.4353}, {3.5675, -2.5353}};
    distance_vector(4, points);

    Point points2[3];
    random_points(3, points2);
    print_point(points2[2]);

    nearest_points(4, points);

    char types[5][50] = {"Família", "Amigos", "Trabalho", "Escola", "Outros"};
    Contact c = {1, "John Doe", "john.doe@email.com", 2};
    print_contact(c, 5, types);

    Contact list[] = {
        {1, "Marcus Fenix", "fenix@gow.com", 2},
        {41, "Blue Mary", "mary@ff3snk.net", 0},
        {17, "Barry Burton", "bburton@re.cap", 0},
        {8, "Charlie Nash", "nash@ssz.com", 2},
        {2, "Ada Wong", "wong@re2.net", 4},
        {5, "Chris Redfield", "crfield@re.cap", 0}};
    print_contact_list(6, list, 5, types);

    Employee list2[] = {
        {"Marcus Fenix", 2200.22, 0},
        {"Blue Mary", 1800.32, 1},
        {"Barry Burton", 4783.15, 2},
        {"Charlie Nash", 7689.10, 2},
        {"Ada Wong", 2343.67, 1},
        {"Chris Redfield", 12345.67, 0}};
    print_best3(6, list2);

    income_report(6, list2);

    char name[] = " JoHn! Do5e3 SILVA";
    fix_name(name);
    printf("Ex10|%s|\n", name);

    Contact c2 = create_contact(4, " JoHn! Do5e3 SILVA", 1);
    printf("Created Contact: %d, %s, %s, %d\n", c2.id, c2.name, c2.email, c2.type);

    char names[][18] = {"John Doe", "Marcio Marcus", "Lui Vit", "Mantus Doe", "John Tordesilhas", "Steve Linux", "Steve Notebook"};
    Contact list3[7];
    fill_contact_list(7, list3, names);
    for (size_t i = 0; i < 7; i++)
    {
        printf("Contact: %d, %s, %s, %d\n", list3[i].id, list3[i].name, list3[i].email, list3[i].type);
    }
    printf("\n");

    char names2[5][10] = {"joanna", "John", "mike", "leonor", "Doe"};
    // a chamada abaixo contará os nomes em “list” que contêm ao menos
    // uma das palavras em “names”.
    int count = find_by_name(7, list3, 5, names2);
    printf("Contatos encontrados: %d\n", count);
    return 0;
}