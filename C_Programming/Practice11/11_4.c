#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
	double x;
	double y;
}point;

typedef struct
{
	double slope;
	double yintercept;
}line;

line calFt(point pt1, point pt2)
{
	line k;
	k.slope = (pt2.y - pt1.y) / (pt2.x - pt1.x);
	k.yintercept = pt1.y - k.slope * pt1.x;
	return k;
}

int main(void)
{
	point pt1, pt2;

	scanf("%lf %lf", &pt1.x ,&pt1.y);
	scanf("%lf %lf", &pt2.x, &pt2.y);

	line k = calFt(pt1, pt2);
	printf("%.1lf %.1lf", k.slope, k.yintercept);

	return 0;
}

