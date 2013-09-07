#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    最长递增子序列
*/
int maxIncreaseSequence(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[i] >= arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n-1];
}

/*
    2:导弹拦截
        1：最多拦截多少导弹
        2：要拦截所有导弹，最少需要几套系统
            在已知序列中找最长上升序列！！！
*/
int missiles(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[i] <= arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n-1];
}
/*
    至少需要几套
*/
int missiles2(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    // dp[i]表示第i套最后的高度
    dp[0] = arr[0];
    int cur = 1;
    for (int i = 1; i < n; ++i)
    {
        int tmp = -1;
        for (int j = 0; j < cur; ++j)
        {
            if (dp[j] >= arr[i])
            {
                if (tmp == -1)
                {
                    tmp = j;
                }
                else
                { // 要保留尽量高的
                    if (dp[tmp] > dp[j])
                    {
                        tmp = j;
                    }
                }
            }
        }
        if (tmp != -1)
        {
            dp[tmp] = arr[i];
        }
        else
        {
            dp[cur++] = arr[i];
        }
    }
    return cur;
}

int missiles3(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i-1; j >= 0; --j)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

void testMissiles()
{
    int arr[] =
    {
        389, 207, 155, 300, 299, 170, 158, 65
    };
    cout << missiles(arr, sizeof(arr) / sizeof(int)) << endl;
    cout << missiles2(arr, sizeof(arr) / sizeof(int)) << endl;
    cout << missiles3(arr, sizeof(arr) / sizeof(int)) << endl;
}

/*
    三：合唱队形
*/
int singerQueue(int arr[], int n)
{
    vector<int> dp1(n, 1);
    dp1[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    vector<int> dp2(n, 1);
    dp2[n-1] = 1;
    for (int i = n-2; i >= 0; --i)
    {
        for (int j = n-2; j > i; --j)
        {
            if (arr[i] > arr[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    return (n - ans);
}

void testSingerQueue()
{
    int arr[] =
    {
        186, 186, 150, 200, 160, 130, 197, 220
    };
    cout << singerQueue(arr, sizeof(arr) / sizeof(int)) << endl;
}

/*
    逢低吸纳：
        每次买入的价格都比上一次的低
        最长下降子序列
*/
int buyLowBuyLower(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i-1; j >= 0; --j)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


/*
	ships
*/
struct Friends
{
	int num1;
	int num2;
};

bool friendSort(const Friends &f1, const Friends &f2)
{
	if (f1.num1 < f2.num1)
		return true;
	else if (f1.num1 > f2.num1)
		return false;
	else
		return f1.num2 <= f2.num2;
}

void ships()
{
	Friends fris[101];
	int riverLong, riverWide;
	while (cin >> riverLong >> riverWide)
	{
		if (riverLong == 0 && riverWide == 0)
		{
			break;
		}
		int N = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			Friends f;
			cin >> f.num1 >> f.num2;
			fris[i] = f;
		}
		sort(fris, fris + N, friendSort);
		vector<int> dp(N, 1);
		int ans = 1;
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < i; ++i)
			{
				if (fris[i].num2 > fris[j].num2)
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
}

void ships2()
{
	Friends fris[101];
	int riverLong, riverWide;
	while (cin >> riverLong >> riverWide)
	{
		if (riverLong == 0 && riverWide == 0)
		{
			break;
		}
		int N = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			Friends f;
			cin >> f.num1 >> f.num2;
			fris[i] = f;
		}
		vector<int> dp(N, 1);
		int ans = 1;
		dp[ans] = 0;
		for (int i = 1; i < N; ++i)
		{
			int tmp = ans - 1;
			for (int j = ans - 1; j >= 0; --j)
			{
				if (fris[i].num2 > fris[j].num2 && fris[i].num1 > fris[j].num1)
				{
					tmp = j;
					break;
				}
			}
			if (tmp == ans - 1)
				dp[ans++] = tmp;
			else
				dp[tmp] = i;
		}
		cout << ans << endl;
	}
}


/*
	装箱问题：
		箱子容量为V，n个物品，每个物品有体积，使得箱子的容量最小
*/
void pack()
{
	int V;
	cin >> V;
	int arr[31];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<bool> dp(V, false);
	for (int i = 0; i < n; ++i)
	{
		for (int j = V; j >= arr[i]; --j)
		{
			if (dp[j - arr[i]])
				dp[j] = true;
		}
	}
	int ans = 0;
	for (int i = V; i >= 0; --i)
	{
		if (dp[i])
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}

/*
    二维dp，先写出二维转移方程，看是否可以转换为一维...
*/
void pack2()
{
	int V;
	cin >> V;
	int arr[31];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<vector<bool> > dp(n, vector<bool>(V, false));
	dp[0][arr[0]] = true;
	for (int i = 1; i < n; ++i)
	{
		for (int j = V; j >= arr[i]; --j)
		{
			dp[i][j] = dp[i-1][j];
			if (dp[i-1][j - arr[i]])
			{
				dp[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = V; i >= 0; --i)
	{
		if (dp[n-1][i])
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}

/*
	采药：
		输入文件medic.in的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），用一个空格隔开，
		T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到100之间（包括1和100）的整数，
		分别表示采摘某株草药的时间和这株草药的价值。
	对于一重背包，
		如果用一维，需要从后往前遍历
		如果用二维，无此限制

	对于N重背包，
		如果用一维，需要从前往前遍历

*/
void medic()
{
	int T, M;
	cin >> T >> M;
	int time[101] = {0};
	int value[101] = {0};
	for (int i = 0; i < M; ++i)
	{
		cin >> time[i] >> value[i];
	}
	int dp[1001] = {0};
	// 需要有个标记，记录是否可以构成，如果不能则为0
	dp[0] = 1;
	dp[time[0]] = value[0];
	for (int i = 1; i < M; ++i)
	{
		// 用二维的时候，就不用考虑从后向前的问题了，因为[i][j]与[i-1][j]不共用一个存储位置
		for (int j = T; j >= time[i]; --j)
		{
			if (dp[j - time[i]])
				dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
		}
	}
	cout << (dp[T] - 1) << endl;
}
/*
	二维动态规划：
		所谓二维状态就是说一般设计的状态是opt[i,j]形式的。那i,j 可以代表什么呢？
		(1)i,j 组合起来代表一个点的坐标（显然是平面坐标系）（如：街道问题）。
		(2)i,j 组合表示一个矩阵的单元的位置（第i行，第j列）（如：数塔问题）
		(3)起点为i 长度为j的区间。（如：回文词）
		(4)起点为i 终点为j的区间。（如：石子合并问题）
		(5)两个没关联的事物，事物1 的第i 个位置，对应事物2 的第j  个位置（花店橱窗设计）
		(6)两个序列，第一个序列的前i 个位置或第i 个位置对应第2 个序列的第j  个位置或前j  个位置。（最长公共子序列）。
		(7)其它
*/

int main()
{
    //cout << "Hello world!" << endl;
    //testMissiles();
    testSingerQueue();
    return 0;
}
