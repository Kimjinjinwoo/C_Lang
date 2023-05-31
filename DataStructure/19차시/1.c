#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** hashtable;
int dict_size;

unsigned int stringToInt(char* key);
int getDictSize(int num_keyword);
void push(char* keyword);
void find(char* keyword);

int main(void) {
	// �Է¹ޱ�
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);
	char keyword[100][20];
	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%s", keyword[ii]);
	}

	//dictionary size���ϱ�
	dict_size = getDictSize(n);

	// hash table �����,,,
	hashtable = (char**)malloc(sizeof(char*) * dict_size);
	for (int ii = 0; ii < dict_size; ii++) {
		hashtable[ii] = (char*)malloc(sizeof(char) * 20);
		strcpy(hashtable[ii],"");
	}

	//table�� �־� �ֱ�
	for (int ii = 0; ii < n; ii++) {
		push(keyword[ii]);
	}

	//main loop
	while (1) {
		printf("> �Է��� Ű���带 �Է��Ͻÿ�...\n> ");
		char word[20];
		scanf("%s", word);
		printf("\n");
		if (strcmp(word, "quit") == 0) {
			printf("> ���α׷��� �����մϴ�,,,");
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
int getDictSize(int num_keyword) {
	int n = num_keyword;
	int result = 0;
	while (!result) {
		n++;
		result = 1;
		for (int ii = 2; ii < n; ii++) {
			if (ii * ii > n)
				break;
			if (n == ((int)(n / ii)) * ii)
				result = 0;
		}

	}
	return n;
}
void push(char* keyword) {
	int hash_id = stringToInt(keyword);
	int address =hash_id - ((int) (hash_id / dict_size) * dict_size);
	while (1) {
		if (strcmp(hashtable[address], "") == 0) {
			strcpy(hashtable[address], keyword);
			break;
		}
		else {
			address++;
			address %= dict_size;
			}
		}
}
void find(char* keyword) {
	int hash_id = stringToInt(keyword);
	int address = hash_id - ((int)(hash_id / dict_size) * dict_size);
	while (1) {
		if (strcmp(hashtable[address], "") == 0) {
			printf("> Ű���尡 �������� �ʽ��ϴ�.\n");
			return;
		}
		else if (strcmp(hashtable[address], keyword) == 0) {
			printf("> ��Ŷ �ּ� %d�� ����� Ű���� �Դϴ�.\n", address);
			return;
		}
		else {
			address++;
			address %= dict_size;
		}
	}
}
