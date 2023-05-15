#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 100000

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};
void push(int data, nodePointer* top);
int pop(nodePointer* top);
int find_level(int k);
void loser_tree(int level, int* tree, nodePointer** runs);
int* init_tree(int level, nodePointer** runs);

int main(void) {
	FILE* fr = fopen("input.txt", "r");

	int n, k;
	fscanf(fr, "%d %d", &n, &k);
	int level = find_level(k);

	nodePointer* runs_ = (nodePointer*)malloc(sizeof(nodePointer) * pow(2, level));
	for (int ii = 0; ii < pow(2,level); ii++)
		runs_[ii] = NULL;


	for (int ii = 0; ii < k; ii++) {
		for (int jj = 0; jj < n / k; jj++) {
			int data;
			fscanf(fr, "%d", &data);
			push(data, &runs_[ii]);
		}
	}

	nodePointer* runs = (nodePointer*)malloc(sizeof(nodePointer) * pow(2, level));
	for (int ii = 0; ii < pow(2, level); ii++)
		runs[ii] = NULL;


	for (int ii = 0; ii < k; ii++) {
		for (int jj = 0; jj < n / k; jj++) {
			push(pop(&runs_[ii]), &runs[ii]);
		}
	}

	int* tree = init_tree(level, &runs);
	loser_tree(level, tree, &runs);
}
	

void push(int data, nodePointer* top) {
	nodePointer new_node = malloc(sizeof(nodePointer));
	new_node->data = data;
	new_node->link = (*top);
	(*top) = new_node;
}

int pop(nodePointer* top) {
	if ((*top) == NULL) {
		return NULL;
	}
	else {
		int data = (*top)->data;
		(*top) = (*top)->link;
		return data;
	}
}

int find_level(int k) {
	for (int ii = 0;; ii++) {
		if (pow(2, ii) <= k && k < pow(2, ii+1)) {
			return ii;
		}
	}
}

void loser_tree(int level,int* tree, nodePointer** runs) {
	int num_runs = pow(2, level);
	int start = pow(2, level);

	for (int jj = pow(2, level + 1) - 1; jj > 1; jj -= 2) {
		int numL = tree[jj], numR = tree[jj - 1];
		int min_num = numL;
		if (min_num > numR)
			min_num = numR;
		tree[(jj - 1) / 2] = min_num;
	}

	for (int ii = 0; ii < num_runs; ii++) {
		int num = tree[start + ii];
		if (num == tree[1]) {
			int new_num = pop(&((*runs)[ii]));
			if (new_num == NULL)
				new_num = maxsize;
			tree[start + ii] = new_num;
			break;
		}
	}
	if (tree[1] == maxsize) {
		return;
	}
	printf("%d ", tree[1]);
	loser_tree(level, tree, runs);
}

int* init_tree(int level, nodePointer** runs) {
	int* tree = malloc(sizeof(int) * (pow(2, level + 1)));
	int num_runs = pow(2, level);
	int start = pow(2, level);
	for (int ii = 0; ii < num_runs; ii++) {
		int num = pop(&((*runs)[ii]));
		if (num == NULL) {
			num = maxsize;
		}
		tree[start + ii] = num;
	}
	return tree;
}



