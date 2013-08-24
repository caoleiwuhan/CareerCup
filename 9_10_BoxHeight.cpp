#include <iostream>

#include "9_10_BoxHeight.h"

using namespace std;

int BoxHight(vector<Box> &vec, vector<Box> &ans)
{
	vector<Box> cur;
	int best = 0;
	bool *used = new bool[vec.size()];
	memset(used, 0, sizeof(bool) * vec.size());
	BoxHightDFS(vec, ans, used, 0, best, cur, 0);
	delete []used;
	return best;
}

void BoxHightDFS(vector<Box> &vec, vector<Box> &ans, bool used[], int step, 
	int &best, vector<Box> &cur, int curDepth)
{
	bool isFinished = true;
	for (int i = 0; i < vec.size(); ++i)
	{
		bool isOK = false;
		if (!used[i])
		{				
			Box b1 = vec[i];
				
			if (cur.size() == 0)
			{					
				isOK = true;
			}
			else
			{
				Box b2 = cur[cur.size() - 1];
				if (b1.weight < b2.weight &&
					b1.hight < b2.hight &&
					b1.depth < b2.depth)
				{
					isOK = true;
				}
			}
			if (isOK)
			{
				isFinished = false;
				cur.push_back(b1);
				used[i] = true;
				BoxHightDFS(vec, ans, used, step + 1, best, cur, curDepth + b1.depth);
				cur.pop_back();
				used[i] = false;
			}
		}
	}
	if (isFinished)
	{
		if (curDepth > best)
		{
			best = curDepth;
		}
	}
}