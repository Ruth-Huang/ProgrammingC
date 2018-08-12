#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define word_len  1024

void bubble_sort_words(char word[][word_len], int n)
{
int i, j;
char temp[word_len];

for (j=0; j<n; j++){
    for (i=n-1; i>j; i--)
      if(strcmp(word[i], word[i-1]) < 0){
        strcpy(temp, word[i]);
        strcpy(word[i], word[i-1]);
        strcpy(word[i-1], temp);
    }
}

}

char word[10000][word_len];

int main(int argc, char *argv[])
{

int i, j, min, last_char;
int n;
char temp[word_len];

FILE *f;
 
     f = fopen("cs.txt", "r");
     i = 0;
     // assumes no word exceeds length of 1023
     while (fscanf(f, " %1023s", word[i]) == 1) {
         i = i+1;
         if(i>10000){
                printf("The file is too large\n");
                exit(0);
         }
     }
     n = i;
     for (i=0; i<n; i++) printf("%s ", word[i]);
     printf("\n");

     for(i=0; i<n; i++) {
        last_char = strlen(word[i]) - 1;
	if(word[i][last_char] == ')' || word[i][last_char] == '.' || word[i][last_char] == ',' || word[i][last_char] == ':' || word[i][last_char] == ';') word[i][last_char] = '\0';
     }

     bubble_sort_words(word, n);
     for(i=0; i<n; i++) printf("%s ", word[i]);
           printf("\n");

     exit(0);


strcpy(word[0], "the" );
strcpy(word[1], "google");
strcpy(word[2], "search");
strcpy(word[3], "is");
strcpy(word[4], "cool");
strcpy(word[5], "willow");
strcpy(word[6], "levi");
strcpy(word[7], "melee");
strcpy(word[8], "ethan");
strcpy(word[9], "ruth");

//fgets(str, 100, stdin);
//x = strcmp(b, a);

printf("The min position is %d\n", min);

n = 10;
bubble_sort_words(word, n);

for (int i=0; i<n; i++) printf("%s ",word[i]);
printf("\n");



exit(0);
} 
