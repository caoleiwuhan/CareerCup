#include <iostream>

#include "1_6_RotateMatrix.h"

using namespace std;

void RotateMatrix(int matrix[][N])
{
	int count = (N / 2);
	// 每次转动一个圆，
	for (int i = 0; i < count; ++i)
	{
		// 每次圆的边长为(N - i * 2 - 1)
		int len = N - i * 2 - 1;
		int size = N - 1;
		for (int j = 0; j < len; ++j)
		{
			int tmp = matrix[i][i + j];
			matrix[i][i + j] = matrix[size - i - j][i];
			matrix[size - i - j][i] = matrix[size - i][size - i - j];
			matrix[size - i][size - i - j] = matrix[i + j][size - i];
			matrix[i + j][size - i] = tmp;
		}
	}
}

void PrintMatrix(int matrix[][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			//cout << matrix[i][j] << ' ';
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void TestRotateMatrix()
{
	int matrix[5][5] = 
	{
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16,
		17, 18, 19, 20,
		21, 22, 23, 24, 25
	};
	PrintMatrix(matrix);

	RotateMatrix(matrix);

	PrintMatrix(matrix);
}