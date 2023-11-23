#include <stdio.h>
#include <stdlib.h>
#include <random>

int randomInteger()
{
	int x, n;
	int isEven = rand() % 2;
	if (isEven == 1)
	{
		n = 1;
	}
	else if (isEven == 0)
	{
		n = -1;
	}
	x = n * (rand() % 100);
	return x;
}

void clear(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void printMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int determinant(int** matrix, int n)
{
	int a, b;
	int d = 0;
	int evenSign = 1;
	int** temp = (int**)malloc((n) * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		temp[i] = (int*)malloc((n) * sizeof(int));
	}
	if (n == 1)
	{
		return matrix[0][0];
	}
	else if (n == 2)
	{
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	}
	else
	{
		for (int x = 0; x < n; x++)
		{
			a = 0;
			for (int i = 1; i < n; i++)
			{
				b = 0;
				for (int j = 0; j < n; j++)
				{
					if (j != x)
					{
						temp[a][b] = matrix[i][j];
						b++;
					}

				}
				a++;

			}
			d += (evenSign * matrix[0][x] * determinant(temp, n - 1));
			evenSign = -evenSign;
		}
	}
	clear(temp, n);
	return d;
}
void test()
{
	int n = 3;
	int numbersForTestTwo[3][3] = {2,3,2,0,6,7,9,2,0};
	int** testOne = (int**)malloc(n * sizeof(int*));
	int** testTwo = (int**)malloc(n * sizeof(int*));		//по окончании цикла
	for (int i = 0; i < n; i++)								//матрица будет выглядеть так:
	{														//| 1	2	3 |
		testOne[i] = (int*)malloc(n * sizeof(int));			//| 2	3	4 |
		for (int j = 0; j < n; j++)							//| 3	4	5 |
		{
			testOne[i][j] = i + j + 1;						
		}
	}
	printMatrix(testOne, n);
	if (determinant(testOne, n) == 0)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("fail!\n");
	}														//по окончании цикла
	for (int i = 0; i < n; i++)								//матрица будет выглядеть так:
	{														//| 2	3	2 |
		testTwo[i] = (int*)malloc(n * sizeof(int));			//| 0	6	7 |
		for (int j = 0; j < n; j++)							//| 9	2	0 |
		{
			testTwo[i][j] = numbersForTestTwo[i][j];
		}
	}
	printMatrix(testTwo, n);
	if (determinant(testTwo, n) == 53)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("fail!\n");
	}
	clear(testOne, n);
	clear(testTwo, n);
}
int **addNumbers(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = randomInteger();
		}
	}
	return matrix;
}

int main()
{
	test();
	srand(time(NULL));
	int n;
	scanf_s("%d", &n);

	int **matrix = (int**)malloc(n*sizeof(int*));
	matrix = addNumbers(matrix, n);
	printMatrix(matrix,n);
	
	printf("%d\n", determinant(matrix,n));

	clear(matrix,n);
	return 0;
}