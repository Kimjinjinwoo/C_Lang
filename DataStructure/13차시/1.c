#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node* tree_nodePointer;
typedef struct tree_node {
	int data;
	tree_nodePointer left, right;
};

typedef struct node* nodePointer;
typedef struct node {
	tree_nodePointer data;
	nodePointer link;
};

tree_nodePointer make_tree(FILE* fr);
tree_nodePointer Init_tree_node(int data);
void queue_push(tree_nodePointer data, nodePointer* front, nodePointer* rear);
nodePointer queue_pop(nodePointer* front, nodePointer* rear);
int equal(tree_nodePointer first, tree_nodePointer second);

int main(void) {
	FILE* fr1 = fopen("input1.txt", "r");
	FILE* fr2 = fopen("input2.txt", "r");

	tree_nodePointer tree1 = make_tree(fr1);
	tree_nodePointer tree2 = make_tree(fr2);

	if (equal(tree1, tree2)) {
		printf("두 트리가 같습니다");
	}
	else {
		printf("두 트리가 같지 않습니다.");
	}

	fclose(fr1);
	fclose(fr2);
	return 0;
}

tree_nodePointer make_tree(FILE* fr) {
	int n;
	fscanf(fr, "%d", &n);

	int data;
	fscanf(fr, "%d", &data);
	tree_nodePointer tree = Init_tree_node(data);

	nodePointer front = malloc(sizeof(nodePointer));
	front = NULL;
	nodePointer rear = front;

	queue_push(tree, &front, &rear);
	while (!feof(fr)) {
		
		tree_nodePointer parent = queue_pop(&front, &rear);

		fscanf(fr, "%d", &data);
		tree_nodePointer left_node = NULL;
		if (data != -1) {
			left_node = Init_tree_node(data);
			parent->left = left_node;
		}
		queue_push(left_node, &front, &rear);

		if (!feof(fr)) {
			fscanf(fr, "%d", &data);
			tree_nodePointer right_node = NULL;
			if (data != -1) {
				right_node = Init_tree_node(data);
				parent->right = right_node;
			}
			queue_push(right_node, &front, &rear);
		}
	}
	return tree;
}

tree_nodePointer Init_tree_node(int data) {
	tree_nodePointer tree = malloc(sizeof(tree_nodePointer));
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	
	return tree;
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

int equal(tree_nodePointer first, tree_nodePointer second) {
	//printf("%d", first->data);
	return ((!first && !second) || (first && second && (first->data == second->data)
		&& equal(first->left, second->left) 
		&& equal(first->right, second->right)));
}