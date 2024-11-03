#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copy_string(const char* str)
{
    int len = strlen(str) + 1;
    char *newstr = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        newstr[i] = str[i];
    }
    return newstr;
}

int main()
{
    char *s1 = "Hello, World!";
    char *s2 = copy_string(s1);
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    free(s2);
    return 0;
}