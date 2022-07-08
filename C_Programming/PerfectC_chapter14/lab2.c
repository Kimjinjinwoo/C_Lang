#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct book
{
	char title[50];
	char author[50];
	int ISBN;
} book;

void input(book*);
void print(book*);


int main()
{
	book python;
	input(&python);
	print(&python);
}

void input(book* pp)
{
	gets((*pp).title);
	gets((*pp).author);
	scanf("%d", &(*pp).ISBN);
}

void print(book* b)
{
	printf("제목: %s, ", b->title);
	printf("저자: %s, ", b->author);
	printf("ISBN: %d \n", b->ISBN);
}