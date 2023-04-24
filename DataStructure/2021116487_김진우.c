#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer right;
	nodePointer left;
} node;

void insert(nodePointer*, int, int);
void delete(nodePointer*, int);


int main(void) {
	FILE* fr = fopen("input.txt", "r");

	nodePointer header;
	header = (nodePointer)malloc(sizeof(nodePointer));
	header->right = header;
	header->right = header;
	int length = 0;
	while (!feof(fr)) {
		int data;
		fscanf(fr, "%d", &data);
		printf("%d ", data);
		insert(&header, length, data);
		length++;
	}
	printf("\n");
	int conti = 1;

	while (conti == 1) {
		printf("+---------------+\n");
		printf("    1.insert     \n");
		printf("    2.delete     \n");
		printf("    3.reverse    \n");
		printf("    4.lenght     \n");
		printf("    5.exit       \n");
		printf("+---------------+\n");
		int comm;
		int data, idx;
		printf("Menu: ");
		scanf("%d", &comm);
		nodePointer x;
		switch (comm) {
		case 5: conti = 0; break;
		case 4:
			printf("length: %d\n", length); break;
		case 1:
			printf("insert: ");
			scanf("%d %d", &idx, &data);
			printf("result: ");
			insert(&header, idx, data);
			length++;
			x = header->right;
			for (int ii = 0; ii < length; ii++) {
				printf("%d ", x->data);
				x = x->right;
			}
			printf("\n");
			break;
		case 2:
			printf("delete: ");
			scanf("%d", &idx);
			delete(&header, idx);
			length--;

			x = header->right;
			for (int ii = 0; ii < length; ii++) {
				printf("%d ", x->data);
				x = x->right;
			}
			printf("\n");
			break;
		case 3:
			x = header->right;
			int* list = (int*)malloc(sizeof(int) * length);
			for (int ii = 0; ii < length; ii++) {
				list[ii] = x->data;
				x = x->right;
			}
			for (int ii = length-1; ii >=0; ii--) {
				printf("%d ", list[ii]);
			}
			printf("\n");
			break;
		}

	}
	printf("\n");

	return 0;
}

void insert(nodePointer* header, int idx, int data) {
	nodePointer X = *header;
	for (int ii = 0; ii < idx; ii++) {
		X = X->right;
	}
	nodePointer new_node = (nodePointer)malloc(sizeof(nodePointer));
	new_node->data = data;
	new_node->left = X;
	new_node->right = X->right;
	X->right = new_node;
}

void delete(nodePointer* header, int idx) {
	nodePointer X = *header;
	for (int ii = 0; ii < idx - 1; ii++) {
		X = X->right;
	}
	X->right = X->right->right;
}