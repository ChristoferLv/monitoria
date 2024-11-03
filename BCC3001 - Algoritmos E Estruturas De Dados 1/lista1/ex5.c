#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_string(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *newstr = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    newstr[len1+len2] = '\0';

    for (int i = 0; i < len1; i++)
    {
        newstr[i] = str1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        newstr[len1+i] = str2[i];
    }
    return newstr;
}

int main()
{
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *s3 = concat_string(s1, s2);
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);

    free(s3);
    return 0;
}