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
	struct employee info;
	scanf("%s", info.name);
	scanf("%s", info.ID);
	scanf("%d", &info.money);

	puts("");

	printf("%s\n%s\n%d", info.name, info.ID, info.money);

	return 0;
}