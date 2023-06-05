#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 10000000

typedef struct elemet {
	int weight;
	int cost;
	int root;
}element;

typedef struct node_info {
	int pos;
	int start;
	int end;
}node_info;

typedef struct node* nodePointer;

typedef struct node {
	node_info data;
	nodePointer link;
};


void calc_dp(int start, int end);
void find_topology(FILE* fw);
void push(node_info data, nodePointer* front, nodePointer* rear);
node_info pop(nodePointer* front, nodePointer* rear);

int n, m;
int* nodes, * p_list, * q_list;
element** dp;



int main(void) {
	FILE* fr = fopen("input.txt", "r");
	FILE* fw = fopen("ouput.txt", "w");
	fscanf(fr, "%d %d", &n, &m);

	nodes = (int*)malloc(sizeof(int) * n);
	for (int ii = 0; ii < n; ii++) {
		int data; fscanf(fr, "%d", &data);
		nodes[ii] = data;
	}

	p_list = (int*)malloc(sizeof(int) * n);
	for (int ii = 0; ii < n; ii++) {
		int data; fscanf(fr, "%d", &data);
		p_list[ii] = data;
		//printf("%d\n", p_list[ii]);
	}

	q_list = (int*)malloc(sizeof(int) * (n + 1));
	for (int ii = 0; ii < (n + 1); ii++) {
		int data; fscanf(fr, "%d", &data);
		q_list[ii] = data;
	}

	// dp_init
	dp = malloc(sizeof(element*) * (n + 1));
	for (int ii = 0; ii < (n + 1); ii++) {
		dp[ii] = (element*)malloc(sizeof(element) * (n + 1));
	}

	for (int ii = 0; ii < (n + 1); ii++) {
		dp[0][ii].cost = 0;
		dp[0][ii].root = 0;
		dp[0][ii].weight = q_list[ii];
	}


	//여기까진 그냥 입력 받기 한거임~
	//start
	for (int ii = 1; ii < n + 1; ii++) {
		for (int jj = 0; jj < n + 1 - ii; jj++) {
			//printf("%d %d /// ", jj, jj+ii);
			calc_dp(jj, jj + ii);
			int start = jj;
			int end = jj + ii;
		}
	}
	int min_cost = dp[n][0].cost;
	double exact_cost = (double)min_cost / (double)m;
	fprintf(fw, "Optimal Binary Search Tree의 총 비용은 %g 이며(%d/%d = %g)\n",exact_cost, min_cost, m, exact_cost);
	fprintf(fw, "그 토폴로지는 다음과 같습니다.\n\n");

	find_topology(fw);
	return 0;
}
//1 2 
//Ex W12 -- (11, 22)
void calc_dp(int start, int end) { //Ex W03 -- (00, 13) (01, 23) (12, 33)
	dp[end - start][start].weight = inf;
	dp[end - start][start].cost = inf;
	dp[end - start][start].root = inf;
	for (int ii = 0; ii < (end - start); ii++) { // 0, 1, 2
		element left = dp[ii][start];
		element right = dp[end - start - ii - 1][start + ii + 1];

		int weight_left = left.weight;
		int weight_right = right.weight;
		int weight = weight_left + weight_right + p_list[start + ii];

		int cost_left = left.cost;
		int cost_right = right.cost;
		int cost = weight + cost_left + cost_right;

		int root = start + ii + 1;
		if (dp[end - start][start].cost > cost) {
			dp[end - start][start].weight = weight;
			dp[end - start][start].cost = cost;
			dp[end - start][start].root = root;
		}
	}
}
//bfs??
void find_topology(FILE* fw) {
	nodePointer front = malloc(sizeof(nodePointer));
	front = NULL;
	nodePointer rear = front;
	node_info data = { 1, 0, n };
	push(data, &front, &rear);

	while (front) {
		data = pop(&front, &rear);
		int pos = data.pos;
		int start = data.start;
		int end = data.end;
		int root = dp[end - start][start].root;
		if (root) {
			fprintf(fw, "complete BT의 %d 노드 자리에 원소 %d가 위치합니다.\n", pos, nodes[root - 1]);
		}
		else {
			continue;
		}

		node_info left = { pos * 2, start, root - 1 };
		node_info right = { pos * 2 + 1, root, end };
		push(left, &front, &rear);
		push(right, &front, &rear);
	}
}

void push(node_info data, nodePointer* front, nodePointer* rear) {
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

node_info pop(nodePointer* front, nodePointer* rear) {
	node_info new_node = (*front)->data;
	(*front) = (*front)->link;
	return new_node;
}