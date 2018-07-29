#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

int x, i;
char word[10][10];
strcpy(word[0], "The");
strcpy(word[1], "Google");
strcpy(word[2], "search");
strcpy(word[3], "is");
strcpy(word[4], "cool");

//fgets(str, 100, 0);
//x = strcmp(b, a);
for (i=0; i<5; i++){
    printf("%s ", word[i]);
}
printf("\n");

exit(0);
} 
