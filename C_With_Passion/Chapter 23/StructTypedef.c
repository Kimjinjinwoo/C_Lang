#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
};

typedef struct point point;

typedef struct person
{
	char name[20];
	char phoneNum[20];
	int age;
} Person;

int main(void)
{

	point pos = { 10,20 };
	Person man = { "�̽±�" , "010-1212-0001" , 21 };
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);
	return 0;

}