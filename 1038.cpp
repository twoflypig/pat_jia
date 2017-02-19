// 1038.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string>buff;
vector<bool>tage;
int N;
string strtemp;
string strmin;
string strffmin;
string::iterator it ;
string::iterator it2;
bool compare(string v1, string v2)
{
	return (v1+v2)<(v2+v1);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> strtemp;
		buff.push_back(strtemp);
	}
	sort(buff.begin(), buff.end(), compare);
	for (int i = 0; i < N; i++)
		strffmin += buff[i];


	for (it = strffmin.begin(); *it == '0'; it++);
	if (it == strffmin.end())
		cout << 0;
	else
		for (; it != strffmin.end(); it++)
			cout << *it;
	cin >> N;
    return 0;
}

