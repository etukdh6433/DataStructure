#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int*** make3dArray(int deps, int rows, int cols);
void printArray(int*** Array, int deps, int rows, int cols);
int*** sumArray(int ***Array1, int ***Array2, int ***Array3, int deps, int rows, int cols);
void freeArray(int***A, int deps, int rows, int cols);


int main(void)
{
	int N[3] = { 3, 5, 4 };

	int*** myArray1;
	int*** myArray2;
	int*** answerArray;

	myArray1 = make3dArray(N[0], N[1], N[2]);
	myArray2 = make3dArray(N[0], N[1], N[2]);
	answerArray = make3dArray(N[0], N[1], N[2]);

	for (int i = 0; i < N[0]; i++)
	{
		for (int j = 0; j < N[1]; j++)
		{
			for (int k = 0; k < N[2]; k++)
			{
				myArray1[i][j][k] = rand() % 9 + 1;
				myArray2[i][j][k] = rand() % 9 + 1;
			}
		}
	}

	answerArray = sumArray(myArray1, myArray2, answerArray, N[0], N[1], N[2]);

	printf("Array1 : ");
	printArray(myArray1, N[0], N[1], N[2]);
	printf("\n");
	printf("Array2 : ");
	printArray(myArray2, N[0], N[1], N[2]);
	printf("\n");
	printf("answerArray : ");
	printArray(answerArray, N[0], N[1], N[2]);

	for (int i = 0; i < N[0]; i++)
	{
		for (int j = 0; j < N[1]; j++)
		{
			free(myArray1[i][j]);
		}
	}

	for (int i = 0; i < N[0]; i++)
	{
		free(myArray1[i]);
	}

	free(myArray1);

	for (int i = 0; i < N[0]; i++)
	{
		for (int j = 0; j < N[1]; j++)
		{
			free(myArray2[i][j]);
		}
	}

	for (int i = 0; i < N[0]; i++)
	{
		free(myArray2[i]);
	}

	free(myArray2);

	for (int i = 0; i < N[0]; i++)
	{
		for (int j = 0; j < N[1]; j++)
		{
			free(answerArray[i][j]);
		}
	}

	for (int i = 0; i < N[0]; i++)
	{
		free(answerArray[i]);
	}

	free(answerArray);

	return 0;
}

int*** make3dArray(int deps, int rows, int cols)
{
	int*** A = 0;

	A = (int***)malloc(sizeof(int**) * deps);

	for (int i = 0; i < deps; i++)
	{
		A[i] = (int**)malloc(sizeof(int*) * rows);
		
		for (int j = 0; j < rows; j++)
		{
			A[i][j] = (int*)malloc(sizeof(int) * cols);
		}
	}

	return A;
}

void printArray(int*** Array, int deps, int rows, int cols)
{
	printf("\n{");
	for (int i = 0; i < deps; i++)
	{
		printf("\n	{");
		for (int j = 0; j < rows; j++)
		{
			printf("\n		{");
			for (int k = 0; k < cols; k++)
			{
				printf("%5d", Array[i][j][k]);
			}
			printf("}\n");
		}
		printf("	}\n");
	}
	printf("}\n");

}

int ***sumArray(int*** Array1, int ***Array2, int ***Array3, int deps, int rows, int cols)
{
	for (int i = 0; i < deps; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				Array3[i][j][k] = Array1[i][j][k] + Array2[i][j][k];
			}
		}
	}

	return Array3;
}

void freeArray(int ***A, int deps, int rows, int cols)
{
	for (int i = 0; i < deps; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			free(A[i][j]);
		}
	}

	for (int i = 0; i < deps; i++)
	{
		free(A[i]);
	}

	free(A); // C¾ð¾î
}