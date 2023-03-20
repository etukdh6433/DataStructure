#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 9
#define MAX 50

typedef struct {
	int row;
	int col;
	int val;
}term;

void transpose (term a[], term b[]);
void mmult(term a[], term b[], term d[]);
void storeSum(term d[], int* totalD, int row, int col, int* sum);
int COMPARE(int x, int y);

int main(void)
{
	term A[MAX_TERMS] = { 6,6,8,0,0,15,0,3,22,0,5,-15,1,1,11,1,2,3,2,3,-6,4,0,91,5,2,28 };
	term B[MAX_TERMS];
	term D[MAX];

	printf("A : \n\n");

	for (int i = 0; i < MAX_TERMS; i++)
	{
		printf("%10d%10d%10d", A[i].row, A[i].col, A[i].val);
		printf("\n");
	}

	transpose(A, B);

	printf("\n");
	printf("transpose(A) : \n\n");

	for (int i = 0; i < MAX_TERMS; i++)
	{
		printf("%10d%10d%10d", B[i].row, B[i].col, B[i].val);
		printf("\n");
	}

	mmult(A, B, D);

	return 0;
}

void transpose(term a[], term b[])
{
	int n, i, j, currentb;
	n = a[0].val;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].val = n;

	if (n > 0)
	{
		currentb = 1;
		for (i = 0; i < a[0].col; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (a[j].col == i)
				{
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].val = a[j].val;
					currentb++;
				}
			}
		}
	}
}

void mmult(term a[], term b[], term d[])
{
	int i, j, col, totalD = 0;
	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].val;
	int colsB = b[0].col, totalB = b[0].val;
	int rowBegin = 1, row = a[1].row, sum = 0;
	term newB[MAX_TERMS];

	if (colsA != b[0].row)
	{
		fprintf(stderr, "Incompatible matrices\n");
		exit(1);
	}

	transpose(b, newB);

	// 경계조건 설정
	/*a[totalA + 1].row = rowsA;
	newB[totalB + 1].row = colsB;
	newB[totalB + 1].col = 0;*/

	for (i = 1; i < totalA;)
	{
		col = newB[1].row;
		
		for (j = 1; j <= totalB + 1;)
		{
			if (a[i].row != row)
			{
				storeSum(d, &totalD, row, col, &sum);
				i = rowBegin;
				for (; newB[j].row == col; j++);
				col = newB[j].row;
			}
			else if (newB[j].row != col)
			{
				storeSum(d, &totalD, row, col, &sum);
				i = rowBegin;
				col = newB[j].row;
			}
			else switch (COMPARE(a[i].col, newB[j].col))
			{
				case -1:
					i++;
					break;
				case 0:
					sum += (a[i++].val * newB[j++].val);
					break;
				case 1:
					j++;
			}
		}

		for (; a[i].row == row; i++);
		rowBegin = i;
		row = a[i].row;

	}

	d[0].row = rowsA;
	d[0].col = colsB;
	d[0].val = totalD;

	printf("\n");
	printf("A X B : \n\n");

	for (int i = 0; i < d[0].val + 1; i++)
	{
		printf("%10d%10d%10d", d[i].row, d[i].col, d[i].val);
		printf("\n");
	}

}

void storeSum(term d[], int* totalD, int row, int col, int* sum)
{
	if (*sum)
	{
		if (*totalD < MAX_TERMS)
		{
			d[++ * totalD].row = row;
			d[*totalD].col = col;
			d[*totalD].val = *sum;
			*sum = 0;
		}
		else
		{
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			exit(1);
		}
	}
}

int COMPARE(int x, int y)
{
	if (x > y)
		return 1;
	else if (x == y)
		return 0;
	else
		return -1;
}