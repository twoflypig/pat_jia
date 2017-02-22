// 1023.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int table1[10] = { 0 };
int table2[10] = { 0 };
string str1;
string str2;
string str3;
int carry = 0;
int main()
{
	cin >> str1;
	str2 = str1;
	for (int i = 0; i < str1.size(); i++)
	{
		table1[str1[i]-'0']++;//他是字符
	}
	int temp = 0;
	carry = 0;
	for (int i = str1.size() - 1; i >= 0; i--)
	{
		temp = (str1[i] - '0') * 2+carry;
		str2[i] = temp % 10 + '0';
		carry = temp / 10;
	}

	for (int i = 0; i < str2.size(); i++)
	{
		table2[str2[i]-'0']++;
	}
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (table1[i] != table2[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1 || carry!=0 )
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	if (carry != 0)
	{
		cout << carry;
	}
	cout << str2;
    return 0;
}

