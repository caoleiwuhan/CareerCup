#include <iostream>
#include <string>

using namespace std;

void StringPermutation(string str);

void StringPermutationDFS(string str, int step);

void TestStringPermutation();

/*
	������ظ��ģ�
		��ǰΪstep��Ҫ������Ϊi
		�����[step, i-1]����str[i]��ͬ�ģ��򲻽���
*/
void StringPermutationDFS2(string str, int step);