#include <iostream>
#include <vector>

using namespace std;

/*
	�Ե����ϣ�f[i][j] �ӣ�0,0������x��y����·������
*/
int BoxPathCount1(int x, int y);

/*
	�Ե����ϣ���������
*/
int BoxPathCount2(int x, int y);

/*
	�Զ����£�Ӧ�ü�¼����
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