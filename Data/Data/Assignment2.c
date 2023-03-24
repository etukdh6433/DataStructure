#include <stdio.h>
#include <stdbool.h>

#define EXIT_ROW 12
#define EXIT_COL 12

#define MAX_SIZE 12
#define MAX_DIR 4
#define MAX_STACK 144

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

element stack[MAX_STACK];

typedef struct {
	short int vert;
	short int horiz;
}offsets;

offsets move[MAX_DIR] = { {-1,0},{0,1},{1,0},{0,-1} };

int top;

element pop();
void push(element cur);
void path(int maze[][MAX_SIZE + 2], int mark[][MAX_SIZE + 2]);

int main(void)
{
	int maze[MAX_SIZE + 2][MAX_SIZE + 2] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1}, {1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1}, {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
	int mark[MAX_SIZE + 2][MAX_SIZE + 2];

	for (int i = 0; i < MAX_SIZE + 2; i++) {
		for (int j = 0; j < MAX_SIZE + 2; j++) {
			mark[i][j] = 0;
		}
	}

	path(maze, mark);

	return 0;
}

element pop()
{
	return stack[top--];
}

void push(element cur)
{
	stack[++top] = cur;
}

void path(int maze[][MAX_SIZE + 2], int mark[][MAX_SIZE + 2])
{
	int i, row, col, nextRow, nextCol, dir, found = false;
	element position;
	mark[1][1] = 1; top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;

	while (top > -1 && !found) {
		position = pop();
		row = position.row; col = position.col; dir = position.dir;

		while (dir < 4 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
				found = true;
			}
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;
				position.row = row; position.col = col;
				position.dir = ++dir;

				push(position);
				row = nextRow; col = nextCol; dir = 0;
			}
			else ++dir;
		}
	}

	if (found) {
		printf("The path is : \n");
		printf("row   col\n");
		for (int i = 0; i <= top; i++) {
			printf("%2d %5d\n", stack[i].row, stack[i].col);
		}
		printf("%2d %5d\n", row, col);
		printf("%2d %5d\n", EXIT_ROW, EXIT_COL);
	}
	else printf("The maze does not have a path\n");
}