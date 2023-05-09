#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct tree_node* tree_nodePointer;
typedef struct tree_node {
	int data;
	tree_nodePointer left, right;
	int left_thread, right_thread;
};

typedef struct node* nodePointer;
typedef struct node {
	tree_nodePointer data;
	nodePointer link;
};

tree_nodePointer Init_tree_node(int data);
tree_nodePointer insucc(tree_nodePointer tree);
void insertRight(tree_nodePointer mom, tree_nodePointer son);
void insertLeft(tree_nodePointer mom, tree_nodePointer son);
void tinorder(tree_nodePointer tree);
void queue_push(tree_nodePointer data, nodePointer* front, nodePointer* rear);
nodePointer queue_pop(nodePointer* front, nodePointer* rear);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);
	printf("%d\n\n", n);

	int data;
	fscanf(fr, "%d", &data);
	printf("%d\n\n", data);
	tree_nodePointer tree = Init_tree_node(data);
	tree->right = tree;
	tree->right_thread = FALSE;
	tree->left = tree;

	nodePointer front = malloc(sizeof(nodePointer));
	front = NULL;
	nodePointer rear = front;
	queue_push(tree, &front, &rear);
	
	int i = 1;
	while (i <= n) {
		tree_nodePointer parent = queue_pop(&front, &rear);

		fscanf(fr, "%d", &data);
		i++;
		tree_nodePointer left_node = NULL;
		if (data != 0) {
			left_node = Init_tree_node(data);
			insertLeft(parent, left_node);
		}
		queue_push(left_node, &front, &rear);

		if (i <= n) {
			fscanf(fr, "%d", &data);
			i++;
			tree_nodePointer right_node = NULL;
			if (data != 0) {
				right_node = Init_tree_node(data);
				insertRight(parent, right_node);
			}
			queue_push(right_node, &front, &rear);
		}
	}

	tinorder(tree);
	return 0;
}

tree_nodePointer Init_tree_node(int data) {
	tree_nodePointer tree = malloc(sizeof(tree_nodePointer));
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	tree->left_thread = TRUE;
	tree->right_thread = TRUE;

	return tree;
}

tree_nodePointer insucc(tree_nodePointer tree)
{
	tree_nodePointer temp;
	temp = tree->right;
	if (!tree->right_thread) {
		while (!temp->left_thread)
			temp = temp->left;
	}
	return temp;
}

void insertRight(tree_nodePointer mom, tree_nodePointer son) {
	tree_nodePointer temp;
	son->right = mom->right;
	son->right_thread = mom->right_thread;
	son->left = mom;
	son->left_thread = TRUE;
	mom->right = son;
	mom->right_thread = FALSE;
	if (!mom->right_thread) {
		temp = insucc(son);
		temp->left = son;
	}
}

void insertLeft(tree_nodePointer mom, tree_nodePointer son) {
	tree_nodePointer temp;
	son->left = mom->left;
	son->left_thread = mom->left_thread;
	son->right_thread = TRUE;
	son->right = mom;
	mom->left = son;
	mom->left_thread = FALSE;
	if (!son->left_thread) {
		temp = insucc(son->left);
		temp->right = son;
	}
}

void tinorder(tree_nodePointer tree) {
	tree_nodePointer temp = tree;
	for (;;) {
		temp = insucc(temp);
		if (temp == tree) break;
		printf("%3d", temp->data);
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
