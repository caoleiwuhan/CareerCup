#include <iostream>

#include "18_3_DP.h"

using namespace std;



void TestSingSongQueue()
{
	int arr[] = {186, 186, 150, 200, 160, 130, 197, 220};
	cout << SingSongQueue(arr, sizeof(arr) / sizeof(int)) << endl;
	cout << SingSongQueue2(arr, sizeof(arr) / sizeof(int)) << endl;

}
int SingSongQueue(int arr[], int n)
{
	//int f[200];
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int low = InCreaseQueue(arr, 0, i, n);
		int high = DecreaseQueue(arr, i, n - 1, n);
		ans = max(ans, low + high - 1);
	}
	return ans;
}


// ����j
int InCreaseQueue(int arr[], int i, int j, int n)
{
	if (i > j)
	{
		return 0;
	}
	if (i == j || i < 0)
		return 1;
	int f[200];
	memset(f, 0, sizeof(f));
	f[j] = 1;
	for (int k = j - 1; k >= i; --k)
	{
		int tmp = 0;
		for (int t = j; t > k; --t)
		{
			if (arr[k] < arr[t] && f[t] != 0)
			{
				tmp = max(tmp, f[t] + 1);
			}
		}
		f[k] = tmp;
	}
	int ans = 0;
	for (int k = i; k <= j; ++k)
	{
		ans = max(ans, f[k]);
	}
	return ans;
}

// ����i
int DecreaseQueue(int arr[], int i, int j, int n)
{
	if (i > j)
		return 0;
	if (i == j || j >= n)
		return 1;
	int f[200];
	memset(f, 0, sizeof(f));
	f[i] = 1;
	for (int k = i + 1; k <= j; ++k)
	{
		int tmp = 0;
		for (int t = i; t < k; ++t)
		{
			if (arr[t] > arr[k] && f[t] != 0)
			{
				tmp = max(tmp, f[t] + 1);
			}
		}
		f[k] = tmp;
	}
	int ans = 0;
	for (int k = i; k <= j; ++k)
	{
		ans = max(ans, f[k]);
	}
	return ans;
}


int SingSongQueue2(int arr[], int n)
{
	// �������������������
	int a[200];
	memset(a, 0, sizeof(a));
	a[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		int tmp = 1;
		for (int j = 1; j < i; ++j)
		{
			if (arr[j] < arr[i])
			{
				tmp = max(tmp, a[j] + 1);
			}
		}
		a[i] = tmp;
	}
	int b[200];
	memset(b, 0, sizeof(b));
	b[n-1] = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		int tmp = 1;
		for (int j = n - 2; j > i; --j)
		{
			if (arr[j] < arr[i])
			{
				tmp = max(tmp, b[j] + 1);
			}
		}
		b[i] = tmp;
	}
	int ans = 0;
	// ��Ϊa[i]���ǰ���i���������У�b[i]�ǰ���i���½����У���ˣ�����һ��ɨ��͵õ���	
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, a[i] + b[i] - 1);
	}
	return ans;
}

int LongestShips(int arr1[], int arr2[], int n)
{
	int f[200];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int ans = 1;
	for (int i = 1; i < n; ++i)
	{
		int tmp = 1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr1[i] > arr1[j] && arr2[i] > arr2[j])
			{
				tmp = max(tmp, f[j] + 1);
			}
		}
		f[i] = tmp;
		ans = max(ans, tmp);
	}
	return ans;
}

void TestMinSpaceOfBox()
{
	int arr[] = 
	{
		8, 3, 12, 7, 9, 7
	};
	cout << MinSpaceOfBox(arr, 6, 24) << endl;
}

int MinSpaceOfBox(int arr[], int n, int v)
{
	bool f[20001] = {false};
	f[0] = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = v; j >= arr[i]; --j)
		{
			if (f[j - arr[i]])
			{
				f[j] = true;
			}
		}
	}
	// ������������Ļ���ÿһ���������ᱻ�úü��Σ�����8��16,24�����õ�������Ƕ��ر������Կ���
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= v; ++j)
		{
			if ((j - arr[i] >= 0) && f[j - arr[i]])
			{
				f[j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = v; i >= 0; --i)
	{
		if (f[i])
		{
			ans = i;
			break;
		}
	}
	return (v - ans);
}

int MinSpaceOfBox2(int arr[], int n, int v)
{
	bool f[101][20001] = {false};
	f[0][arr[0]] = true;
	for (int i = 1; i < n; ++i)
	{
		for (int j = arr[i]; j <= v; ++j)
		{
			if (f[i-1][j-arr[i]])
			{
				f[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < v; ++i)
	{
		if (f[n-1][i])
		{
			ans = max(ans, i);
		}
	}
	return (v - ans); 
}

int kindOfWeight(int arr[], int n)
{ // 1 2 3 5 10 20
	int w[6] = {1, 2, 3, 5, 10, 20};
	bool f[1001] = {false};
	f[0] = true;
	int v = 0;
	for (int i = 0; i < n; ++i)
	{
		v += arr[i] * w[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = v; j >= 0; --j)
		{
			for (int k = 1; k <= arr[i]; ++k)
			{
				if (f[j - k * arr[i]])
				{
					f[j] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= v; ++i)
	{
		++ans;
	}
	return ans;
}

int PacketOne(int time[], int val[], int n, int totalTime)
{
	// f[i] ��ʾ��iʱ���ڵõ������ֵ

	int f[1001] = {0};
	// �߽���������f[0]=1�������Ͳ������߽�Ϊ0ʱ���ж��ˣ�ֻ��Ҫ������һ����
	f[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = totalTime; j > 0; --j)
		{
			if (j >= time[i] && f[j - time[i]] != 0)
			{
				f[j] = max(f[j], f[j - time[i]] + val[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= totalTime; ++i)
	{
		ans = max(ans, f[i]);
	}
	--ans;
	return ans;
}

void TestPacketOne()
{
	int time[] = 
	{
		200, 79, 58, 86, 11, 28, 62, 15, 68
	};
	int val[] = 
	{
		8, 83, 14, 54, 79, 72, 52, 48, 62
	};
	cout << PacketOne(time, val, sizeof(val) / sizeof(int), 200) << endl;
}

int PacketTwo(int price[], int val[], int n, int money)
{
	// f[i] ����Ϊiʱ�����ֵ
	int f[30001] = {0};
	f[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = money; j > 0; --j)
		{
			if (j - val[i] >= 0)
			{
				if (f[j - val[i]])
				{
					f[j] = max(f[j], f[j-val[i]] + price[i] * val[i]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = money; i >= 0; --i)
	{
		ans = max(ans, f[i]);
	}
	--ans;
	return ans;
}

int MoneySystem(int kind[], int m, int N)
{
	// f[i] 
	int f[10001] = {0};
	f[0] = 1;
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (j - kind[i] >= 0 && f[j - kind[i]] > 0)
			{
				f[j] += f[j - kind[i]];
			}
		}
	}
	return (f[N]);
}

int DVD(int time[], int score[], int n, int total)
{
	int f[2001] = {0};
	f[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = total; j >= time[i]; --j)
		{
			if (f[j - time[i]] > 0)
			{
				f[j] = max(f[j], f[j - time[i]] + score[i]);
			}
		}
	}
	return (f[total] - 1);
}

int DVD2(int time[], int score[], int n, int total, int m)
{
	// ��i�ţ���jʱ���ڿ���
	int f[101][2001] = {0};
	f[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (j < i)
				break;
			for (int k = total; k >= time[i]; --k)
			{
				if (f[j - 1][k - time[i]] > 0)
				{
					f[j][k] = max(f[j][k], f[j-1][k-time[i]] + score[i]);
				}
			}
		}
	}
	return (f[m][total] - 1);	
}

void TestMOneySystem()
{
	/*int arr[] = 
	{
		1, 2, 3, 5
	};
	cout << MoneySystem(arr, sizeof(arr) / sizeof(int), 10) << endl;*/

	//int t[] = 
	//{
	//	11, 1, 9
	//};
	//int s[] =
	//{
	//	100, 2, 1
	//};
	//cout << DVD2(t, s, sizeof(t) / sizeof(int), 10, 2) << endl;
	
	int stone[] = 
	{
		3, 4, 6, 5, 4, 2
	};
	cout << MergeStoneMin(stone, 6) << endl;

}

int MergeStoneMin(int s[], int n)
{
	int f[101][101] = {0};
	for (int i = 1; i < n; ++i)
	{
		s[i] += s[i-1];
	}
	for (int k = 1; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			int j = i + k;
			if (j >= n)
				break;
			f[i][j] = f[i][i] + f[i + 1][j];
			for (int t = i + 1; t < j; ++t)
			{
				f[i][j] = min(f[i][j], f[i][t] + f[t+1][j]);
			}
			if (i == 0)
			{
				f[i][j] += s[j];
			}
			else
			{
				f[i][j] += (s[j] - s[i-1]);
			}
		}
	}
	return f[0][n-1];	
}