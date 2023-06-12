#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer left;
	nodePointer right;
};

typedef struct queue* queuePointer;
typedef struct queue {
	nodePointer data;
	queuePointer link;
};

typedef struct stack* stackPointer;
typedef struct stack {
	nodePointer data;
	stackPointer link;
};


nodePointer init_node(int data);
void dfs(nodePointer X);
void iterative_pre_order(nodePointer);
void iterative_post_order(nodePointer);
void iterative_in_order(nodePointer);
void push(nodePointer data, queuePointer* front, queuePointer* rear);
nodePointer pop(queuePointer* front, queuePointer* rear);
void stack_push(nodePointer data, stackPointer* top);
nodePointer stack_pop(stackPointer* top);


int main(void) {
	FILE* fr = fopen("input.txt", "r");

	int n; fscanf(fr, "%d", &n);

	queuePointer front = malloc(sizeof(queuePointer));
	front = NULL;
	queuePointer rear = front;

	char raw[20]; fscanf(fr, "%s", &raw);
	int data = raw[0];
	nodePointer root = init_node(data);
	push(root, &front, &rear);
	printf("%c\n\n", front->data);


	int ii = 1;
	while (ii < n) {
		nodePointer par = pop(&front, &rear);

		fscanf(fr, "%s", &raw);
		int left_data = raw[0];
		if (left_data == 'N') {
			push(NULL, &front, &rear);
		}
		else {
			ii++;
			nodePointer left_node = init_node(left_data);
			par->left = left_node;
			push(left_node, &front, &rear);
		}

		fscanf(fr, "%s", &raw);
		int right_data = raw[0];
		if (right_data == 'N') {
			push(NULL, &front, &rear);
		}
		else {
			ii++;
			nodePointer right_node = init_node(right_data);
			par->right = right_node;
			push(right_node, &front, &rear);
		}

	}
	printf("inorder traversal: ");
	iterative_in_order(root); printf("\n");

	printf("preorder traversal: ");
	iterative_pre_order(root); printf("\n");

	printf("postorder traversal: ");
	iterative_post_order(root); printf("\n");
	return 0;
}

nodePointer init_node(int data) {
	nodePointer new_node = malloc(sizeof(nodePointer) * 10);
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void dfs(nodePointer X) {
	if (X == NULL) return;
	printf("%c\n", X->data);
	dfs(X->left);
	dfs(X->right);
}

void iterative_in_order(nodePointer X) {
	stackPointer top = malloc(sizeof(stackPointer));
	top = NULL;

	for (;;) {
		for (; X != NULL; X = X->left) {
			stack_push(X, &top);
		}
		X = stack_pop(&top);
		if (X == NULL) break;
		
		printf("%c", X->data);
		X = X->right;
	}
}

void iterative_pre_order(nodePointer X) {
	stackPointer top = malloc(sizeof(stackPointer));
	top = NULL;

	for (;;) {
		for (; X != NULL; X = X->left) {
			printf("%c", X->data);
			stack_push(X, &top);
		}
		X = stack_pop(&top);
		if (X == NULL) break;
		X = X->right;
		
	}
}

void iterative_post_order(nodePointer X) {
	stackPointer top = malloc(sizeof(stackPointer));
	top = NULL;
	while (1) {
		while (X != NULL) {
			stack_push(X, &top);
			stack_push(X, &top);

			X = X->left;
		}

		if (top != NULL) {
			X = stack_pop(&top);

			if (top != NULL && X == top->data) {
				X = X->right;
			}

			else {
				printf("%c", X->data);
				X = NULL;
			}
		}
		else {
			break;
		}
	}
}


void push(nodePointer data, queuePointer* front, queuePointer* rear) {
	queuePointer new_node = malloc(sizeof(queuePointer) * 10);
	new_node->data = data;
	new_node->link = NULL;
	if (*front == NULL) {
		*front = new_node;
		*rear = new_node;
	}
	else {
		(*rear)->link = new_node;
		*rear = new_node;
	}
}

nodePointer pop(queuePointer* front, queuePointer* rear) {
	nodePointer data = (*front)->data;
	(*front) = (*front)->link;
	return data;
}

void stack_push(nodePointer data, stackPointer* top) {
	stackPointer new_node = malloc(sizeof(stackPointer));
	new_node->data = data;
	new_node->link = *top;
	(*top) = new_node;
}

nodePointer stack_pop(stackPointer* top) {
	if (*top == NULL) return NULL;
	nodePointer data = (*top)->data;
	(*top) = (*top)->link;
	return data;
}