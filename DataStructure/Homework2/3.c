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
		printf("���� ������ �Է��ϼ��� : ");
		scanf("%d", &number_biz);

		srand(time(0));
		int bizList[20];
		//0�� ��� 1�� ����
		for (int ii = 0; ii < number_biz; ii++) {
			bizList[ii] = rand() % 2;
		}
		
		printf("������ ���� :");
		for (int ii = 0; ii < number_biz; ii++) {
			if (bizList[ii] == 0)
				printf(" ��");
			else
				printf(" ��");
		}
		printf("\n�ָӴϿ� ������ �־����ϴ�.\n\n");
		//���� �ֱ�
		stackPointer top;
		top = NULL;
		for (int ii = 0;ii < number_biz;ii++) {
			int biz = bizList[ii];
			if (biz == 1) { //�������̸�
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
		printf("���\n");
		printf("�Ͼ�� ����: %d��\n", white);
		printf("������ ����: %d��\n", black);
		printf("�ٽ� �ϰڽ��ϱ�? [y/n]");
		scanf("%s", &ans);
		printf("\n");
		if (!strcmp(ans, "n"))
			break;
	}
	printf("���α׷��� �����մϴ�.");
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
