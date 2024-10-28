#include <stdio.h>

int main()
{
    int num = 0, milhares = 0, centenas = 0, dezenas = 0, unidades = 0;
    int negativo = 0;
    printf("Digite um número de 0 até 1000 para ser escrito por extenso: ");
    scanf("%d", &num);
    if (num < -9999 || num > 9999)
    {
        printf("Número inválido\n");
        return 0;
    }

    if(num < 0){
        num = num * -1;
        negativo = 1;
    }

    milhares = num / 1000;
    centenas = (num % 1000) / 100;
    dezenas = (num % 100) / 10;
    unidades = num % 10;

    if (milhares != 0)
    {
        if (milhares == 1)
        {
            printf("Um");
        }
        else if (milhares == 2)
        {
            printf("Dois");
        }
        else if (milhares == 3)
        {
            printf("Três");
        }
        else if (milhares == 4)
        {
            printf("Quatro");
        }
        else if (milhares == 5)
        {
            printf("Cinco");
        }
        else if (milhares == 6)
        {
            printf("Seis");
        }
        else if (milhares == 7)
        {
            printf("Sete");
        }
        else if (milhares == 8)
        {
            printf("Oito");
        }
        else if (milhares == 9)
        {
            printf("Nove");
        }
        printf(" mil ");
    }

    if (centenas != 0)
    {
        if (centenas == 1)
        {
            printf("Cento e ");
        }
        else if (centenas == 2)
        {
            printf("Duzentos e ");
        }
        else if (centenas == 3)
        {
            printf("Trezentos e ");
        }
        else if (centenas == 4)
        {
            printf("Quatrocentos e ");
        }
        else if (centenas == 5)
        {
            printf("Quinhentos e ");
        }
        else if (centenas == 6)
        {
            printf("Seiscentos e ");
        }
        else if (centenas == 7)
        {
            printf("Setecentos e ");
        }
        else if (centenas == 8)
        {
            printf("Oitocentos e ");
        }
        else if (centenas == 9)
        {
            printf("Novecentos e ");
        }
    }

    if (dezenas != 0)
    {
        if (dezenas == 1)
        {
            printf("Um");
        }
        else if (dezenas == 2)
        {
            printf("Vinte e ");
        }
        else if (dezenas == 3)
        {
            printf("Trinta e ");
        }
        else if (dezenas == 4)
        {
            printf("Quarenta e ");
        }
        else if (dezenas == 5)
        {
            printf("Cinquenta e ");
        }
        else if (dezenas == 6)
        {
            printf("Sessenta e ");
        }
        else if (dezenas == 7)
        {
            printf("Setenta e ");
        }
        else if (dezenas == 8)
        {
            printf("Oitenta e ");
        }
        else if (dezenas == 9)
        {
            printf("Noventa e ");
        }
    }

    if (dezenas == 1){
        if (unidades == 0)
        {
            printf("Dez");
        }
        else if (unidades == 1)
        {
            printf("Onze");
        }
        else if (unidades == 2)
        {
            printf("Doze");
        }
        else if (unidades == 3)
        {
            printf("Treze");
        }
        else if (unidades == 4)
        {
            printf("Quatorze");
        }
        else if (unidades == 5)
        {
            printf("Quinze");
        }
        else if (unidades == 6)
        {
            printf("Dezesseis");
        }
        else if (unidades == 7)
        {
            printf("Dezessete");
        }
        else if (unidades == 8)
        {
            printf("Dezoito");
        }
        else if (unidades == 9)
        {
            printf("Dezenove");
        }
    }else{
        if (unidades != 0)
        {
            if (unidades == 1)
            {
                printf("Um");
            }
            else if (unidades == 2)
            {
                printf("Dois");
            }
            else if (unidades == 3)
            {
                printf("Três");
            }
            else if (unidades == 4)
            {
                printf("Quatro");
            }
            else if (unidades == 5)
            {
                printf("Cinco");
            }
            else if (unidades == 6)
            {
                printf("Seis");
            }
            else if (unidades == 7)
            {
                printf("Sete");
            }
            else if (unidades == 8)
            {
                printf("Oito");
            }
            else if (unidades == 9)
            {
                printf("Nove");
            }
        }
    }

    if(num == 0){
        printf("Zero");
    }

    if(negativo == 1){
        printf(" negativo");
    }
    
    return 0;
}