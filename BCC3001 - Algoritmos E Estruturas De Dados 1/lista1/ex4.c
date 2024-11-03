#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy_reverse(const char *str)
{
    int len = strlen(str);
    char *newstr = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++)
    {
        newstr[len - i - 1] = str[i];
    }
    newstr[len] = '\0';
    return newstr;
}

int main()
{
    char *s1 = "Hello, World!";
    char *s2 = copy_reverse(s1);
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);


    free(s2);
    return 0;
}