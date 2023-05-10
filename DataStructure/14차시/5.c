#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};

int parent[100];
int visited[100];
nodePointer classList[100];

void weightedUnion(int i, int j);
int find(int num);
nodePointer init_node();
void push(int data, nodePointer* top);
nodePointer pop(nodePointer* top);



int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int N; fscanf(fr, "%d", &N);
	
	//init
	for (int ii = 0; ii < 100; ii++) {
		parent[ii] = -1;
		visited[ii] = 1;
		classList[ii] = NULL;
	}

	for (int ii = 0; ii < N; ii++) {
		int a, b;
		if (ii < N - 1) {
			fscanf(fr, "%d = %d,", &a, &b);
		}
		else {
			fscanf(fr, "%d = %d", &a, &b);
		}
		visited[a] = 0;
		visited[b] = 0;
		weightedUnion(a, b);
	}
	//lets go~  ヽ(°〇°)ﾉ
	int num_class = 0;
	for (int ii = 0; ii < 100; ii++) {
		if (visited[ii] != 0) {
			continue;
		}
		int class = find(ii);

		if (parent[ii] < 0) {
			num_class++;
			class = ii;
		}
		if (classList[class] == NULL) {
			classList[class] = init_node();
		}
		push(ii, &classList[class]);
	}

	printf("Total # od equivalence classes = %d\n", num_class);
	printf("equivalent classes : ");
	int k = 0;
	for (int ii = 0; ii < 100; ii++) {
		if (classList[ii] == NULL) {
			continue;
		}
		k++;
		nodePointer top = classList[ii];
		printf("{");
		while (top != NULL) {
			int p = pop(&top);
			if (top != NULL)
				printf("%d, ", p);
			else
				printf("%d", p);
		}
		if (k < num_class)
			printf("}, ");
		else
			printf("}");

	}
}

void weightedUnion(int i, int j) {
	i = find(i); j = find(j);
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) {
		parent[i] = j;
		parent[j] = temp;
	}
	else {
		parent[j] = i;
		parent[i] = temp;
	}
}

int find(int num) {
	if (parent[num] < 0)
		return num;
	return parent[num] = find(parent[num]);
}

nodePointer init_node() {
	nodePointer x = malloc(sizeof(nodePointer));
	x = NULL;
	return x;
}

void push(int data, nodePointer* top) {
	nodePointer x = malloc(sizeof(nodePointer));
	x->data = data;
	x->link = (*top);
	(*top) = x;
}

nodePointer pop(nodePointer* top) {
	int data = (*top)->data;
	(*top) = (*top)->link;
	return data;
}