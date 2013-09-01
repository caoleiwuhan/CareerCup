#include <iostream>
#include <vector>

using namespace std;

/*
	自底向上：f[i][j] 从（0,0）到（x，y）的路径个数
*/
int BoxPathCount1(int x, int y);

/*
	自底向上：滚动数组
*/
int BoxPathCount2(int x, int y);

/*
	自顶向下：应用记录数组
*/
int BoxPathCount3(int x, int y);

int BoxPathCount3Help(int **f, int x, int y);

struct Pair
{
	int x;
	int y;
	Pair(int _x, int _y) : x(_x), y(_y) {}
};

int BoxPathCount4(int x, int y, vector<Pair> &vec);

int BoxPathCount4Help(int **f, int x, int y, vector<Pair> &vec);

void TestBoxPathCount();