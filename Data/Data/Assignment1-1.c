//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//
//int*** make3darray(int deps, int rows, int cols);
//void printarray(int*** array, int deps, int rows, int cols);
//int*** sumarray(int ***array1, int ***array2, int ***array3, int deps, int rows, int cols);
//void freearray(int***a, int deps, int rows, int cols);
//
//
//int main(void)
//{
//	int n[3] = { 3, 5, 4 };
//
//	int*** myarray1;
//	int*** myarray2;
//	int*** answerarray;
//
//	myarray1 = make3darray(n[0], n[1], n[2]);
//	myarray2 = make3darray(n[0], n[1], n[2]);
//	answerarray = make3darray(n[0], n[1], n[2]);
//
//	for (int i = 0; i < n[0]; i++)
//	{
//		for (int j = 0; j < n[1]; j++)
//		{
//			for (int k = 0; k < n[2]; k++)
//			{
//				myarray1[i][j][k] = rand() % 9 + 1;
//				myarray2[i][j][k] = rand() % 9 + 1;
//			}
//		}
//	}
//
//	answerarray = sumarray(myarray1, myarray2, answerarray, n[0], n[1], n[2]);
//
//	printf("array1 : ");
//	printarray(myarray1, n[0], n[1], n[2]);
//	printf("\n");
//	printf("array2 : ");
//	printarray(myarray2, n[0], n[1], n[2]);
//	printf("\n");
//	printf("answerarray : ");
//	printarray(answerarray, n[0], n[1], n[2]);
//
//	for (int i = 0; i < n[0]; i++)
//	{
//		for (int j = 0; j < n[1]; j++)
//		{
//			free(myarray1[i][j]);
//		}
//	}
//
//	for (int i = 0; i < n[0]; i++)
//	{
//		free(myarray1[i]);
//	}
//
//	free(myarray1);
//
//	for (int i = 0; i < n[0]; i++)
//	{
//		for (int j = 0; j < n[1]; j++)
//		{
//			free(myarray2[i][j]);
//		}
//	}
//
//	for (int i = 0; i < n[0]; i++)
//	{
//		free(myarray2[i]);
//	}
//
//	free(myarray2);
//
//	for (int i = 0; i < n[0]; i++)
//	{
//		for (int j = 0; j < n[1]; j++)
//		{
//			free(answerarray[i][j]);
//		}
//	}
//
//	for (int i = 0; i < n[0]; i++)
//	{
//		free(answerarray[i]);
//	}
//
//	free(answerarray);
//
//	return 0;
//}
//
//int*** make3darray(int deps, int rows, int cols)
//{
//	int*** a = 0;
//
//	a = (int***)malloc(sizeof(int**) * deps);
//
//	for (int i = 0; i < deps; i++)
//	{
//		a[i] = (int**)malloc(sizeof(int*) * rows);
//		
//		for (int j = 0; j < rows; j++)
//		{
//			a[i][j] = (int*)malloc(sizeof(int) * cols);
//		}
//	}
//
//	return a;
//}
//
//void printarray(int*** array, int deps, int rows, int cols)
//{
//	printf("\n{");
//	for (int i = 0; i < deps; i++)
//	{
//		printf("\n	{");
//		for (int j = 0; j < rows; j++)
//		{
//			printf("\n		{");
//			for (int k = 0; k < cols; k++)
//			{
//				printf("%5d", array[i][j][k]);
//			}
//			printf("}\n");
//		}
//		printf("	}\n");
//	}
//	printf("}\n");
//
//}
//
//int ***sumarray(int*** array1, int ***array2, int ***array3, int deps, int rows, int cols)
//{
//	for (int i = 0; i < deps; i++)
//	{
//		for (int j = 0; j < rows; j++)
//		{
//			for (int k = 0; k < cols; k++)
//			{
//				array3[i][j][k] = array1[i][j][k] + array2[i][j][k];
//			}
//		}
//	}
//
//	return array3;
//}
//
//void freearray(int ***a, int deps, int rows, int cols)
//{
//	for (int i = 0; i < deps; i++)
//	{
//		for (int j = 0; j < rows; j++)
//		{
//			free(a[i][j]);
//		}
//	}
//
//	for (int i = 0; i < deps; i++)
//	{
//		free(a[i]);
//	}
//
//	free(a); // c¾ğ¾î
//}