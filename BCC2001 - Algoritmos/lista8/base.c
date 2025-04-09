#include <stdio.h>
#include <string.h>

void removeSpecial(char text[]) {
    size_t i, j = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) || text[i] == ' ') {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';
}


void removeInterSpaces(char text[])
{ //"Um      texto     ."
    size_t tam = strlen(text);
    char temp[tam];
    size_t tempIndex = 0;
    size_t space = 0;
    for (size_t i = 0; i < tam; i++)
    {
        if(text[i] == ' ' && space){
            continue;
        }else if(text[i] == ' '){
            space = 1;
            temp[tempIndex] = ' ';
            tempIndex++;
        }else{
            space = 0;
            temp[tempIndex] = text[i];
            tempIndex++;
        }
    }
    int i = 0;
    strcpy(text,temp);
}

int main()
{
    char texto[] = "JoHn Doe SILVA";
    removeInterSpaces(texto);
    printf("|%s|", texto);
    return 0;
}