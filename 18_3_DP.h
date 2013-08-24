#include <iostream>

using namespace std;

/*
	一、递增子序列
	在无序序列中，找到一个最长上升最序列或最长下降子序列
	1:f[i] = max{f[j] + 1} a[i] >= a[j] 0<=j<i
	2:f[i] = max{f[j] + 1} a[i] <= a[j] 0<=j<i

	第一发子弹可以打任意高度，但是以后的都不能超过前一发的高度。
	输入导弹的高度（不大于30000），计算最多能拦截多少导弹，
	如果要拦截所有导弹，要配备多少套这样的系统
	389 207 155 300 299 170 158 65
	第一问：最长下降子序列
	f[i] = max{f[j] + 1} a[i] <= a[j] 0<=j<i
			if (a[i] <= a[j] && a[i] <= a[k] && f[j] == f[k])
				if (a[j] <= a[k]) f[i] = f[j] + 1
	第二问：迭代贪心计算？
	维护一个集合，记录当前所用的j套系统的最后一个高度
	b[j]
*/

/*
	二、合唱队形
	N个同学站成一排，（n-k）个同学出列，使得剩下的k个同学组成队形：先上升、再下降的队形（严格的先上升、再下降）
	已知N位同学的身高，求最长的队形。
	186 186 150 200 160 130 197 220
	思路一：for (int i = 0; i < n; ++i) 
			f[i] = a[0, i] + b[i, n]
	思路二：
		正向求一次最长上升子序列、逆向求一次最长下降子序列
		ans = max(N - a[i]
*/
int SingSongQueue(int arr[], int n);
// 包含j
int InCreaseQueue(int arr[], int i, int j, int n);
// 包含i
int DecreaseQueue(int arr[], int i, int j, int n);

void TestSingSongQueue();

int SingSongQueue2(int arr[], int n);

/*
	例题3：每次购买的股票要比上次购买的要低，最多能购买几次。
	给定连续的N天中每天的股价。你可以在任何一天购买一次股票，但是购买时的股价
	一定要比你上次购买时的股价低。写一个程序，求出最多能买几次股票。
	68 69 54 64 68 64 70 67 78 62 98 87 
	   69		68 64		   62 
	最长下降子序列：
*/

/*
	例题4:船
	PALMIA国家被一条河流分成南北两岸，南北两岸上各有N个村庄。
	北岸的每一个村庄有一个唯一的朋友在南岸，且他们的朋友村庄彼此不同。 
	每一对朋友村庄想要一条船来连接他们，他们向政府提出申请以获得批准。由于河面上常常有雾，
	政府决定禁止船只航线相交（如果相交，则很可能导致碰船）。
	你的任务是编写一个程序，帮助政府官员决定批准哪些船只航线，使得不相交的航线数目最大。 
	【输入文件】
	ships.in 
	输入文件由几组数据组成
	。每组数据的第一行有2个整数X，Y，中间有一个空格隔开，X代表PALMIA河的长度（10<=X<=6000），
	Y代表河的宽度（10<=Y<=100）。
	第二行包含整数N，表示分别坐落在南北两岸上的村庄的数目（1<=N<=5000）。在接下来的N行中，
	每一行有两个非负整数C，D，由一个空格隔开，分别表示这一对朋友村庄沿河岸与PALMIA河最西边界
	的距离（C代表北岸的村庄，D代表南岸的村庄），	不存在同岸又同位置的村庄。最后一组数据的下面
	仅有一行，是两个0，也被一空格隔开。 
	【输出文件】
	ships.out 
	对输入文件的每一组数据，输出文件应在连续的行中表示出最大可能满足上述条件的航线的数目。 
	【输入样例】 
	30 4 
	7 
	22 4 
	2 6 
	10 3 
	15 12 
	9 8 
	17 17 
	4 2 
	0 0 
	【输出样例】 
	4 
	思路：先按照num1排序，然后对num2,求最长上升子序列
*/
int LongestShips(int arr1[], int arr2[], int n);


/*
	5:背包问题
	有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），
	每个物品有一个体积（正整数）。 
	要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。 
	【输入文件】 
	第一行一个正整数V表示箱子的容量，第二行一个正整数N表示物品个数，接下来N行列出这N个物品各自的体积。 
	【输出文件】 
	单独一行，表示箱子最小的剩余空间。 
	【输入样例】 
	24 
	6 
	8 3 12 7 9 7
*/
int MinSpaceOfBox(int arr[], int n, int v);

void TestMinSpaceOfBox();

int MinSpaceOfBox2(int arr[], int n, int v);


/*
	设有1g、2g、3g、5g、10g、20g的砝码各若干枚（其总重<=1000），用他们能称出的重量的种类数。 
	【输入文件】 
	a1 a2 a3 a4 a5 a6 （表示1g砝码有a1个，2g砝码有a2个，…，20g砝码有a6个，中间有空格）。 
	【输出文件】 
	Total=N （N表示用这些砝码能称出的不同重量的个数，但不包括一个砝码也不用的情况）。 
	【输入样例】 
	1 1 0 0 0 0 
	【输出样例】 
	TOTAL=3 
*/
int kindOfWeight(int arr[], int n);

int PacketOne(int time[], int val[], int n, int totalTime);

void TestPacketOne();

int PacketTwo(int price[], int val[], int n, int money);

/*
	包括主件和附件，如果要购买附件，必须要先购买主件
	如果能记录相应money下的主件是否被购买就好了

*/

/*
	Money System:
	写一个程序来计算有多少种方法用给定的货币系统来构造一定数量的面值
*/
int MoneySystem(int kind[], int m, int N);

void TestMOneySystem();

int DVD(int time[], int score[], int n, int total);

int DVD2(int time[], int score[], int n, int total, int m);

/*
	石子合并
*/
int MergeStoneMin(int s[], int n);