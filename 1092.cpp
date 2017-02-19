// 1092.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
int table[300] = { 0 };
int need[300] = { 0 };
string str;
string strneed;
int have =0;
int lost=0;

int main()
{
	cin >> str;
	cin >> strneed;
	for (int i = 0; i<str.size(); i++)
	{
		table[str[i]]++;
	}
	for (int i = 0; i < strneed.size(); i++)
	{
		need[strneed[i]]++;
	}
	for (int i = 0; i < 300; i++)
	{
		if (table[i] > need[i])
		{
			have += table[i] - need[i];
		}
		else
		{
			lost += (need[i] - table[i]);
		}
	}
	if (lost > 0)
		cout << "No " << lost;
	else
		cout << "Yes " << have;

	cin >> lost;
    return 0;
}

