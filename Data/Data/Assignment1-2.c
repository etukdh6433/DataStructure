//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define max_terms 9
//#define max 50
//
//typedef struct {
//	int row;
//	int col;
//	int val;
//}term;
//
//void transpose (term a[], term b[]);
//void mmult(term a[], term b[], term d[]);
//void storesum(term d[], int* totald, int row, int col, int* sum);
//int compare(int x, int y);
//
//int main(void)
//{
//	term a[max_terms] = { 6,6,8,0,0,15,0,3,22,0,5,-15,1,1,11,1,2,3,2,3,-6,4,0,91,5,2,28 };
//	term b[max_terms];
//	term d[max];
//
//	printf("a : \n\n");
//
//	for (int i = 0; i < max_terms; i++)
//	{
//		printf("%10d%10d%10d", a[i].row, a[i].col, a[i].val);
//		printf("\n");
//	}
//
//	transpose(a, b);
//
//	printf("\n");
//	printf("transpose(a) : \n\n");
//
//	for (int i = 0; i < max_terms; i++)
//	{
//		printf("%10d%10d%10d", b[i].row, b[i].col, b[i].val);
//		printf("\n");
//	}
//
//	mmult(a, b, d);
//
//	return 0;
//}
//
//void transpose(term a[], term b[])
//{
//	int n, i, j, currentb;
//	n = a[0].val;
//	b[0].row = a[0].col;
//	b[0].col = a[0].row;
//	b[0].val = n;
//
//	if (n > 0)
//	{
//		currentb = 1;
//		for (i = 0; i < a[0].col; i++)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				if (a[j].col == i)
//				{
//					b[currentb].row = a[j].col;
//					b[currentb].col = a[j].row;
//					b[currentb].val = a[j].val;
//					currentb++;
//				}
//			}
//		}
//	}
//}
//
//void mmult(term a[], term b[], term d[])
//{
//	int i, j, col, totald = 0;
//	int rowsa = a[0].row, colsa = a[0].col, totala = a[0].val;
//	int colsb = b[0].col, totalb = b[0].val;
//	int rowbegin = 1, row = a[1].row, sum = 0;
//	term newb[max_terms];
//
//	if (colsa != b[0].row)
//	{
//		fprintf(stderr, "incompatible matrices\n");
//		exit(1);
//	}
//
//	transpose(b, newb);
//
//	// 경계조건 설정
//	/*a[totala + 1].row = rowsa;
//	newb[totalb + 1].row = colsb;
//	newb[totalb + 1].col = 0;*/
//
//	for (i = 1; i < totala;)
//	{
//		col = newb[1].row;
//		
//		for (j = 1; j <= totalb + 1;)
//		{
//			if (a[i].row != row)
//			{
//				storesum(d, &totald, row, col, &sum);
//				i = rowbegin;
//				for (; newb[j].row == col; j++);
//				col = newb[j].row;
//			}
//			else if (newb[j].row != col)
//			{
//				storesum(d, &totald, row, col, &sum);
//				i = rowbegin;
//				col = newb[j].row;
//			}
//			else switch (compare(a[i].col, newb[j].col))
//			{
//				case -1:
//					i++;
//					break;
//				case 0:
//					sum += (a[i++].val * newb[j++].val);
//					break;
//				case 1:
//					j++;
//			}
//		}
//
//		for (; a[i].row == row; i++);
//		rowbegin = i;
//		row = a[i].row;
//
//	}
//
//	d[0].row = rowsa;
//	d[0].col = colsb;
//	d[0].val = totald;
//
//	printf("\n");
//	printf("a x b : \n\n");
//
//	for (int i = 0; i < d[0].val + 1; i++)
//	{
//		printf("%10d%10d%10d", d[i].row, d[i].col, d[i].val);
//		printf("\n");
//	}
//
//}
//
//void storesum(term d[], int* totald, int row, int col, int* sum)
//{
//	if (*sum)
//	{
//		if (*totald < max_terms)
//		{
//			d[++ * totald].row = row;
//			d[*totald].col = col;
//			d[*totald].val = *sum;
//			*sum = 0;
//		}
//		else
//		{
//			fprintf(stderr, "numbers of terms in product exceeds %d\n", max_terms);
//			exit(1);
//		}
//	}
//}
//
//int compare(int x, int y)
//{
//	if (x > y)
//		return 1;
//	else if (x == y)
//		return 0;
//	else
//		return -1;
//}