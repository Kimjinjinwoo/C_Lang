#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct point
{
	int xpos;
	int ypos;
} Point;

void SwapPoint(Point*, Point*);

int main(void)
{
	Point pos1 = { 2,4 };
	Point pos2 = { 5,7 };

	SwapPoint(&pos1, &pos2);

	printf("%d %d \n", pos1.xpos, pos1.ypos);
	printf("%d %d \n", pos2.xpos, pos2.ypos);

	return 0;

}

void SwapPoint(Point* ptr_pos1, Point* ptr_pos2)
{
	Point temp = *ptr_pos1;
	*ptr_pos1 = *ptr_pos2;
	*ptr_pos2 = temp;
}