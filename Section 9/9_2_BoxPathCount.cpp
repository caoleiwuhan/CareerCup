#include <iostream>

#include "9_2_BoxPathCount.h"

using namespace std;

int BoxPathCount(int x, int y)
{
	if (x <= 0 && y <= 0)
		return 0;
	int **f = new int *[x + 1];
	for (int i = 0; i <= x; ++i)
	{
		f[i] = new int[y + 1];
	}
	// 初始化
	for (int i = 0; i <= x; ++i)
		for (int j = 0; j <= y; ++j)
		{
			f[i][j] = 0;
		}
	for (int i = 0; i <= x; ++i)
		f[i][0] = 1;
	for (int j = 0; j <= y; ++j)
		f[0][j] = 1;

	f[0][0] = 0;
	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= y; ++j)
		{
			f[i][j] = f[i][j-1] + f[i-1][j];
		}
	}

	int ans = f[x][y];
	// 数组销毁
	for (int i = 0; i <= x; ++i)
	{
		delete []f[i];
	}
	delete []f;
	return ans;
}

void TestBoxPathCount()
{
	cout << BoxPathCount(3, 3) << endl;
	cout << BoxPathCount(4, 3) << endl;
	cout << BoxPathCount(2, 3) << endl;
	cout << BoxPathCount(1, 3) << endl;
	cout << BoxPathCount(0, 3) << endl;

	cout << "******************************" << endl;
	cout << BoxPathCount2(3, 3) << endl;
	cout << BoxPathCount2(4, 3) << endl;
	cout << BoxPathCount2(2, 3) << endl;
	cout << BoxPathCount2(1, 3) << endl;
	cout << BoxPathCount2(0, 3) << endl;

	cout << "******************************" << endl;
	cout << BoxPathCount3(3, 3) << endl;
	cout << BoxPathCount3(4, 3) << endl;
	cout << BoxPathCount3(2, 3) << endl;
	cout << BoxPathCount3(1, 3) << endl;
	cout << BoxPathCount3(0, 3) << endl;

	cout << "******************************" << endl;

	vector<Pair> vec;
	vec.push_back(Pair(1, 0));

	cout << BoxPathCount4(1, 1, vec) << endl;	
	cout << BoxPathCount4(1, 2, vec) << endl;

}

int BoxPathCount2(int x, int y)
{
	if (x <= 0 && y <= 0)
		return 0;

	int **f = new int*[2];
	for (int i = 0; i < 2; ++i)
	{
		f[i] = new int[y + 1];
	}
	
	for (int i = 1; i <= y; ++i)
	{
		f[0][i] = 1;
	}
	int flag = 0;
	for (int i = 1; i <= x; ++i)
	{
		int index = 1 - flag;
		for (int j = 0; j <= y; ++j)
		{
			if (j == 0)
			{
				f[index][j] = 1;
			}
			else
			{
				f[index][j] = f[flag][j] + f[index][j - 1];
			}
		}
		flag = 1 - flag;
	}

	int ans = f[flag][y];

	for (int i = 0; i < 2; ++i)
		delete []f[i];
	delete[] f;

	return ans;
}


int BoxPathCount3(int x, int y)
{
	int **f = new int *[x + 1];
	for (int i = 0; i <= x; ++i)
		f[i] = new int[y];

	// 初始化
	for (int i = 0; i <= x; ++i)
	{
		for (int j = 0; j <= y; ++j)
		{
			f[i][j] = 0;
		}
	}

	int ans = BoxPathCount3Help(f, x, y);

	// 释放内存出问题！！！
	/*for (int i = 0; i <= x; ++i)
	{
		delete []f[i];
	}

	delete []f;*/

	return ans;
}

int BoxPathCount3Help(int **f, int x, int y)
{
	if (x == 0 && y == 0)
		return 0;
	if (x == 0 || y == 0)
		return 1;
	if (f[x][y] != 0)
		return f[x][y];
	f[x][y] = BoxPathCount3Help(f, x - 1, y) + BoxPathCount3Help(f, x, y - 1);

	return f[x][y];
}

int BoxPathCount4(int x, int y, vector<Pair> &vec)
{
	int **f = new int *[x + 1];
	for (int i = 0; i <= x; ++i)
	{
		f[i] = new int[y + 1];
	}

	// 初始化
	for (int i = 0; i <= x; ++i)
	{
		for (int j = 0; j <= y; ++j)
		{
			f[i][j] = 0;
		}
	}

	int ans = BoxPathCount4Help(f, x, y, vec);

	for (int i = 0; i <= x; ++i)
	{
		delete []f[i];
	}
	delete []f;

	return ans;
}

int BoxPathCount4Help(int **f, int x, int y, vector<Pair> &vec)
{
	if (x == 0 && y == 0)
		return 0;
	if (f[x][y] != 0)
		return f[x][y];

	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		if (x == vec[i].x && y == vec[i].y)
		{
			return 0;
		}
	}

	if (x == 0 || y == 0)
	return 1;

	f[x][y] = BoxPathCount4Help(f, x - 1, y, vec) + BoxPathCount4Help(f, x, y - 1, vec);

	return f[x][y];
}