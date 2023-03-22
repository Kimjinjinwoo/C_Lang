#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	short int vert;
	short int horiz;
} offsets;

typedef struct {
	short int row;
	short int col;
	short int dir;
} element;

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int Row, Col;
	int maze[20][20];
	int visited[20][20] = { 0 };
	fscanf(fr, "%d %d", &Row, &Col);
	for (int ii = 0; ii < Row; ii++)
	{
		for (int jj = 0; jj < Col;jj++)
		{
			fscanf(fr, "%d", &maze[ii][jj]);
		}
	}
	fclose(fr);
	// direction 배열 만들기
	offsets move[8] = {
		{-1,0},
		{-1,1},
		{0,1},
		{1,1},
		{1,0},
		{1,-1},
		{0,-1},
		{-1,-1}
	};

	//Stack 만들기
	element* Stack = (element*)malloc(sizeof(element));
	int top = -1;

	// 가자!
	top++;
	Stack = realloc(Stack, sizeof(element) * (top + 1));
	Stack[0].col = 0;
	Stack[0].row = 0;
	Stack[0].dir = 0;
	top++;
	int found = 0;
	int col, row, dir;
	int new_col, new_row, new_dir;
	while (top > -1 && found == 0)
	{
		//printf("%d  ", top);
		col = Stack[top].col;
		row = Stack[top].row;
		dir = Stack[top].dir;
		top--;
		Stack = realloc(Stack, sizeof(element) * (top + 1));
		// 여기부터 방향 바꾸는 for문
		for (int ii = dir; ii < 8; ii++)
		{
			int dx = move[ii].vert, dy = move[ii].horiz;
			new_col = col + dy;
			new_row = row + dx;

			if ((0 <= new_col && new_col < Col) && (0 <= new_row && new_row < Row))
			{
				//printf("%d %d\n", new_row, new_col);
				if (maze[new_row][new_col] != 1)
				{
					if (visited[new_row][new_col] != 1) {
						visited[new_row][new_col] = 1;
						top++;
						Stack = realloc(Stack, sizeof(element) * (top + 1));
						Stack[top].col = col;
						Stack[top].row = row;
						Stack[top].dir = ii;

						top++;
						Stack = realloc(Stack, sizeof(element) * (top + 1));
						Stack[top].col = new_col;
						Stack[top].row = new_row;
						Stack[top].dir = 0;

						if (new_col == Col - 1 && new_row == Row - 1)
							found = 1;

						break;
					}
				}
			}
		}
		/// 여기까지 방향바꾸는 for문
	}
	// while 문 끝남
	FILE* fw = fopen("output.txt", "w");
	if (found == 0)
	{
		fprintf(fw, "fail");
	}
	else
	{
		fprintf(fw, "success\n\n");
		fprintf(fw, "path는 ");
		for (int ii = 0; ii <= top; ii++)
		{
			fprintf(fw, "(%d,%d) ", Stack[ii].row, Stack[ii].col);
		}
		fprintf(fw, "\n\n사용한 스택의 크기 / 스택의 최대 크기 = %d / %d", top + 1, Row * Col);
	}
	free(Stack);
	fclose(fw);
	return 0;
}

