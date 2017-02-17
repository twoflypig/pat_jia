// 1069.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s1, s2, res;
int asd = 0;
int count_nu = 0;
bool no_increase(char v1, char v2)
{
	return v1 > v2;
}
bool non_decreasing(char v1, char v2)
{
	return v1 < v2;
}
int main()
{
	int temp = 2;
	cin >> temp;
	s1 = "0000";
	for (int i = 3; i >= 0; i--)
	{
		s1[i] = temp % 10+'0';
		temp /= 10;
	}
	res = s1;

	do
	{
		sort(s1.begin(), s1.begin() + 4, no_increase);
		s2 = s1;
		sort(s2.begin(), s2.begin() + 4, non_decreasing);
		for (int i = 3,asd = 0 ; i >= 0; i--)
		{
			res[i] = (int)s1[i] - (int)s2[i] + '0' + asd;
			if (res[i] < '0')
			{
				res[i] = res[i] + 10;
				asd = -1;
			}
			else
			{
				asd = 0;
			}
		}
		printf("%s - %s = %s\n", &s1[0], &s2[0], &res[0]);
		s1 = res;
	} while (res != "6174" && res != "0000");


	cin >> asd;
	return 0;
}

