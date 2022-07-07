#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct MovieData
{
	char title[30];
	char dire[30];
	int year;
	int time;
};

int main(void)
{
	struct MovieData md;

	gets(&md.title);
	gets(&md.dire);
	scanf("%d", &md.year);
	scanf("%d", &md.time);

	printf("Title : %s\n", md.title);
	printf("Director : %s\n", md.dire);
	printf("Year : %d\n", md.year);
	printf("RunningTime : %d\n", md.time);
	return 0;
}