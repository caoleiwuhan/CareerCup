#include <iostream>
#include <vector>

using namespace std;

struct Box
{
	int weight;
	int hight;
	int depth;
	Box(int _weight, int _hight, int _depth) : weight(_weight), 
		hight(_hight), depth(_depth) {}
};

int BoxHight(vector<Box> &vec, vector<Box> &ans);

void BoxHightDFS(vector<Box> &vec, vector<Box> &ans, bool used[], int step, 
	int &best, vector<Box> &cur, int curDepth);

void TestBoxHight();