#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Area(Rectangle);
void printPt(Rectangle);

typedef struct point
{
	int xpos;
	int ypos;
}Point;

typedef struct Rectangle
{
	Point pos1;
	Point pos2;
}Rectangle;



int main()
{
	Rectangle rec;
	scanf("%d %d", &rec.pos1.xpos, &rec.pos1.ypos);
	scanf("%d %d", &rec.pos2.xpos, &rec.pos2.ypos);

	Area(rec);
	printPt(rec);
}

void Area(Rectangle rec)
{
	int a;
	a = (rec.pos1.xpos - rec.pos2.xpos) * (rec.pos1.ypos, rec.pos2.ypos);
	if (a > 0)
		printf("%d" ,a);
	else
		return printf("%d", (-1) * a ) ;
}

void printPt(Rectangle rec)
{
	printf("[%d %d]\n", rec.pos1.xpos, rec.pos2.ypos);
	printf("[%d %d]\n", rec.pos1.xpos, rec.pos1.ypos);
	printf("[%d %d]\n", rec.pos2.xpos, rec.pos2.ypos);
	printf("[%d %d]\n", rec.pos2.xpos, rec.pos1.ypos);
}