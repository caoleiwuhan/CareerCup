#include <iostream>
#include <string>

using namespace std;

void StringPermutation(string str);

void StringPermutationDFS(string str, int step);

void TestStringPermutation();

/*
	如果有重复的：
		当前为step，要交换的为i
		如果从[step, i-1]有与str[i]相同的，则不交换
*/
void StringPermutationDFS2(string str, int step);