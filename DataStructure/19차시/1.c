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
	// 입력받기
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);
	char keyword[100][20];
	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%s", keyword[ii]);
	}

	//dictionary size구하기
	dict_size = getDictSize(n);

	// hash table 만들기,,,
	hashtable = (char**)malloc(sizeof(char*) * dict_size);
	for (int ii = 0; ii < dict_size; ii++) {
		hashtable[ii] = (char*)malloc(sizeof(char) * 20);
		strcpy(hashtable[ii],"");
	}

	//table에 넣어 주기
	for (int ii = 0; ii < n; ii++) {
		push(keyword[ii]);
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
			printf("> 키워드가 존재하지 않습니다.\n");
			return;
		}
		else if (strcmp(hashtable[address], keyword) == 0) {
			printf("> 버킷 주소 %d에 저장된 키워드 입니다.\n", address);
			return;
		}
		else {
			address++;
			address %= dict_size;
		}
	}
}
