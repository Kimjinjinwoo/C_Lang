// 안되던디... 왜 되지..?
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer left;
	nodePointer right;
}node;

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	nodePointer header = (nodePointer)malloc(sizeof(nodePointer));
	header->right = header;
	header->left = header;
	nodePointer new_node = (nodePointer)malloc(sizeof(nodePointer));
	nodePointer new_node2 = (nodePointer)malloc(sizeof(nodePointer));
}