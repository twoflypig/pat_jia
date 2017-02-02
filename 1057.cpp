// 1057.cpp : 定义控制台应用程序的入口点。
//给堆增加一个操作，返回堆中所有元素的中间值 
//the median value is defined to be the (N/2)-th
//smallest element if N is even, or ((N+1)/2)-th if N is odd.
//第一行包含一个整数N，有三种命令 Push Pop PeekMedian
//N<=10 ^4 key <=10 ^5
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <list>
#define MAX 100001
using namespace std;
vector<int>output;
stack<int >buffer;
int fx[MAX] = {0};
int lowbit(int x)
{
	return x&(-x);
}
int sum(int x)
{
	int res = 0;
	while (x >0)
	{
		res += fx[x];
		x -= lowbit(x);
	}
	return res;
}
void  add(int value, int command)
{
	while (value < MAX)
	{
		fx[value] += command;
		value += lowbit(value);
	}
}
int getMid(void)
{
	int low = 0;
	int high = MAX;
	int middle =0;
	int find = 0;
	int temp = 0;
	if (buffer.size() == 0)
	{
		return -1;
	}
	find = (1 + buffer.size()) / 2;
	while (low < high)
	{
		middle = (low + high) / 2;
		temp = sum(middle);
		if ( temp <find)
		{
			low = middle + 1;
		}
		else
		{
			high = middle;
		}
	}

	return low;
}
int main()
{
	string command;
	int value;
	int N;
	cin >> N;
	cin.get();
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command == "Pop")
		{
			if (buffer.size() == 0)
			{
				output.push_back(-1);
			}
			else
			{
				output.push_back(buffer.top());
				add(buffer.top(), -1);
				buffer.pop();
			}
		}
		else if (command == "Push")
		{
			cin >> value;
			buffer.push(value);
			add(value, 1);

		}
		else if (command == "PeekMedian")
		{
			output.push_back(getMid());
		}
		else
		{
			output.push_back(-1);
		}
		cin.get();
	}
	for (int i = 0; i < output.size(); i++)
	{

		if (output[i] == -1)
		{
			printf("Invalid\n");
		}
		else
		{
			printf("%d\n",output[i]);
		}
	}

	cin >> value;
	cin >> value;
    return 0;
}

