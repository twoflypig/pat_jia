// 1110.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef struct
{
	int father;
	int left;
	int right;
}NODE;
vector<NODE>arry;
NODE temp;
int N;
string c1, c2;
queue<int >level;
int rootindex = 0;
int value;
vector<bool>tage(21);
int completeflag = 0;
int fllowindex = 0;
int totalcount = 0;
int check(string &c)
{
	int temp = 0;
	if (c[0] == '-')
		return -1;
	else
	{
		sscanf(c.c_str(), "%d", &temp);
		return temp;
	}
		
}
int main()
{
	cin >> N;
	cin.get();
	arry.resize(N);
	for (int i = 0; i < N; i++)
		arry[i].left = arry[i].right = arry[i].father = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> c1 >> c2;
		arry[i].left = check(c1);
		arry[i].right = check(c2);
		arry[i].father = -1;
	}
	for (int i = 0; i < N; i++)
	{
		if (arry[i].left != -1)
			arry[arry[i].left].father = i;
		if (arry[i].right != -1)
			arry[arry[i].right].father = i;
	}
	//查找root
	for (int i = 0; i < N; i++)
	{
		if ( arry[i].father == -1)
		{
			rootindex = i;
			break;
		}
	}
	//思路:跟踪最后左右有孩子的连续节点，使这个规律中断的节点，记录此节点
	level.push(rootindex);
	while (level.empty() == false)
	{
		value = level.front();
		level.pop();
		if (value != -1 )
		{
			fllowindex = value;
			totalcount++;
		}
		if (value == -1)
			break;

		level.push(arry[value].left);
		level.push(arry[value].right);
	}
	if (totalcount == N)
	{
		cout << "YES " << fllowindex<<endl;
	}
	else
	{
		cout << "NO " << rootindex << endl;
	}
	return 0;
}

