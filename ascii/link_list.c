#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define word_len 1024

struct link {
char word[word_len];
int count;
struct link *next;
};

void insert(struct link *head, struct link *ptr)
{
	struct link *tail;

//	if(head == NULL) head = ptr;

	tail = head;
	while (tail->next != NULL) tail = tail->next;
	tail->next = ptr;
	return;
}
