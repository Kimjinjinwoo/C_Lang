#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	int height;
	nodePointer left;
	nodePointer right;
	int loc;
};

typedef struct queue* queuePointer;
typedef struct queue {
	nodePointer data;
	queuePointer link;
};

nodePointer node_init();
nodePointer Node(int data, int height);
int get_height(nodePointer X);
nodePointer add_item(nodePointer X, int data);
int bf(nodePointer X);
nodePointer balance(nodePointer X);
void push(nodePointer data, queuePointer* front, queuePointer* rear);
nodePointer pop(queuePointer* front, queuePointer* rear);
void print_topology(nodePointer root);


nodePointer root;

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);

	int data; fscanf(fr, "%d", &data);
	root = Node(data, 1);

	for (int ii = 0; ii < (n - 1); ii++) {
		fscanf(fr, "%d", &data);
		root = add_item(root, data);
	}

	print_topology(root);
}

nodePointer node_init() {
	nodePointer new_node = (nodePointer)malloc(sizeof(nodePointer));
	new_node->data = -1;
	new_node->height = -1;
	new_node->loc = -1;

	new_node->left = NULL;
	new_node->right = (nodePointer)NULL;
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
	return balance(X);
}

nodePointer right_rotate(nodePointer X) {
	nodePointer Lnode = X->left;
	X->left = Lnode->right;
	Lnode->right = X;

	int height = get_height(X->left);
	if (height < get_height(X->right))
		height = get_height(X->right);
	X->height = height + 1;

	height = get_height(Lnode->left);
	if (height < get_height(Lnode->right))
		height = get_height(Lnode->right);
	Lnode->height = height + 1;

	return Lnode;
}

nodePointer left_rotate(nodePointer X) {
	nodePointer Rnode = X->right;
	X->right = Rnode->left;
	Rnode->left = X;

	int height = get_height(X->left);
	if (height < get_height(X->right))
		height = get_height(X->right);
	X->height = height + 1;

	height = get_height(Rnode->left);
	if (height < get_height(Rnode->right))
		height = get_height(Rnode->right);
	Rnode->height = height + 1;

	return Rnode;
}

int bf(nodePointer X) {
	return get_height(X->left) - get_height(X->right);
}

nodePointer balance(nodePointer X) {
	if (bf(X) > 1) {
		if (bf(X->left) < 0) {
			X->left = left_rotate(X->left);
		}
		X = right_rotate(X);
	}

	else if (bf(X) < -1) {
		if (bf(X->right) > 0) {
			X->right = right_rotate(X->right);
		}
		X = left_rotate(X);
	}

	return X;
}

void push(nodePointer data, queuePointer* front, queuePointer* rear) {
	queuePointer new_node = malloc(sizeof(queuePointer));
	new_node->data = data;
	new_node->link = NULL;
	if (*rear != NULL) {
		(*rear)->link = new_node;
	}
	(*rear) = new_node;
	if ((*front) == NULL) {
		*front = *rear;
	}
}

nodePointer pop(queuePointer* front, queuePointer* rear) {
	nodePointer data = (*front)->data;
	(*front) = (*front)->link;
	return data;
}

void print_topology(nodePointer root) {
	FILE* fw = fopen("output.txt", "w");
	queuePointer front = malloc(sizeof(queuePointer));
	front = NULL;
	queuePointer rear = front;
	root->loc = 1;
	push(root, &front, &rear);
	while (front != NULL) {
		nodePointer X = pop(&front, &rear);

		int loc = X->loc;
		fprintf(fw, "CBT %d¹ø ³ëµå = %d   bf = %d\n", loc, X->data, bf(X));

		// left
		nodePointer left = X->left;
		if (left != NULL) {
			left->loc = loc * 2;
			push(left, &front, &rear);

		}

		// right
		nodePointer right = X->right;
		if (right != NULL) {
			right->loc = loc * 2 + 1;
			push(right, &front, &rear);
		}
	}
}