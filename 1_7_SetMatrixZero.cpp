#include <iostream>

#include "1_7_SetMatrixZero.h"

using namespace std;



void SetMatrixZero(int **matrix, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = MAX_INT;
			}
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (matrix[i][j] == MAX_INT)
			{
				// the same row
				for (int k = 0; k < col; ++k)
				{
					if (matrix[i][k] != MAX_INT)
					{
						matrix[i][k] = 0;
					}
				}
				// the same col
				for (int k = 0; k < row; ++k)
				{
					if (matrix[k][j] != MAX_INT)
					{
						matrix[k][j] = 0;
					}
				}
				matrix[i][j] = 0;
			}
		}
	}
}

void TestSetMatrixZero()
{
	int row = 4;
	int col = 3;

	int **matrix = new int *[4];
	for (int i = 0; i < row; ++i)
	{
		matrix[i]= new int[3];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			matrix[i][j] = i + j + 1;
		}
	}

	matrix[1][1] = 0;
	//matrix[2][2] = 0;

	PrintMatrix2(matrix, 4, 3);
	SetMatrixZero2(matrix, 4, 3);
	PrintMatrix2(matrix, 4, 3);


	for (int i = 0; i < row; ++i)
	{
		delete []matrix[i];
	}
	delete[] matrix;
}

void PrintMatrix2(int **matrix, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void SetMatrixZero2(int **matrix, int row, int col)
{
	bool *rowFlag = new bool[row];
	bool *colFlag = new bool[col];
	memset(rowFlag, 0, sizeof(bool) * row);
	memset(colFlag, 0, sizeof(bool) * col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (matrix[i][j] == 0)
			{
				rowFlag[i] = true;
				colFlag[j] = true;
			}
		}
	}
	for (int i = 0; i < row; ++i)
	{
		if (rowFlag[i])
		{
			for (int k = 0; k < col; ++k)
			{
				matrix[i][k] = 0;
			}
		}
	}
	for (int i = 0; i < col; ++i)
	{
		if (colFlag[i])
		{
			for (int k = 0; k < row; ++k)
			{
				matrix[k][i] = 0;
			}
		}
	}
	delete[]rowFlag;
	delete[]colFlag;
}