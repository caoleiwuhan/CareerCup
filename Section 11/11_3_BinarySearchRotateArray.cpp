#include <iostream>
#include <vector>
#include <cassert>

#include "11_3_BinarySearchRotateArray.h"

using namespace std;

int BinarySearchRotateArray(int arr[], int n, int num)
{
	if (arr == NULL || n <= 0)
	{
		return -1;
	}
	int left = 0;
	int right = n - 1;
	while (left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == num)
			return mid;
		// 前一段是绝对序
		if (arr[left] <= arr[mid])
		{
			if (num >= arr[left] && num <= arr[mid])
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		else if (arr[mid] <= arr[right])
		{ // 后一段是绝对序
			if (num >= arr[mid] && num <= arr[right])
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
	}
	if (arr[left] == num)
		return left;
	if (arr[right] == num)
		return right;
	return -1;
}

int BinarySearchRotateArray2(int arr[], int n, int num)
{
	if (arr == NULL || n <= 0)
	{
		return -1;
	}
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == num)
			return mid;
		else if (arr[left] <= arr[mid])
		{
			if (num >= arr[left] && num <= arr[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else
		{
			if (num >= arr[mid] && num <= arr[right])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
	return -1;
}

bool search(int arr[], int n, int num) 
{
	int left = 0;
    int right = n - 1;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
        {
            return true;
        }
		if (arr[left] == arr[mid] && arr[mid] == arr[right])
		{
			for (int i = left; i <= right; ++i)
			{
				if (arr[i] == num)
					return true;
			}
			return false;
		}
        if (arr[left] <= arr[mid])
        {
            if (num >= arr[left] && num <= arr[mid])
                right = mid;
            else
                left = mid;
        }
        else
        {
            if (num >= arr[mid] && num <= arr[right])
                left = mid;
            else
                right = mid;
        }
    }
    if (arr[left] == num)
        return true;
    if (arr[right] == num)
        return true;
        
    return false;
}

// 找到指定的数
bool search2(int arr[], int n, int num)
{
	if (arr == NULL || n <= 0)
	{
		return -1;
	}
	int left = 0;
	int right = n - 1;
	while (left + 1 < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == num)
		{
			return mid;
		}
		if (arr[mid] == arr[left] && arr[mid] == arr[right])
		{
			for (int i = left; i <= right; ++i)
			{
				if (arr[i] == num)
				{
					return i;
				}
			}
			return -1;
		}
		if (arr[left] <= arr[mid])
		{
			if (num >= arr[left] && num <= arr[mid])
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		else
		{
			if (num >= arr[mid] && num <= arr[right])
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
	}
	if (arr[left] == num)
		return left;
	if (arr[right] == num)
		return right;
	return -1;

}

int maxProfit(vector<int> &arr) 
{
    int size = arr.size();
    if (size == 0)
        return 0;
    int ans = 0;
    int cur = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[i - 1])          
        {
            ans += arr[i - 1] - cur;
            cur = arr[i];                
        }
    }
	if (cur < arr[size - 1])
	{
		ans += (arr[size - 1] - cur);
	}
    return ans;
}


int MaxSum(vector<int> &arr, int from, int to)
{
    if (from > to)
        return 0;
    if (from == to)
    {
        if (arr[from] > 0)
            return arr[from];
        return 0;
    }
    int best = 0;
    int sum = 0;
    for (int i = from; i <= to; ++i)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        if (sum > best)
            best = sum;
    }
    return best;        
}
    
int maxProfit2(vector<int> &arr) 
{
    int size = arr.size();
    if (size == 0)
        return 0;
            
    for (int i = 1; i < size; ++i)
    {
        arr[i - 1] = arr[i] - arr[i - 1];
    }
    int ans = 0;
    size--;
    for (int i = 0; i < size; ++i)
    {
        int num1 = MaxSum(arr, 0, i);
        int num2 = MaxSum(arr, i + 1, size - 1);
        int sum = num1 + num2;
        if (sum > ans)
            ans = sum;
    }
        
    return ans;
}

int MinNumberOfRotateArray(int arr[], int n, int num)
{
	if (arr == NULL || n <= 0)
		return 0;
	int left = 0;
	int right = n - 1;
	while (left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[left] == arr[mid] && arr[mid] == arr[right])
		{
			int ans = arr[left];
			for (int i = left + 1; i <= right; ++i)
			{
				ans = min(ans, arr[i]);
			}
			return ans;
		}
		else if (arr[left] < arr[mid])
		{
			if (arr[mid] > arr[right])
				left = mid;
			else
				right = mid;
		}
		else if (arr[mid] < arr[right])
		{
			right = mid;			
		}
	}
	return min(arr[left], arr[right]);
}

int MinNumberOfRotateArray2(int arr[], int n, int num)
{
	if (arr == NULL || n <= 0)
		return 0;
	int left = 0;
	int right = n - 1;
	while (arr[left] >= arr[right])
	{
		if (left + 1 == right)
		{
			return arr[right];
		}
		int mid = left + (right - left) / 2;
		if (arr[left] == arr[mid] && arr[mid] == arr[right])
		{
			int ans = arr[left];
			for (int i = left + 1; i <= right; ++i)
			{
				ans = min(ans, arr[i]);
			}
			return ans;
		}
		if (arr[left] >= arr[mid])
		{
			right = mid;
		}
		else if (arr[mid] >= arr[right])
		{
			left = mid;
		}
	}
	return arr[left];
}


int MinNumberOfRotateArray3(int arr[], int n)
{
	assert(arr && n >= 0);
	int left = 0;
	int right = n - 1;
	while (arr[left] >= arr[right])
	{
		if (left + 1 == right)
		{
			return arr[right];
		}
		int mid = (left + right) / 2;
		if (arr[left] == arr[mid] && arr[mid] == arr[right])
		{
			int ans = arr[left];
			for (int i = left + 1; i <= right; ++i)
			{
				ans = min(ans, arr[i]);
			}
			return ans;
		}
		if (arr[left] >= mid)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}	
	return arr[left];
}

void TestBinarySearchRotateArray()
{
	/*int arr[] = 
	{
		15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
	};
	cout << BinarySearchRotateArray(arr, 12, 15) << endl;
	cout << BinarySearchRotateArray(arr, 12, 16) << endl;
	cout << BinarySearchRotateArray(arr, 12, 19) << endl;
	cout << BinarySearchRotateArray(arr, 12, 20) << endl;
	cout << BinarySearchRotateArray(arr, 12, 25) << endl;
	cout << BinarySearchRotateArray(arr, 12, 1) << endl;
	cout << BinarySearchRotateArray(arr, 12, 3) << endl;
	cout << BinarySearchRotateArray(arr, 12, 4) << endl;
	cout << BinarySearchRotateArray(arr, 12, 5) << endl;
	cout << BinarySearchRotateArray(arr, 12, 7) << endl;
	cout << BinarySearchRotateArray(arr, 12, 10) << endl;
	cout << BinarySearchRotateArray(arr, 12, 14) << endl;


	cout << "------------------------------------------" << endl;
	cout << BinarySearchRotateArray2(arr, 12, 15) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 16) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 19) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 20) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 25) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 1) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 3) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 4) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 5) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 7) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 10) << endl;
	cout << BinarySearchRotateArray2(arr, 12, 14) << endl;*/

	/*int arr[] = {1, 3, 1, 1, 1};
	cout << search(arr, 5, 3) << endl;
*/
	int tmp[] = {10, 9, 11, 13, 15};
	vector<int> vec(tmp, tmp + 5);

	cout << maxProfit(vec) << endl;
}