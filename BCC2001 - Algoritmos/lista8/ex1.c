#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

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

float print_point(Point p) // Ex1
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
    float temp = 0;
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
    printf("1: %s, 2: %s, 3: %s", v[best1].name, v[best2].name, v[best3].name);
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

    char types2[][50] = {"Família", "Amigo", "Trabalho", "Escola", "Outros"};
    Contact list[] = {
        {1, "Marcus Fenix", "fenix@gow.com", 2},
        {41, "Blue Mary", "mary@ff3snk.net", 0},
        {17, "Barry Burton", "bburton@re.cap", 0},
        {8, "Charlie Nash", "nash@ssz.com", 2},
        {2, "Ada Wong", "wong@re2.net", 4},
        {5, "Chris Redfield", "crfield@re.cap", 0}};
    print_contact_list(6, list, 5, types);

    Employee list2[] = {
        {"Marcus Fenix", 2200.22, 2},
        {"Blue Mary", 1800.32, 0},
        {"Barry Burton", 4783.15, 0},
        {"Charlie Nash", 7689.10, 2},
        {"Ada Wong", 2343.67, 4},
        {"Chris Redfield", 12345.67, 0}};
    print_best3(6, list2);
    return 0;
}