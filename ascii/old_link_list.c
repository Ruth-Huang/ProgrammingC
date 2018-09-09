#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define word_len 1024

struct link {
char word[word_len];
int count;
struct link *next;
};

void insert(struct link *head, char word[])
{
	struct link *tail, *ptr;

//	if(head == NULL) head = ptr;

	tail = head;
	if(strcmp(tail->word, word) == 0) {
		tail->count ++;
		return;
	}
	while (tail->next != NULL){
		tail = tail->next;
		if(strcmp(tail->word, word) == 0) { 
		  tail->count ++;
		  return;
		}
	}
	ptr = malloc(sizeof(struct link));
	strcpy(ptr->word, word);
	ptr->count = 1;
	ptr->next = NULL;

	tail->next = ptr;
	return;

}

/*
int main(int argc, char *argv[])
{
struct link *ptr, *head, *tail;

head = NULL;

ptr = malloc(sizeof(struct link));

strcpy(ptr->word, "cat");
ptr->count = 1;
ptr->next = NULL;

head = ptr;

ptr = malloc(sizeof(struct link));
strcpy(ptr->word, "cow");
ptr->count = 2;
ptr->next = NULL;

insert(head, ptr);

ptr = malloc(sizeof(struct link));
strcpy(ptr->word, "sheep");
ptr->count = 3;
ptr->next = NULL;

insert(head, ptr);

ptr = head;
do {
printf("%s  %d \n", ptr->word, ptr->count);
ptr = ptr->next;
} while(ptr != NULL);

}
*/
