#include <iostream>

#include <string>

#include "17_7_EnglishDescribe.h"

using namespace std;

string base[] = 
{
	"Zero",
	"One",
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine"
};

string teenBase[] = 
{
	"Ten",
	"Eleven",
	"Twelve",
	"Thirteen",
	"Fourteen",
	"Fifteen",
	"Sixteen",
	"Seventeen",
	"Eighteen",
	"Nineteen"
};

string tyBase[] = 
{
	"",
	"",
	"Twenty",
	"Thirty",
	"Fourty",
	"Fifty",
	"Sixty",
	"Seventy",
	"Eighty",
	"Ninety"
};

string hBase[] =
{
	"Hundred",
	"Thousand"
};

string NumberOfEnglish(int num)
{
	if (num < 0)
	{
		return "";
	}
	if (num == 0)
	{
		return base[0];
	}
	string ans = "";
	int high = num / 1000;
	if (high > 0)
	{
		ans = NumberOfEnglishBelowThousand(high);
		ans += " ";
		ans += hBase[1];
		num %= 1000;
	}
	if ((ans.size() != 0) && (num != 0))
	{
		ans += ", ";
	}

	if (num != 0)
	{
		ans += NumberOfEnglishBelowThousand(num);
	}

	return ans;
}

string NumberOfEnglishBelowThousand(int num)
{
	if (num < 0)
		return "";
	if (num == 0)
	{
		return base[0];
	}
	string ans;
	//int thousand = num / 1000;
	//if (thousand > 0)
	//{
	//	ans += base[thousand];
	//	ans += ' ';
	//	ans += hBase[1];
	//	ans += ',';
	//	num %= 1000;
	//}
	int hundred = num / 100;
	if (hundred > 0)
	{
		ans += base[hundred];
		ans += ' ';
		ans += hBase[0];		
		num %= 100;
	}
	if ((ans.size() != 0) && num != 0)
	{
		ans += " and ";
	}
	int ty = num / 10;
	if (ty > 1)
	{
		ans += tyBase[ty];
		ans += ' ';
		num %= 10;
	}
	if (ty == 1)
	{
		ans += teenBase[num - 10];
		num = 0;
	}
	if (num != 0)
	{
		ans += base[num];
	}
	return ans;
}

void TestNumberOfEnglish()
{
	//cout << NumberOfEnglish(0) << endl;
	//cout << NumberOfEnglish(3) << endl;
	//cout << NumberOfEnglish(10) << endl;
	//cout << NumberOfEnglish(11) << endl;
	//cout << NumberOfEnglish(18) << endl;
	//cout << NumberOfEnglish(20) << endl;
	//cout << NumberOfEnglish(80) << endl;
	//cout << NumberOfEnglish(88) << endl;


	//cout << NumberOfEnglish(100) << endl;
	//cout << NumberOfEnglish(103) << endl;
	//cout << NumberOfEnglish(110) << endl;
	//cout << NumberOfEnglish(111) << endl;
	//cout << NumberOfEnglish(118) << endl;
	//cout << NumberOfEnglish(120) << endl;
	//cout << NumberOfEnglish(180) << endl;
	//cout << NumberOfEnglish(188) << endl;
	//cout << NumberOfEnglish(200) << endl;
	//cout << NumberOfEnglish(318) << endl;
	//cout << NumberOfEnglish(520) << endl;
	//cout << NumberOfEnglish(780) << endl;
	//cout << NumberOfEnglish(888) << endl;

	//cout << NumberOfEnglish(1000) << endl;
	//cout << NumberOfEnglish(1103) << endl;
	//cout << NumberOfEnglish(1110) << endl;
	//cout << NumberOfEnglish(1111) << endl;
	//cout << NumberOfEnglish(1118) << endl;
	//cout << NumberOfEnglish(1120) << endl;
	//cout << NumberOfEnglish(1180) << endl;
	//cout << NumberOfEnglish(1188) << endl;
	//cout << NumberOfEnglish(1318) << endl;
	//cout << NumberOfEnglish(1520) << endl;
	//cout << NumberOfEnglish(1780) << endl;
	//cout << NumberOfEnglish(1888) << endl;
	//cout << NumberOfEnglish(2000) << endl;

	//cout << NumberOfEnglish(11000) << endl;
	//cout << NumberOfEnglish(11103) << endl;
	//cout << NumberOfEnglish(11110) << endl;
	//cout << NumberOfEnglish(11111) << endl;
	//cout << NumberOfEnglish(11118) << endl;
	//cout << NumberOfEnglish(11120) << endl;
	//cout << NumberOfEnglish(11180) << endl;
	//cout << NumberOfEnglish(11188) << endl;
	//cout << NumberOfEnglish(11318) << endl;
	//cout << NumberOfEnglish(11520) << endl;
	//cout << NumberOfEnglish(11780) << endl;
	//cout << NumberOfEnglish(11888) << endl;
	//cout << NumberOfEnglish(12000) << endl;

	cout << NumberOfEnglish(111000) << endl;
	cout << NumberOfEnglish(111103) << endl;
	cout << NumberOfEnglish(111110) << endl;
	cout << NumberOfEnglish(111111) << endl;
	cout << NumberOfEnglish(111118) << endl;
	cout << NumberOfEnglish(111120) << endl;
	cout << NumberOfEnglish(111180) << endl;
	cout << NumberOfEnglish(111188) << endl;
	cout << NumberOfEnglish(111318) << endl;
	cout << NumberOfEnglish(111520) << endl;
	cout << NumberOfEnglish(111780) << endl;
	cout << NumberOfEnglish(111888) << endl;
	cout << NumberOfEnglish(112000) << endl;
	cout << NumberOfEnglish(110100) << endl;
	cout << NumberOfEnglish(111103) << endl;
	cout << NumberOfEnglish(111110) << endl;
	cout << NumberOfEnglish(111111) << endl;
	cout << NumberOfEnglish(111118) << endl;
	cout << NumberOfEnglish(111120) << endl;
	cout << NumberOfEnglish(111180) << endl;
	cout << NumberOfEnglish(111188) << endl;
	cout << NumberOfEnglish(111318) << endl;
	cout << NumberOfEnglish(111520) << endl;
	cout << NumberOfEnglish(111780) << endl;
	cout << NumberOfEnglish(111888) << endl;
	cout << NumberOfEnglish(999999) << endl;

}
