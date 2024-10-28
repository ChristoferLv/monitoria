#include <stdio.h>

int main()
{
    int num = 0, dig = 1;
    printf("Digite um número para ser decomposto: ");
    scanf("%d", &num);
    
    if(num == 0){
        printf("0");
    }

    dig = num % 10;
    while (dig != 0)
    {
        printf("%d\n", dig);
        num = num / 10;
        dig = num % 10; 
    }
    
    return 0;
}