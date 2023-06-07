#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	int height;
	nodePointer left;
	//nodePointer right;
}node_;

node_ X = { 0, 0, NULL};
nodePointer A = &X;

nodePointer node_init();
nodePointer Node(int data, int height);
int get_height(nodePointer X);
nodePointer add_item(nodePointer X, int data);

nodePointer root;

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	//int n; fscanf(fr, "%d", &n);
	int n = 6;

	//int data; fscanf(fr, "%d", &data);
	int data = 10;
	printf("%d\n", data);
	root = Node(data, 1);

	for (int ii = 0; ii < (n - 1); ii++) {
		//fscanf(fr, "%d", &data);
		data = ii;
		printf("%d\n", data);
		//root = add_item(root, data);
		node_init();
	}

}

nodePointer node_init() {
	nodePointer new_node = (nodePointer)malloc(sizeof(nodePointer));
	new_node->data = -1;
	new_node->height = -1;

	new_node->left = NULL;
	//new_node->right = (nodePointer)NULL;
	return new_node;
}

nodePointer Node(int data, int height) {
	nodePointer new_node = node_init();
	new_node->data = data;
	new_node->height = height;
	return new_node;
}

int get_height(nodePointer X) {
	if (X == NULL) {
		return 0;
	}
	else {
		return X->height;
	}
}
/*
nodePointer add_item(nodePointer X, int data) {
	if (X == NULL) {
		return Node(data, 1); // ???
	}
	if (X->data > data) {
		X->left = add_item(X->left, data);
	}
	else {
		X->right = add_item(X->right, data);
	}
	int height = get_height(X->left);
	if (height < get_height(X->right))
		height = get_height(X->right);
	X->height = height + 1;
	return X;
}
*/

