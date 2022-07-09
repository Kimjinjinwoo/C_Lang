#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct employee {
	char name[20];
	char ID[20];
	int money;
};

int main(void)
{
	struct employee info[3];
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", info[i].name);
		scanf("%s", info[i].ID);
		scanf("%d", &info[i].money);
		puts("");
	}

	puts("");
	for(int i= 0 ; i<3 ; i++)
		printf("%s\n%s\n%d\n", info[i].name, info[i].ID, info[i].money);

	return 0;
}