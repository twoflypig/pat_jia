// 1054.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <map>
using namespace std;
int M, N;
map<int, int >fx;
map<int, int >::iterator it ;
int max_number=0;
int max_pos = 0;
int main()
{
	int temp;
	cin >> M >> N;
	cin.get();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			it = fx.find(temp);
			if (it != fx.end())
			{
				fx[temp]++;
			}
			else
			{
				fx.insert(pair<int, int>(temp, 1));
			}
		}
	}
	for (it = fx.begin(); it != fx.end(); it++)
	{
		temp = it->second;
		if (temp > max_number)
		{
			max_number = temp;
			max_pos = it->first;
		}
	}
	cout << max_pos;

	cin >> N;
    return 0;
}

