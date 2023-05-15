#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nodePointer;
typedef struct node {
	char data;
	nodePointer left, right;
	int node_number;
};

typedef struct queue* queuePointer;
typedef struct queue {
	nodePointer  data;
	queuePointer link;
	
};


void main_print_bfs(nodePointer tree);
void preorder_print(nodePointer tree);
nodePointer pre_to_in(char* preorder, char* inorder);
void push(nodePointer data, queuePointer* front, queuePointer* rear);
nodePointer pop(queuePointer* front, queuePointer* rear);


int main(void) {
	FILE* fr = fopen("input.txt", "r");
	
	char preorder[100];
	char inorder[100];

	fscanf(fr, "preorder sequence : %s\n", preorder);
	fscanf(fr, "inorder sequence : %s", inorder);
	//printf("%s\n\n", inorder);

	nodePointer tree;
	tree = pre_to_in(preorder, inorder);
	//preorder_print(tree);
	main_print_bfs(tree);

	return 0;
}

void main_print_bfs(nodePointer tree) {
	FILE* fw = fopen("output.txt", "w");
	tree->node_number = 1;

	queuePointer front = malloc(sizeof(queuePointer));
	front = NULL;
	queuePointer rear = front;

	push(tree, &front, &rear);
	//printf("...\n");
	while (front != NULL) {
		//printf("이건 되제??  %d\n", front->data->node_number);
		nodePointer mom = pop(&front, &rear);
		fprintf(fw, "%d, ", mom->node_number);
		if (mom->left != NULL) {
			
			mom->left->node_number = mom->node_number * 2;
			push(mom->left, &front, &rear);
			//printf("이건 되제??  %d\n", rear->data->node_number);
		}
		
		if (mom->right != NULL) {
			mom->right->node_number = (mom->node_number * 2 + 1);
			push(mom->right, &front, &rear);
			//printf("이건 되제??  %d\n", front->data->node_number);
		}
	}

}

void preorder_print(nodePointer tree) {
	if (tree == NULL) {
		return;
	}
	else {
		printf("%c ", tree->data);
		preorder_print(tree->left);
		preorder_print(tree->right);
	}
}

nodePointer pre_to_in(char* preorder, char* inorder) {
	int length = strlen(preorder);
	//printf("%s       %s\n", preorder, inorder);
	if (strlen(preorder) == 0) {
		return NULL;
	}
	
	char next = preorder[0];
	nodePointer head = malloc(sizeof(nodePointer));
	head->data = next;

	// 이등분 하기,,
	
	// next의 위치
	int next_idx = 0;
	for (; next_idx < length; next_idx++){
		if (inorder[next_idx] == next)
			break;
	}
	//printf("%d %d\n", next_idx, length);

	char left_inorder[100];
	char left_preorder[100];
	for (int ii = 0; ii < next_idx; ii++) {
		left_inorder[ii] = inorder[ii];
		left_preorder[ii] = preorder[ii + 1];
	}
	left_inorder[next_idx] = '\0';
	left_preorder[next_idx] = '\0';

	char right_inorder[100];
	char right_preorder[100];
	for (int ii = 1; next_idx + ii < length; ii++) {
		right_inorder[ii-1] = inorder[ii + next_idx];
		right_preorder[ii-1] = preorder[ii + next_idx];
	}
	right_inorder[length - next_idx - 1] = '\0';
	right_preorder[length - next_idx - 1] = '\0';
	
	//연결하기
	//printf("%s       %s\n", left_preorder, left_inorder);
	//printf("%s       %s\n", right_preorder, right_inorder);
	//printf("\n\n");

	head->left = pre_to_in(left_preorder, left_inorder);
	head->right = pre_to_in(right_preorder, right_inorder);
	

	return head;
}

void push(nodePointer data, queuePointer* front, queuePointer* rear) {
	queuePointer new_node = malloc(sizeof(queuePointer));
	new_node->data = data;
	new_node->link = NULL;
	if (*front == NULL) {
		*front = new_node;
		*rear = *front;
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

// preorder - B C
// inorder - B C

