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

nodePointer init_node(int data);
void dfs(nodePointer X);
void pre_order(nodePointer);
void post_order(nodePointer);
void in_order(nodePointer);
void push(nodePointer data, queuePointer* front, queuePointer* rear);
nodePointer pop(queuePointer* front, queuePointer* rear);

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
	while(ii < n){
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
	in_order(root); printf("\n");

	printf("preorder traversal: ");
	pre_order(root); printf("\n");

	printf("postorder traversal: ");
	post_order(root); printf("\n");
	return 0;
}

nodePointer init_node(int data) {
	nodePointer new_node = malloc(sizeof(nodePointer)*10);
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

void in_order(nodePointer X) {
	if (X == NULL) return;
	in_order(X->left);
	printf("%c", X->data);
	in_order(X->right);

}


void pre_order(nodePointer X) {
	if (X == NULL) return;
	printf("%c", X->data);
	pre_order(X->left);
	pre_order(X->right);
}

void post_order(nodePointer X) {
	if (X == NULL) return;
	post_order(X->left);
	post_order(X->right);
	printf("%c", X->data);
}


void push(nodePointer data, queuePointer* front, queuePointer* rear) {
	queuePointer new_node = malloc(sizeof(queuePointer)*10);
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