#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
};
polyPointer initPoly();
void attach(int, int, polyPointer*);

int main(void) {
	polyPointer A = initPoly(), B = initPoly();

	FILE* fr = fopen("input.txt", "r");
	int n, m, coef, expon;
	fscanf(fr, "%d %d", &n, &m);
	for (int ii = 0; ii < n;ii++) {
		fscanf(fr, "%d %d", &coef, &expon);
		attach(coef, expon, &A);
	}
	A = A->link;

	for (int jj = 0; jj < m;jj++) {
		fscanf(fr, "%d %d", &coef, &expon);
		attach(coef, expon, &B);
	}
	B = B->link;

	/* 확인 코드

	polyPointer tmp = B->link;
	for (int ii = 0; ii < 5;ii++) {
		printf("%d %d\n", tmp->coef, tmp->expon);
		tmp = tmp->link;
	}
	*/

	polyPointer startA = A, C = initPoly(), lastC = C;
	int expA, expB, sum, done = 0;
	A = A->link; B = B->link;

	do {
		expA = A->expon; expB = B->expon;
		//printf("%d %d\n", expA, expB);
		if (expA < expB) {
			attach(B->coef, B->expon, &lastC);
			B = B->link;
		}
		else if (expA == expB) {
			if (A == startA) {
				//printf("\n---- %d ----\n", 1);
				done = 1;
			}
			else {
				sum = A->coef + B->coef;
				//printf("\n---- %d ----\n", sum);
				if (sum) {
					attach(sum, A->expon, &lastC);
				}
				A = A->link; B = B->link;
			}
		}
		else if (expA > expB) {
			attach(A->coef, A->expon, &lastC);
			A = A->link;
		}
	} while (!done);
	lastC->link = C;

	polyPointer X = C->link;
	
	FILE* fw = fopen("output.txt", "w");
	while(C!=X){
		coef = X->coef; expon = X->expon;
		//printf("%d %d\n", coef, expon);
		fprintf(fw, "%d %d\n", coef, expon);
		X = X->link;
	}
	fclose(fr);
	fclose(fw);
	
	return 0;
}

polyPointer initPoly() {
	polyPointer poly = (polyPointer)malloc(sizeof(*poly));
	poly->coef = -1;
	poly->link = poly;
	return poly;
}

void attach(int coef, int expon, polyPointer* ptr)
{
	polyPointer temp = (polyPointer) malloc(sizeof(*temp));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = (*ptr)->link;
	(*ptr)->link = temp;
	*ptr = temp;
}