#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

float print_point(Point p) // Ex1
{
    printf("(%.2f,%.2f)\n", p.x, p.y);
}

float distance2D(Point p1, Point p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void distance_vector(int n, Point v[])
{
    for (size_t i = 0; i < n; i += 2)
    {
        printf("%.2f - ", distance2D(v[i], v[i + 1]));
    }
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
    return 0;
}