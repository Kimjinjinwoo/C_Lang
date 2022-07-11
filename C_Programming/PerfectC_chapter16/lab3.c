#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student
{
	char dept[40];
	char name[20];
	int sum;
} student;

int main()
{
	student mylab[3];

	FILE* f;

	char fname[] = "student.bin";
	fopen_s(&f, fname, "wb");
	int size = sizeof(mylab) / sizeof(student);
	puts("ภิทยวุ");
	for (int i = 0; i < size; i++)
	{
		scnaf("%s %s %d", mylab[i].dept, mylab[i].name, &mylab[i].sum);
	}

	fwrite(mylab, sizeof(student), size, f);

	fopen_s(&f, fname, "rb");

	student lab[10];

	fread(lab, sizeof(student), size, f);
	for (int i = 0; i < size; i++)
		fprintf("stdout", "%s %s %d\n", lab[i].dept, lab[i].name, lab[i].sum);

	fclose(f);

	return 0;


}