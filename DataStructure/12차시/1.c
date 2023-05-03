#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	char data;
	nodePointer left, right;
};

typedef struct queue* queuePointer;
typedef struct queue {
	nodePointer data;
	queuePointer link;
};

char get_char(FILE** fr);
nodePointer InitNode();
void push(nodePointer data, queuePointer* head, queuePointer* tail);
nodePointer pop(queuePointer* head, queuePointer* tail);
void recursive_inorder(nodePointer X);

int main() {
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);

	nodePointer tree = InitNode();
	tree->data = get_char(&fr);

	queuePointer head = malloc(sizeof(queuePointer));
	head->data = tree;
	head->link = NULL;

	queuePointer tail = head;
	int t = 1;
	while (t < n) {
		nodePointer parent = pop(&head, &tail);

		char data;
		// left
		data = get_char(&fr);
		nodePointer new_node = NULL;
		if (data != 'N') {
			t++;
			new_node = InitNode();
			new_node->data = data;
			parent->left = new_node;
		}
		push(new_node, &head, &tail);

		// right
		data = get_char(&fr);
		new_node = NULL;
		if (data != 'N') {
			t++;
			new_node = InitNode();
			new_node->data = data;
			parent->right = new_node;
		}
		push(new_node, &head, &tail);
	}
	printf("recursive implementation of inorder traversal : ");
	recursive_inorder(tree);

	return 0;
}

char get_char(FILE** fr) {
	char x;
	fscanf(*fr, "%c", &x);
	while (x == ' ' || x == '\n') {
		fscanf(*fr, "%c", &x);
	}
	return x;
}

nodePointer InitNode() {
	nodePointer X = malloc(sizeof(nodePointer));
	X->data = 'N';
	X->left = NULL;
	X->right = NULL;
	return X;
}

void push(nodePointer data, queuePointer* head, queuePointer* tail) {
	queuePointer new_node = malloc(sizeof(queuePointer));
	new_node->data = data;
	new_node->link = NULL;
	if (*head == NULL) {
		*head = new_node;
		*tail = *head;
	}
	else {
		(*tail)->link = new_node;
		(*tail) = new_node;
	}
}

nodePointer pop(queuePointer* head, queuePointer* tail) {
	nodePointer data = (*head)->data;
	(*head) = (*head)->link;
	return data;
}

void recursive_inorder(nodePointer X) {
	if (X == NULL) {
		return;
	}
	recursive_inorder(X->left);
	printf("%c", X->data);
	recursive_inorder(X->right);
}


