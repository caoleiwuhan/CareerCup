#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    �����������
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
    2:��������
        1��������ض��ٵ���
        2��Ҫ�������е�����������Ҫ����ϵͳ
            ����֪����������������У�����
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
    ������Ҫ����
*/
int missiles2(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    // dp[i]��ʾ��i�����ĸ߶�
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
                { // Ҫ���������ߵ�
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
    �����ϳ�����
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
    ������ɣ�
        ÿ������ļ۸񶼱���һ�εĵ�
        ��½�������
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
	װ�����⣺
		��������ΪV��n����Ʒ��ÿ����Ʒ�������ʹ�����ӵ�������С
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
    ��άdp����д����άת�Ʒ��̣����Ƿ����ת��Ϊһά...
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
	��ҩ��
		�����ļ�medic.in�ĵ�һ������������T��1 <= T <= 1000����M��1 <= M <= 100������һ���ո������
		T�����ܹ��ܹ�������ҩ��ʱ�䣬M����ɽ����Ĳ�ҩ����Ŀ����������M��ÿ�а���������1��100֮�䣨����1��100����������
		�ֱ��ʾ��ժĳ���ҩ��ʱ��������ҩ�ļ�ֵ��
	����һ�ر�����
		�����һά����Ҫ�Ӻ���ǰ����
		����ö�ά���޴�����

	����N�ر�����
		�����һά����Ҫ��ǰ��ǰ����

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
	// ��Ҫ�и���ǣ���¼�Ƿ���Թ��ɣ����������Ϊ0
	dp[0] = 1;
	dp[time[0]] = value[0];
	for (int i = 1; i < M; ++i)
	{
		// �ö�ά��ʱ�򣬾Ͳ��ÿ��ǴӺ���ǰ�������ˣ���Ϊ[i][j]��[i-1][j]������һ���洢λ��
		for (int j = T; j >= time[i]; --j)
		{
			if (dp[j - time[i]])
				dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
		}
	}
	cout << (dp[T] - 1) << endl;
}
/*
	��ά��̬�滮��
		��ν��ά״̬����˵һ����Ƶ�״̬��opt[i,j]��ʽ�ġ���i,j ���Դ���ʲô�أ�
		(1)i,j �����������һ��������꣨��Ȼ��ƽ������ϵ�����磺�ֵ����⣩��
		(2)i,j ��ϱ�ʾһ������ĵ�Ԫ��λ�ã���i�У���j�У����磺�������⣩
		(3)���Ϊi ����Ϊj�����䡣���磺���Ĵʣ�
		(4)���Ϊi �յ�Ϊj�����䡣���磺ʯ�Ӻϲ����⣩
		(5)����û�������������1 �ĵ�i ��λ�ã���Ӧ����2 �ĵ�j  ��λ�ã����������ƣ�
		(6)�������У���һ�����е�ǰi ��λ�û��i ��λ�ö�Ӧ��2 �����еĵ�j  ��λ�û�ǰj  ��λ�á�������������У���
		(7)����
*/

int main()
{
    //cout << "Hello world!" << endl;
    //testMissiles();
    testSingerQueue();
    return 0;
}
