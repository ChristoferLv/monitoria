#include <stdio.h>

int main()
{
    printf("DEC    HEX   CHR    DEC    HEX   CHR   DEC    HEX   CHR\n");
    for (int i = 31; i < 64; i++)
    {
        printf("%d     %0x    %c      %d     %0x    %c     %d     %0x    %c\n", i, i, i, i+31, i+31, i+31, i+62, i+62, i+62);
    }

    return 0;
}