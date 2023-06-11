#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	int loc;
	nodePointer left;
	nodePointer right;
};

typedef struct queue* queuePointer;
typedef struct queue {
	nodePointer data;
	queuePointer link;
};

nodePointer node_init(int data);
void push(nodePointer data, queuePointer* front, queuePointer* rear);
nodePointer pop(queuePointer* front, queuePointer* rear);
void dfs(nodePointer);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);

	queuePointer front = malloc(sizeof(queuePointer));
	front = NULL;
	queuePointer rear = front;

	int data;
	fscanf(fr, "%d", &data);
	nodePointer root = node_init(data, 1);
	push(root, &front, &rear);

	while (front != NULL) {
		nodePointer par_node = pop(&front, &rear);
		//printf("%d\n", par_node->data);
		int loc = par_node->loc;

		int left_data = -1; fscanf(fr, "%d", &left_data);
		if (left_data != -1) {
			printf("%d\n", left_data);
			nodePointer left_node = node_init(left_data, loc*2);
			par_node->left = left_node;
			push(left_node, &front, &rear);
		}

		int right_data = -1; fscanf(fr, "%d", &right_data);
		if (right_data != -1) {
			printf("%d\n", right_data);
			nodePointer right_node = node_init(right_data, loc*2 + 1);
			par_node->right = right_node;
			push(right_node, &front, &rear);
		}
	}
	dfs(root);

	return 0;
}

nodePointer node_init(int data, int loc) {
	nodePointer new_node = malloc(sizeof(nodePointer));
	new_node->data = data;
	new_node->loc = loc;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void push(nodePointer data, queuePointer* front, queuePointer* rear) {
	queuePointer new_node = malloc(sizeof(queuePointer));
	new_node->data = data;
	new_node->link = NULL;

	if (*front == NULL) {
		*front = new_node;
		*rear = new_node;
	}
	else {
		(*rear)->link = new_node;
		(*rear) = new_node;
	}
}

nodePointer pop(queuePointer* front, queuePointer* rear) {
	nodePointer data = (*front)->data;
	(*front) = (*front)->link;
	return data;
}

void dfs(nodePointer X) {
	if (X == NULL) {
		return;
	}
	printf("%dÀ§Ä¡¿¡ %d\n", X->loc, X->data);
	dfs(X->left);
	dfs(X->right);
}