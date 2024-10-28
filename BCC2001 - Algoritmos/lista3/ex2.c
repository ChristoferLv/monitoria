#include <stdio.h>

int main()
{
    printf("DEC   OCT   HEX   CHR\n");
    for (int i = 33; i < 127; i++)
    {
        printf("%d     %o   %0x  %c\n", i, i, i, i);
    }

    return 0;
}