// 1049.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int checkOne(int value)
{
	int cout = 0;
	while (value > 0)
	{
		if (value % 10 == 1)
		{
			cout++;
		}
		value /= 10;
	}
	return cout;
}
int main()
{
	int N;
	int sum = 0;
	int k = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		sum += checkOne(i);
	}
	printf("%d", sum);
	cin >> N;
    return 0;
}

