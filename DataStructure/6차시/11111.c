#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };
precedence getToken(char*);
char* convert2S(precedence);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	char express[100][10];
	char postfix[100][10];
	int num_of_char = 0;
	int num_of_post = 0;
	while (feof(fr) == 0) {
		fscanf(fr, "%s", express[num_of_char]);
		num_of_char++;
	}
	fclose(fr);
	/*
	for (int ii = 0; ii < num_of_char; ii++) {
		strcpy(postfix[num_of_post], express[ii]);
		num_of_post++;
	}
	for (int ii = 0; ii < num_of_post; ii++) {
		printf("%s ", postfix[ii]);

	}
	*/

	FILE* fw = fopen("output.txt", "w");

	char stack[100][10];
	int top = -1;

	for (int ii = 0; ii < num_of_char; ii++)
	{
		precedence token = getToken(express[ii]);
		if (token == operand) {
			//printf("\n%s  %d  %d  1\n", express[ii], ii, top);
			fprintf(fw, "%s ", express[ii]);
			strcpy(postfix[num_of_post], express[ii]);
			num_of_post++;
		}
		else if (token == rparen) {
			while (getToken(stack[top]) != lparen) {
				//printf("\n%s  %d  %d  2\n", express[ii], ii, top);
				fprintf(fw, "%s ", stack[top]);
				strcpy(postfix[num_of_post], stack[top]);
				num_of_post++;
				top--;
			}
			if (top > -1)
				top--;
		}
		else {
			
			while (isp[getToken(stack[top])] >= icp[token] && top >= 0) {
				//printf("\n%s  %d  %d  3\n", express[ii], ii, top);
				fprintf(fw, "%s ", stack[top]);
				strcpy(postfix[num_of_post], stack[top]);
				num_of_post++;
				top--;
			}
			strcpy(stack[top + 1], express[ii]);
			top++;
		}
	}
	while (top >= 0)
	{
		fprintf(fw, "%s ", stack[top]);
		strcpy(postfix[num_of_post], stack[top]);
		num_of_post++;
		top--;
	}

	int stack2[100];
	top = -1;
	for (int ii = 0; ii < num_of_post; ii++)
	{	
		precedence token = getToken(postfix[ii]);
		if (token == operand) {
			stack2[top + 1] = (int) ((char)postfix[ii][0]) - '0';
			top++;
		}
		else {
			int op2 = stack2[top];
			top--;
			int op1 = stack2[top];
			top--;
			switch (token) {
			case plus: stack2[top+1] = (op1 + op2);
				top++;break;
			case minus: stack2[top+1] = (op1 - op2);
				top++;break;
			case times: stack2[top+1] = (op1 * op2);
				top++;break;
			case divide: stack2[top+1] = (op1 / op2);
				top++;break;
			case mod: stack2[top+1] = (op1 % op2);
				top++;break;
			}
		}
	}
	fprintf(fw,"\n´äÀº %d", stack2[top]);
	fclose(fw);

	return 0;

}

precedence getToken(char* symbol)
{
	if (strcmp(symbol, "(") == 0)return lparen;
	else if (strcmp(symbol, ")") == 0) return rparen;
	else if (strcmp(symbol, "+") == 0) return plus;
	else if (strcmp(symbol, "-") == 0) return minus;
	else if (strcmp(symbol, "/") == 0) return divide;
	else if (strcmp(symbol, "*") == 0) return times;
	else if (strcmp(symbol, "%") == 0) return mod;
	else if (strcmp(symbol, " ") == 0) return eos;
	else return operand;

}

char* convert2S(precedence X) {
	switch (X) {
	case 0: return"(";
	case 1: return")";
	case 2: return"+";
	case 3: return"-";
	case 4: return"*";
	case 5: return"/";
	case 6: return"%";
	case 7: return" ";
	}
}

