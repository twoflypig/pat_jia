// 1084.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string in_str;
string real_instr;
int fx[300] = {0};
char temp;
int i, j=0;

int main()
{
	cin >> in_str >> real_instr;
	for (i = 0; i < in_str.size() && j< real_instr.size(); i++)
	{
		if (tolower(in_str[i]) != tolower(real_instr[j]))
		{
			fx[tolower(in_str[i])]++;
			if (fx[tolower(in_str[i])] == 1)
			{
				cout << (char)toupper(in_str[i]);
			}
		}
		else
		{
			j++;
		}
	}
	for (; i < in_str.size(); i++)
	{
		fx[tolower(in_str[i])]++;
		if (fx[tolower(in_str[i])] == 1)
		{
			cout << (char)toupper(in_str[i]);
		}
	}
	cin >> in_str;
    return 0;
}

