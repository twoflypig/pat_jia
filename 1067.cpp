// 1067.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int N;
int number = 0;
void swap(int &v1, int &v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

int main()
{
	int base, find;
	cin >> N;
	vector<int>fx(N);
	vector<int>pos_index(N);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i];
		pos_index[fx[i]] = i;
	}

	while (1)
	{
		base = pos_index[0];//0对应的位置
		find = pos_index[base];//0对应的位置的本来数的位置
		if (base != find)
		{
			swap(pos_index[fx[base]], pos_index[fx[find]]);//更换映射表
			swap(fx[base], fx[find]);//更换数组
		}
		else
		{
			//找到一个没有对齐的数
			int i = 1;
			for (;i<N&&pos_index[i] == i ; i++) ;
			if (i == N) break;
			swap(fx[base], fx[pos_index[i]]);//更换数组
			swap(pos_index[0], pos_index[i]);//更换映射表

		}
		number++;
	}

	cout << number;


	cin >> N;
    return 0;
}

