#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
	int id;
	int height;
	int weight;
	Person(int _id, int _height, int _weight) : id(_id), height(_height),
		weight(_weight) {}
	// 先按照身高由低到高排序
	bool operator < (const Person& p) const
	{
		if (this->height < p.height)
		{
			return true;
		}
		else if (this->height > p.height)
		{
			return false;
		}
		else
		{
			if (this->weight <= p.weight)
			{
				return true;
			}
			return false;
		}
	}
};

vector<Person> LongestTower(vector<Person> &vec);

void TestLongestTower();


int LongestIncreaseSequence(int arr[], int n);

int ** my2DAlloc(int rows, int cols);
void TestMy2DAlloc();


int ** my2DAlloc2(int rows, int cols);
