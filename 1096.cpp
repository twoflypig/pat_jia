// 1096.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	int start = 0;
	int length = 0;
	int max_length = 0;
	int max_start = 0;
	int data;
	int stroe_data;
	int flag = 0;
	cin >> data;

	int N = (int)sqrt((double)data) + 2;
	stroe_data = data;
	for (int i = 2; i < N; i++)
	{
		data = stroe_data;
		length = 0;
		start = 0;
		flag = 0;
		int j = i;
		for (int time = 0; time <= 31; time++,j++)
		{
			if (data %(j) == 0)
			{
				if (start == 0)
				{
					start = j;
					flag = 1;
				}
				length++;
				data /= j;
			}
			else if (flag == 1)
			{
				if (max_length < length)
				{
					max_length = length;
					max_start = start;
				}
				else if (max_length == length)
				{
					if (max_start > start)
					{
						max_start = start;
					}
				}
				break;
			}
		}
	}
	if (max_length == 0)
	{
		max_length = 1;
		max_start = stroe_data;
	}
	cout << max_length << endl;
	for (int i = 0; i < max_length; i++)
	{
		if (i == 0)
		{
			cout << max_start;
		}
		else
		{
			cout << "*" << max_start + i;
		}

	}


	getchar();
	getchar();
	return 0;
}

