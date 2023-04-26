#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void inorder(char* tree, int idx);
void preorder(char* tree, int idx);
void postorder(char* tree, int idx);


int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);
	char tree[21];
	for (int ii = 0; ii < 21; ii++) {
		
		tree[ii] = 'N';
	}

	int idx = 1;
	int k = 0;
	while (k < n) {
		char C;
		fscanf(fr, "%c", &C);
		if (C == ' ' || C == '\n') {
			continue;
		}
		tree[idx] = C;
		if (tree[idx] != 'N') {
			k++;
		}
		idx++;
	}
	printf("inorder traversal: "); inorder(tree, 1); printf("\n");
	printf("preorder traversal: "); preorder(tree, 1); printf("\n");
	printf("postorder traversal: "); postorder(tree, 1); printf("\n");
}

void inorder(char* tree, int idx) {
	if (idx < 21 && tree[idx] != 'N') {
		inorder(tree, idx * 2);
		printf("%c", tree[idx]);
		inorder(tree, idx * 2 + 1);
	}
}

void preorder(char* tree, int idx){
	if (idx < 21 && tree[idx] != 'N') {
		printf("%c", tree[idx]);
		preorder(tree, idx * 2);
		preorder(tree, idx * 2 + 1);
	}
}

void postorder(char* tree, int idx) {
	if (idx < 21 && tree[idx] != 'N') {
		postorder(tree, idx * 2);
		postorder(tree, idx * 2 + 1);
		printf("%c", tree[idx]);
	}
}