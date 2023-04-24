#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pop(int* , int* , int* );
void push(int, int*, int*, int*);

int main() {
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);
	
	int queue[20] = { -1 };
	int front = 0, rear = 0;

	int tree[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	fscanf(fr, "%d", &tree[1]);
	push(1, queue, &front, &rear);
	int num_of_node = 1;
	int conti = 1;
	while(conti == 1) {
		int idx = pop(queue, &front, &rear);

		for (int jj = 0; jj < 2; jj++) {
			int data;
			fscanf(fr, "%d", &data);
			if (data == -1) {
				continue;
			}
			else {
				tree[idx * 2 + jj] = data;
				push(idx * 2 + jj, queue, &front, &rear);
				num_of_node++;
				if (num_of_node == n) {
					conti = 0;
					break;
				}
			}
		}
	}
	fclose(fr);

	for (int ii = 0; ii < 16; ii++) {
		printf("%d ", tree[ii]);
	}
}

void push(int data, int* queue, int* front, int* rear) {
	queue[*rear] = data;
	*rear += 1;
}

int pop(int* queue, int* front, int* rear) {
	int data = queue[*front];
	*front += 1;
	return data;
}