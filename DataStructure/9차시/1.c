#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};

typedef struct nodenode* nodenodePointer;
typedef struct nodnode {
	nodePointer data;
	nodenodePointer link;
};

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n;
	int visited[24] = { FALSE };
	nodePointer seq[24] = { NULL };
	fscanf(fr, "%d", &n);
	for (int ii = 0; ii < n; ii++) {
		int a, b;
		fscanf(fr, "%d = %d", &a, &b);
		nodePointer x;

		x = (nodePointer) malloc(sizeof(*x));
		x->data = a; x->link = seq[b]; seq[b] = x;

		x = (nodePointer)malloc(sizeof(*x));
		x->data = b; x->link = seq[a]; seq[a] = x;
	}

	// Ãâ·Â;
	
	int num_class = 0;
	int* len_list = (int*)malloc(sizeof(int) * n);
	int List[30][100];
	
	nodePointer x, y, top, tmp;
	tmp = (nodePointer)malloc(sizeof(*tmp));

	int ii, jj;
	for (ii = 0;ii < 24; ii++) {
		nodePointer eqList;
		if (seq[ii] == NULL)
			continue;
		if (!visited[ii]) {
			num_class++;
			len_list[num_class - 1] = 1;
			visited[ii] = TRUE;
			x = seq[ii]; top = NULL; 
			
			List[num_class - 1][len_list[num_class - 1] - 1] = ii;

			for (;;) {
				while (x) {
					jj = x->data;
					if (!visited[jj]) {					
						visited[jj] = TRUE;
						y = x->link; x->link = top; top = x; x = y;	
						
						len_list[num_class - 1]++;
						List[num_class - 1][len_list[num_class - 1] - 1] = jj;
					}
					else {
						x = x->link;
					}
				}
				if (!top) break;
				x = seq[top->data]; top = top->link;
			}			

		}
	}
	FILE* fw = fopen("output.txt", "w"); 
	fprintf(fw,"%d\n", num_class);
	for (ii = 0; ii < num_class; ii++) {
		fprintf(fw,"{");
		for (jj = 0;jj < len_list[ii];jj++) {
			fprintf(fw,"%d", List[ii][jj]);
			if (jj != len_list[ii] - 1) fprintf(fw, ", ");
		}
		fprintf(fw, "}");
		if (ii != num_class - 1) fprintf(fw, ", ");
	}
	fclose(fr);
	fclose(fw);
}