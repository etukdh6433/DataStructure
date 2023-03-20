#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define MAX_TERMS 9

void transpose (int a[][N], int b[][N]);
void mmult(int a[][N], int b[][N], int d[][N]);
void storeSum(int d[][N], int* totalD, int row, int col, int* sum);
int COMPARE(int a, int b);

int main(void)
{
	int A[9][3] = { {6,6,8}, {0,0,5}, {0,3,2}, {0,5,-5}, {1,1,1}, {1,2,3}, {2,3,-6}, {4,0,1}, {5,2,6} };
	int B[9][3];
	int D[10][3];

	transpose(A, B);
	mmult(A, B, D);

	printf("A : ");

	for (int i = 0; i < MAX_TERMS; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("transpose(A) : ");

	for (int i = 0; i < MAX_TERMS; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%5d", B[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("A X B : ");

	for (int i = 0; i < D[0][2] + 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%5d", D[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void transpose(int a[][N], int b[][N])
{
	int n, i, j, currentb;
	n = a[0][2] + 1;
	b[0][0] = a[0][1];
	b[0][1] = a[0][0];
	b[0][2] = a[0][2];

	if (n > 0)
	{
		currentb = 1;
		for (i = 0; i < a[0][1]; i++)
		{
			for (j = 1; j < n; j++)
			{
				if (a[j][1] == i)
				{
					b[currentb][0] = a[j][1];
					b[currentb][1] = a[j][0];
					b[currentb][2] = a[j][2];
					currentb++;
				}
			}
		}
	}
}

void mmult(int a[][N], int b[][N], int d[][N])
{
	int i, j, col, totalD = 0;
	int rowsA = a[0][0], colsA = a[0][1], totalA = a[0][2];
	int colsB = b[0][1], totalB = b[0][2];
	int rowBegin = 1, row = a[1][0], sum = 0;
	int newB[MAX_TERMS][3];

	if (colsA != b[0][0])
	{
		fprintf(stderr, "Incompatible matrices\n");
		exit(1);
	}

	transpose(b, newB);

	a[totalA + 1][0] = rowsA;
	newB[totalB + 1][0] = colsB;
	newB[totalB + 1][1] = 0;
	col = newB[1][0];

	for (i = 1; i < totalA;)
	{
		col = newB[1][0];
		
		for (j = 1; j <= totalB + 1;)
		{
			if (a[i][0] != row)
			{
				storeSum(d, &totalD, row, col, &sum);
				i = rowBegin;
				for (; newB[j][0] == col; j++);
				col = newB[j][0];
			}
			else if (newB[j][0] != col)
			{
				storeSum(d, &totalD, row, col, &sum);
				i = rowBegin;
				col = newB[j][0];
			}
			else switch (COMPARE(a[i][1], newB[j][1]))
			{
				case -1:
					i++;
					break;
				case 0:
					sum += (a[i++][2] * newB[j++][2]);
					break;
				case 1:
					j++;
			}
		}

		for (; a[i][0] == row; i++);
		rowBegin = i;
		row = a[i][0];

	}

	d[0][0] = rowsA;
	d[0][1] = colsB;
	d[0][2] = totalD;

}

void storeSum(int d[][N], int* totalD, int row, int col, int* sum)
{
	if (*sum)
	{
		if (*totalD < MAX_TERMS)
		{
			d[++ * totalD][0] = row;
			d[*totalD][1] = col;
			d[*totalD][2] = *sum;
			*sum = 0;
		}
		else
		{
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			exit(1);
		}
	}
}

int COMPARE(int a, int b)
{
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}