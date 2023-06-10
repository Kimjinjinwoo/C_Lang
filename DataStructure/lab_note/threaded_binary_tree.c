#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct node* threadedPointer;
typedef struct node {
	int leftTread;
	threadedPointer left;
	int data;
	threadedPointer right;
	int rightTread;
};

typedef struct queue* queuePointer;
typedef struct queue {
	threadedPointer data;
	queuePointer link;
};

threadedPointer init_node(int data);
void tinorder(threadedPointer root);
threadedPointer insucc(threadedPointer X);
void insertRight(threadedPointer par, threadedPointer rightChild);
void insertLeft(threadedPointer par, threadedPointer leftChild);
void push(threadedPointer data, queuePointer* front, queuePointer* rear);
threadedPointer pop(queuePointer* front, queuePointer* rear);



int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);

	queuePointer front = (queuePointer) malloc(sizeof(queuePointer));
	front = NULL;
	queuePointer rear = front;

	threadedPointer root = init_node(0);
	//printf("%d\n", rear->data->data);
	
	int data; fscanf(fr, "%d", &data);
	threadedPointer first_node = init_node(data);
	insertLeft(root, first_node);

	/*
	printf("root의 right_node_data : %d\n", root->right->data);
	printf("root의 left_node_data : %d\n", root->left->data);
	printf("left의 right_node_data : %d\n", root->left->right->data);
	printf("left의 right_thread : %d\n", root->left->rightTread);
	printf("left의 left_node_data : %d\n", root->left->left->data);
	printf("left의 left_thread : %d\n", root->left->leftTread);
	*/

	push(first_node, &front, &rear);

	int num_data = 1;


	while( front != NULL ) {
		threadedPointer par = pop(&front, &rear);
		if (par == NULL) {
			push((threadedPointer) NULL, &front, &rear);
			push((threadedPointer) NULL, &front, &rear);
			continue;
		}

		int left_data; fscanf(fr, "%d", &left_data);
		printf("left = %d\n", left_data);
		if (left_data != 0)  {
			num_data += 1;
			threadedPointer left_node = init_node(left_data);
			insertLeft(par, left_node);
			push(left_node, &front, &rear);
		}
		else
			push((threadedPointer)NULL, &front, &rear);

		if (num_data == n) break;
	
		
		int right_data; fscanf(fr, "%d", &right_data);
		printf("right = %d\n\n", right_data);
		if (right_data != 0) {
			num_data += 1;
			threadedPointer right_node = init_node(right_data);
			insertRight(par, right_node);
			push(right_node, &front, &rear);
		}
		else
			push((threadedPointer) NULL, &front, &rear);

		if (num_data == n) break;

		//tinorder(root);
	}
	printf("done,,,\n");
	tinorder(root);

	return 0;
}

threadedPointer insucc(threadedPointer X) {
	threadedPointer temp;

	temp = X->right;
	if (!X->rightTread) { //right노드가 있으면
		while (!temp->leftTread) { //left노드가 있으면
			temp = temp->left;
		}
	}
	return temp;
}

threadedPointer init_node(int data) {
	threadedPointer new_node = (threadedPointer) malloc(sizeof(threadedPointer) * 10);
	new_node->data = data;
	new_node->right = new_node;
	new_node->rightTread = FALSE;
	new_node->left = new_node;
	new_node->leftTread = TRUE;
	return new_node;
}

void tinorder(threadedPointer root) {
	printf("\n\ntinorder>>\n");
	threadedPointer temp = root;
	for (;;) {
		temp = insucc(temp);
		if (temp == root) break;
		printf("%d\n", temp->data);
	}

}

void insertRight(threadedPointer par, threadedPointer rightChild) {
	threadedPointer temp;
	rightChild->right = par->right;
	rightChild->rightTread = par->rightTread;
	rightChild->left = par;
	rightChild->leftTread = TRUE;
	par->right = rightChild;
	par->rightTread = FALSE;
	if (!rightChild->rightTread) { //right노드가 있으면
		temp = insucc(rightChild); //오호,,,,
		temp->left = rightChild;
	}
}

void insertLeft(threadedPointer par, threadedPointer leftChild) {
	threadedPointer temp;
	leftChild->left = par->left;
	leftChild->leftTread = par->leftTread;
	leftChild->right = par;
	leftChild->rightTread = TRUE;
	par->left = leftChild;
	par->leftTread = FALSE;
	//해야됨,,,
	if (!leftChild->leftTread) { //왼쪽 노드가 있으면
		temp = leftChild;
		while (!insucc(temp) == par) {
			temp = insucc(temp);
		}
		temp->right = leftChild;
		temp->right = FALSE;
	}
}

void push(threadedPointer data, queuePointer* front, queuePointer* rear) {
	queuePointer new_node = (queuePointer) malloc(sizeof(queuePointer));
	new_node->data = data;
	new_node->link = NULL;
	if ((*front) == NULL) {
		*front = new_node;
		*rear = new_node;
	}
	else {
		(*rear)->link = new_node;
		*rear = new_node;
	}
}

threadedPointer pop(queuePointer* front, queuePointer* rear) {
	threadedPointer data = (*front)->data;
	*front = (*front)->link;
	return data;
}