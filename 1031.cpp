// 1031.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
string fx;
int n1, n2, n3;
int space;
int space_lenth;
int str_start = 0;
int str_end = 0;
int main()
{
	cin >> fx;
	n2 = fx.size()+2;
	if (n2 % 3 != 0)
	{
		n2 = n2 / 3 + 1;
	}
	else
	{
		n2 = n2 / 3 ;
	}
	n1 =(fx.size() - n2)/2;
	n3 = n1;
	n2 = fx.size() - n1 * 2;
	space = n2 - 2;
	str_start = 0;
	str_end = fx.size()-1;
	while (str_start < str_end)
	{
		if (str_start < n1)
		{
			cout << fx[str_start++];
			space_lenth = space;
			while (space_lenth--) cout << " ";
			cout << fx[str_end--];
			cout << endl;
		}
		else
		{	
			space_lenth = space+2;
			while (space_lenth--) cout << fx[str_start++];
		//	cout << fx[str_end];
		}
	}

	cin >> n1;
    return 0;
}

