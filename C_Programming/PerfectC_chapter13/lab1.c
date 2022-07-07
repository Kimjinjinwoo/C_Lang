#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct position
{
	double latitude;
	double longitude;
};

int main(void)
{
	struct city
	{
		char name[20];
		struct position place;
	};


	struct city seoul, newyork;
	

	scanf("%s %lf %lf", &seoul.name, &seoul.place.latitude, &seoul.place.longitude);
	scanf("%s %lf %lf", &newyork.name, &newyork.place.latitude, &newyork.place.longitude);


	puts("");
	printf("%s %lf %lf\n", seoul.name, seoul.place.latitude, seoul.place.longitude);
	printf("%s %lf %lf", newyork.name, newyork.place.latitude, newyork.place.longitude);


	return 0;
}