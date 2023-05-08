#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {not, and, or, true, false, empty} logical;

typedef struct tree_node* tree_nodePointer;
typedef struct tree_node {
	logical data;
	int value;
	tree_nodePointer left, right;
};

typedef struct node* nodePointer;
typedef struct node {
	tree_nodePointer data;
	nodePointer link;
};

int* get_variable(FILE** fr, int n);
logical input2logical(char data[20], int* variable);
tree_nodePointer make_tree(FILE* fr, int n, int* variable);
tree_nodePointer Init_tree_node(int data);
void postOrderEval(tree_nodePointer node);
void queue_push(tree_nodePointer data, nodePointer* front, nodePointer* rear);
nodePointer queue_pop(nodePointer* front, nodePointer* rear);


int main(void) {
	FILE* fr = fopen("input.txt", "r");

	int n;
	fscanf(fr, "%d",  &n);

	int * variable = get_variable(&fr, n);
	//printf("%d %d %d", variable[0], variable[1], variable[2]);

	tree_nodePointer tree = make_tree(fr, n, variable);
	postOrderEval(tree);
	if (tree->value == 1) {
		printf("참입니다!\n");
	}
	else {
		printf("거짓입니다..\n");
	}

	return 0;
}

int* get_variable(FILE** fr, int n) {
	int* variableList = malloc( sizeof(int) * n);
	for (int ii = 0; ii < n; ii++) {
		
		char variable[20];
		fscanf( *fr, "%s", variable );
		if (variable[0] == 't') {
			variableList[ii] = 1;
		}
		else {
			variableList[ii] = 0;
		}
	}
	return variableList;
}

logical input2logical(char data[20], int* variable) {
	if (strcmp(data, "not") == 0) return not;
	else if (strcmp(data, "or") == 0) return or ;
	else if (strcmp(data, "and") == 0) return and;
	else if (strcmp(data, "empty") == 0) return empty;
	else {
		char v = data[1];
		int idx = (int)v - (int)'1';
		if (variable[idx] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
}

tree_nodePointer make_tree(FILE* fr, int n, int* variable) {
	char data[20];
	fscanf(fr, "%s", data);
	logical logic = input2logical(data, variable);
	tree_nodePointer tree = Init_tree_node(logic);

	nodePointer front = malloc(sizeof(nodePointer));
	front = NULL;
	nodePointer rear = front;

	queue_push(tree, &front, &rear);
	while (!feof(fr)) {
		tree_nodePointer parent = queue_pop(&front, &rear);

		fscanf(fr, "%s", data);
		logical logic = input2logical(data, variable);

		tree_nodePointer left_node = NULL;
		if (logic != empty) {
			left_node = Init_tree_node(logic);
			parent->left = left_node;
		}
		queue_push(left_node, &front, &rear);

		if (!feof(fr)) {
			fscanf(fr, "%s", data);
			logical logic = input2logical(data, variable);

			tree_nodePointer right_node = NULL;
			if (logic != empty) {
				right_node = Init_tree_node(logic);

				parent->right = right_node;
			}
			queue_push(right_node, &front, &rear);
		}
	}
	return tree;
}

tree_nodePointer Init_tree_node(logical data) {
	tree_nodePointer tree = malloc(sizeof(tree_nodePointer));
	tree->data = data;
	tree->value = NULL;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}

void postOrderEval(tree_nodePointer node) {
	if (node) {
		postOrderEval(node->left);
		postOrderEval(node->right);
		switch (node->data) {
		case not:
			node->value = !node->right->value;
			break;
		case and:
			node->value = node->right->value && node->left->value;
			break;
		case or:
			node->value = node->right->value || node->left->value;
			break;
		case true:
			node->value = 1;
			break;
		case false:
			node->value = 0;
		}
	}
}

void queue_push(tree_nodePointer data, nodePointer* front, nodePointer* rear) {
	nodePointer new_node = (nodePointer)malloc(sizeof(nodePointer));
	new_node->data = data;
	new_node->link = NULL;
	if (*front == NULL) {
		(*front) = new_node;
		(*rear) = new_node;
	}
	else {
		(*rear)->link = new_node;
		(*rear) = new_node;
	}
}

nodePointer queue_pop(nodePointer* front, nodePointer* rear) {
	nodePointer new_node = (*front)->data;
	(*front) = (*front)->link;
	return new_node;
}
