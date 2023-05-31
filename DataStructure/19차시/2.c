#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};

nodePointer hashtable[13];
int dict_size = 13;
char keyword[100][20];

unsigned int stringToInt(char* key);
void find(char* keyword);
void stack_push(nodePointer* top,int data);

int main(void) {
	// 입력받기
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);
	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%s", keyword[ii]);
	}

	// hash table 만들기,,,
	for (int ii = 0; ii < dict_size; ii++) {
		nodePointer new_node = malloc(sizeof(nodePointer));
		new_node = (nodePointer) NULL;
		hashtable[ii] = new_node;
	};

	//table에 넣어 주기
	for (int ii = 0; ii < n; ii++) {
		int hash_id = stringToInt(keyword[ii]);
		int address = hash_id - ((int)(hash_id / dict_size) * dict_size);
		stack_push(&hashtable[address], ii);
	}

	//main loop
	while (1) {
		printf("> 입력할 키워드를 입력하시오...\n> ");
		char word[20];
		scanf("%s", word);
		printf("\n");
		if (strcmp(word, "quit") == 0) {
			printf("> 프로그램을 종료합니다,,,");
			break;
		}

		find(word);
		printf("\n----------------------------\n\n");
	}
	return 0;
}

unsigned int stringToInt(char* key)
{
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}

void find(char* word) {
	int hash_id = stringToInt(word);
	int address = hash_id - ((int)(hash_id / dict_size) * dict_size);
	nodePointer X = (hashtable[address]);
	while (1) {
		if (X == NULL) {
			printf("> 키워드가 존재하지 않습니다.\n");
			return;
		}
		else if (strcmp(keyword[X->data], word) == 0) {
			printf("> 버킷 주소 %d에 저장된 키워드 입니다.\n", address);
			return;
		}
		else {
			X = X->link;
		}
	}
}

void stack_push(nodePointer* top, int data) {
	nodePointer new_node = malloc(sizeof(nodePointer));
	new_node->data = data;
	new_node->link = *top;
	(*top) = new_node;
}