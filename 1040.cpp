// 1040.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
string fx;
int max_number=0;
int p_number = 0;
int p_left;
int p_right;
int flag = 0;
int main()
{
	getline(cin,fx);
	for (int i = 0; i<fx.size(); i++)
	{
		for (p_left = i, p_right = i,p_number=0; p_left >= 0 && p_right<fx.size(); p_left--, p_right++)
		{
			if (fx[p_left] == fx[p_right])
			{
				p_number++;
				max_number = max_number < p_number*2-1 ? p_number*2-1 : max_number;
			}
			else
			{
				break;
			}
		}
		for (p_left = i - 1, p_right = i, p_number = 0; p_left >= 0 && p_right<fx.size(); p_left--, p_right++)
		{
			if (fx[p_left] == fx[p_right])
			{
				p_number++;
				max_number = max_number < p_number*2 ? p_number*2 : max_number;
			}
			else
			{
				break;
			}
		}
	}
	cout << max_number;
	cin >> p_right;
    return 0;
}

