#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct employee
{
	int num;
	char name[30];
	char loca[30];
	int money;
	double incen;
};
typedef struct employee em;

int main(void)
{
	em emList[3];

	for (int i = 0; i < 3; i++)
	{
		char str[20];
		scanf("%d", &(emList[i].num));
		//printf("%d", emList[i].num);

		getchar();
		gets(emList[i].name);
		//printf("%s", emList[i].name);


		gets(emList[i].loca);
		//printf("%s", emList[i].name);

		scanf("%d", &(emList[i].money));
		//printf("%d", emList[i].money);

		scanf("%lf", &(emList[i].incen));
		//printf("%lf", emList[i].incen);
	}

	for (int i = 0; i < 3; i++)
	{

		printf("%d\t%s\t%s\t%d\t%.0lf\%\t%.1lf\n", emList[i].num, emList[i].name, emList[i].loca, emList[i].money, emList[i].incen * 100, (double)emList[i].money * (12 + emList[i].incen));
	}

}