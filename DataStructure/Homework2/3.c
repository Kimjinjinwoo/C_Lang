#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct stack* stackPointer;
typedef struct stack {
	int data;
	stackPointer link;
};

void push(int, stackPointer* );
int pop(stackPointer*);

int main(void) {
	int number_biz;
	while (1) {
		printf("****************************************\n");
		printf("구슬 개수를 입력하세요 : ");
		scanf("%d", &number_biz);

		srand(time(0));
		int bizList[20];
		//0는 흰색 1은 검정
		for (int ii = 0; ii < number_biz; ii++) {
			bizList[ii] = rand() % 2;
		}
		
		printf("생성된 구슬 :");
		for (int ii = 0; ii < number_biz; ii++) {
			if (bizList[ii] == 0)
				printf(" 흰");
			else
				printf(" 검");
		}
		printf("\n주머니에 구슬을 넣었습니다.\n\n");
		//구슬 넣기
		stackPointer top;
		top = NULL;
		for (int ii = 0;ii < number_biz;ii++) {
			int biz = bizList[ii];
			if (biz == 1) { //검정색이면
				push(1, &top);
				push(1, &top);
			}
			else {
				if (top != NULL)
					pop(&top);
				if (top != NULL)
					pop(&top);

				push(0, &top);
			}
		}

		int white = 0, black = 0;
		while (top != NULL) {
			int biz = pop(&top);
			if (biz == 0)
				white++;
			else
				black++;
		}
		char ans[20];
		printf("결과\n");
		printf("하얀색 구슬: %d개\n", white);
		printf("검정색 구슬: %d개\n", black);
		printf("다시 하겠습니까? [y/n]");
		scanf("%s", &ans);
		printf("\n");
		if (!strcmp(ans, "n"))
			break;
	}
	printf("프로그램을 종료합니다.");
}

void push(int data, stackPointer* top)
{

	stackPointer temp = (stackPointer) malloc( sizeof(*temp));
	temp->data = data;
	temp->link = *top;
	*top = temp;
}

int pop(stackPointer* top) {
	int data = (*top)->data;
	(*top) = (*top)->link;
	return data;
}
