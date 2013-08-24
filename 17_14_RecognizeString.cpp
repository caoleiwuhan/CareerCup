#include <iostream>

#include <vector>
#include <string>

using namespace std;

vector<string> RecognizeString(string str, vector<string> dictionary)
{
	vector<string> ans;
	return ans;
}

void TestRecogninzeString()
{
	
}

int minimumTotal(vector<vector<int> > &vec) 
{
    int row = vec.size();    
    int **f = new int*[row + 1];

    for (int i = 0; i <= row; ++i)
    {
        f[i] = new int[row + 1];
        memset(f[i], 0, sizeof(int) * (row + 1));
    }    
        
    f[0][0] = vec[0][0];
    for (int i = 1; i < row; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            int tmp = 0x7FFFFFFF;
            // 如果上一行第一个有
            if (j - 1 >= 0)
            {
                tmp = min(tmp, f[i-1][j-1]);
            }
            if (j < i)
            {
                tmp = min(tmp, f[i-1][j]);                    
            }
            tmp += vec[i][j];
            f[i][j] = tmp;
        }
    }
    int ans = 0x7FFFFFFF;        
    for (int i = 0; i < row; ++i)
    {
        ans = min(ans, f[row - 1][i]);
    }    
        
    for (int i = 0; i <= row; ++i)
    {
        delete[] f[i];
    }
    delete [] f;
        
    return ans;
}

vector<vector<int> > generate(int row) 
{   
    vector<vector<int> > ans;
    if (row == 0)
    {
        return ans;
    }
    for (int i = 0; i < row; ++i)
    {
        vector<int> vec;
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                vec.push_back(1);
            }
            else
            {
                vec.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
        }
        ans.push_back(vec);
    }
    return ans;
}

vector<int> getRow(int row) 
{
	 ++row;
    vector<vector<int> > ans;
    vector<int> v1(row, 1);
    ans.push_back(v1);
    vector<int> v2(row, 1);
    ans.push_back(v2);
        
 
    int flag = 0;
        
    for (int i = 0; i < row; ++i)
    {            
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                ans[1 - flag][j] = 1;
            }
            else
            {
                ans[1 - flag][j] = ans[flag][j-1] + ans[flag][j];
            }
        }
        flag = 1 - flag;
    }
    return ans[flag]; 
}

void TestGenerate()
{
	//vector<vector<int> > ans = generate(2);
	vector<int> ans = getRow(0);
}
