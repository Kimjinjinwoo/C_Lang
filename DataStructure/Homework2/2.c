#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
	srand((unsigned int)time(0));
	int list[10];
	for (int ii = 0;ii < 10;ii++) {
		list[ii] = rand() % 25;
	}

	// Count
	int count[5] = { 0 };
	int quo;
	for (int ii = 0; ii < 10;ii++) {
		quo = list[ii] / 5;
		count[quo]++;
	}

	//할당
	int** ptr = (int**)malloc(sizeof(int*) * 5);
	for (int ii = 0; ii < 5;ii++) {
		int cnt = (count[ii]);
		if (cnt) {
			ptr[ii] = (int*)malloc(sizeof(int) * cnt);
		}
		else {
			ptr[ii] = (int*)malloc(sizeof(int) * cnt);
			ptr[ii][0] = -1;
		}
	}

	//대입
	int new_count[5] = { 0 };
	for (int ii = 0; ii < 10;ii++) {
		quo = list[ii] / 5;
		ptr[quo][new_count[quo]] = list[ii];
		new_count[quo]++;
	}

	//출력
	int sum, first;
	for (int ii = 0; ii < 5; ii++) {
		printf("arr[%d] = ", ii);
		first = ptr[ii][0];
		sum = first;
		if (first == -1) {
			printf("0");
			continue;
		}
		else {
			printf("%d ", first);
			for (int jj = 1; jj < count[ii];jj++) {
				printf("+ %d ", ptr[ii][jj]);
				sum += ptr[ii][jj];
			}
			printf("= %d\n", sum);
		}
		
	}


}