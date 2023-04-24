#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer left, right;
};
nodePointer Init_node();

typedef struct queue_node* queue_nodePointer;
typedef struct queue_node {
	nodePointer data;
	queue_nodePointer link;
};
nodePointer queue_pop(queue_nodePointer* front);
void queue_push(nodePointer data, queue_nodePointer* rear);

int main() {
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);

	nodePointer root = Init_node();
	int data;
	fscanf(fr, "%d", &data);
	root->data = data;
	queue_nodePointer X = malloc(sizeof(queue_nodePointer));
	queue_nodePointer front = X, rear = X;
	queue_push(root, &rear);

	int num_of_node = 1;
	int conti = 1;

	while (conti == 1) {
		 nodePointer head = queue_pop(&front);

		for (int jj = 0; jj < 2; jj++) { //for문으로는 못하겟네,,,?
			int data;
			fscanf(fr, "%d", &data);
			if (data == -1) {
			head->left == NULL;
			continue;
			}
			else {
				nodePointer newNode = Init_node();
				newNode->data = data;
				head->left = newNode;
				num_of_node++;
				queue_push(newNode, &rear);
				if (num_of_node == n) {
					conti = 0;
					break;
				}
			}
		}
	}
}

nodePointer Init_node() {
	nodePointer node = malloc(sizeof(nodePointer));
	node->data = -1;
	//node->left = NULL;
	node->right = NULL;
	return node;
}

nodePointer queue_pop(queue_nodePointer* front) {
	nodePointer x = (*front)->data;
	(*front) = (*front)->link;
	return x;
}

void queue_push(nodePointer data, queue_nodePointer* rear) {
	queue_nodePointer x = malloc(sizeof(queue_nodePointer));
	x->data = data;
	(*rear)->link = x;
	(*rear) = x;
}
