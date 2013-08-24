#include <iostream>
#include <vector>

#include "11_6_MatrixFindNum.h"
using namespace std;


vector<int> spiralOrder(vector<vector<int> > &arr) 
{
    vector<int> ans;
    int row = arr.size();
    if (row == 0)
        return ans;
    int col = arr[0].size();
    if (col == 0)
        return ans;
            
    int left = 0;
    int right = col - 1;
    int up = 0;
    int down = row - 1;
    int count = (row + 1) >> 1;
    int i = 0, j = 0;
    while (count--)
    {
        while (j <= right)
        {
            ans.push_back(arr[i][j]);
            ++j;
        }
		--j;
        ++up;
		if (up >= row)
			break;
        ++i;
        while (i <= down)
        {
            ans.push_back(arr[i][j]);
            ++i;
        }
		--i;
        --right;
		if (right < 0)
			break;
        --j;
        while (j >= left)
        {
            ans.push_back(arr[i][j]);
            --j;
        }
		++j;
        --down;
		if (down < 0)
			break;

        --i;
        while (i >= up)
        {
            ans.push_back(arr[i][j]);
            --i;
        }
		++i;
        ++left;
		if (left >= col)
			break;
        ++j;
          
    }
    return ans;
}


vector<int> spiralOrder2(vector<vector<int> > &arr) 
{
    vector<int> ans;
    int row = arr.size();
    if (row == 0)
        return ans;
    int col = arr[0].size();
    if (col == 0)
        return ans;
            
    int left = 0;
    int right = col - 1;
    int up = 0;
    int down = row - 1;
    int count = (row + 1) >> 1;
    int i = 0, j = 0;
    while (count--)
    {
        while (j <= right)
        {
            ans.push_back(arr[i][j]);
            ++j;
        }
		--j;
        ++up;
		if (up >= row)
			break;
        ++i;
        while (i <= down)
        {
            ans.push_back(arr[i][j]);
            ++i;
        }
		--i;
        --right;
		if (right < 0)
			break;

        --j;
        while (j >= left)
        {
            ans.push_back(arr[i][j]);
            --j;
        }
		++j;
        --down;
		if (down < 0)
			break;

        --i;
        while (i >= up)
        {
            ans.push_back(arr[i][j]);
            --i;
        }
		++i;
        ++left;
		if (left >= col)
			break;
        ++j;
          
    }
    return ans;
}

vector<vector<int> > generateMatrix(int n) 
{
    vector<vector<int> >ans;
        
    if (n == 0)
        return ans;
    for (int i = 0; i < n; ++i)
    {
        vector<int> vec(n, 0);
        ans.push_back(vec);
    }
        
    int tot = 1;
    int x = 0;
    int y = 0;
        
    int l = 0;
    int r = n - 1;
    int u = 0;
    int d = n - 1;
        
    while (tot <= n * n)
    {
        while (y <= r)
        {
            ans[x][y] = tot++;
            ++y;
        }
        ++x;
        --y;
        ++u;
        if (u > d)
            break;
        while (x <= d)
        {
            ans[x][y] = tot++;
            ++x;
        }
        --x;
        --y;
        --r;
        if (r < l)
            break;
        while (y >= l)
        {
            ans[x][y] = tot++;
            --y;
        }
        ++y;
        --x;
        --d;
        if (d < u)
            break;
        while (x >= u)
        {
            ans[x][y] = tot++;
            --x;
        }
        ++x;
        ++y;
        ++l;
        if (l > r)
            break;
    }
    return ans;
}

void TestSpiralOrder()
{
	vector<vector<int> > arr;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	arr.push_back(v1);
	
	//vector<int> v2;
	//v2.push_back(3);
	//v2.push_back(4);
	//arr.push_back(v2);


	//vector<int> ans = spiralOrder(arr);
	vector<vector<int> > ans = generateMatrix(1);	
}