#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void inorder(char* tree, int link[21][2], int idx);
void preorder(char* tree, int link[21][2], int idx);
void postorder(char* tree, int link[][2], int idx);
char get_c(FILE** fr);
int pop(int*, int*, int*);
void push(int, int*, int*, int*);

int queue[21];
int front = 0, rear = 0;

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);
	char tree[21];
	int link[21][2];

	for (int ii = 0; ii < 21; ii++) {
		tree[ii] = 'N';
		link[ii][0] = -1;
		link[ii][1] = -1;
	}

	int idx = 1;
	int k = 0;
	char C;
	C = get_c(&fr);

	tree[idx] = C;
	push(idx, queue, &front, &rear);
	idx++; k++;

	while (k < n) {
		int mom_idx = pop(queue, &front, &rear);

		C = get_c(&fr);
		tree[idx] = C;
		push(idx, queue, &front, &rear);
		if (C != 'N'){
			link[mom_idx][0] = idx;
			idx++; k++;
		}
		
		if (k == n)
			break;

		C = get_c(&fr);
		tree[idx] = C;
		push(idx, queue, &front, &rear);
		if (C != 'N') {
			link[mom_idx][1] = idx;
			idx++; k++;
		}
	}


	printf("inorder traversal: "); inorder(tree, link, 1); printf("\n");
	printf("preorder traversal: "); preorder(tree, link, 1); printf("\n");
	printf("postorder traversal: "); postorder(tree ,link, 1); printf("\n");
}

void inorder(char* tree, int link[21][2], int idx) {
	if (idx != -1 && tree[idx] != 'N') {
		inorder(tree, link , link[idx][0]);
		printf("%c", tree[idx]);
		inorder(tree, link , link[idx][1]);
	}
}

void preorder(char* tree, int link[21][2], int idx) {
	if (idx != -1 && tree[idx] != 'N') {	
		printf("%c", tree[idx]);
		preorder(tree, link, link[idx][0]);
		preorder(tree, link, link[idx][1]);
	}
}

void postorder(char* tree, int link[][2], int idx) {
	if (idx != -1 && tree[idx] != 'N') {
		postorder(tree, link, link[idx][0]);
		postorder(tree, link, link[idx][1]);
		printf("%c", tree[idx]);	
	}
}

int pop(int* queue, int* front, int* rear) {
	(*front)++;
	return queue[(*front) - 1];
}

void push(int data, int* queue, int* front, int* rear) {
	queue[(*rear)] = data;
	(*rear)++;
}

char get_c(FILE** fr) {
	while (1) {
		char C;
		fscanf(*fr, "%c", &C);
		if (C == ' ' || C == '\n') {
			continue;
		}
		return C;
	}
}