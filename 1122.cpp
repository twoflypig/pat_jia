// 1122.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int  vertexs, edgs;
int p1, p2;
int N,K;
#define MAX 201
int G[MAX][MAX] = { 0 };
vector<int >verarry;
vector<int >tage;
//要求给出的路径构成一个简单环（只有一圈），且包含所有结点才满足题目要求。
//不满足要求的情况判断：路径不连通不符合要求；路径头尾结点出现次数应为2次，中间的为1次；所有点都必须出现过。
bool check(int index)
{
	//index所能访问到的节点
	for (int i = 0; i < verarry.size(); i++)
	{
		if (i < verarry.size() - 1)
		{
			if (G[verarry[i]][verarry[i + 1]] == 0)//不通
			{
				return false;
			}
		}
		++tage[verarry[i]];
	}
	if (verarry[verarry.size() - 1] !=verarry[0] || verarry.size() <vertexs)//不通
	{
		return false;
	}
	//check
	for (int i = 0; i < verarry.size(); i++)
	{
		if ( (i == 0 || i == verarry.size()-1)&& tage[verarry[i]] == 2)
		{

		}
		else if (i != 0 && tage[verarry[i]] == 1)
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> vertexs >> edgs;
	for (int i = 0; i < edgs; i++)
	{
		cin >> p1 >> p2;
		G[p1][p2] = 1;
		G[p2][p1] = 1;
	}
	cin >> N;
	tage.resize(vertexs+1);//对应顶点的标记
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		verarry.resize(K);
		for (vector<int>::iterator it = verarry.begin(); it != verarry.end(); it++)
			*it = 0;
		for (vector<int>::iterator it = tage.begin(); it != tage.end(); it++)
			*it = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> verarry[j];
		}
		//做一个DFS即可
		if (check(verarry[0]) == true)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}
    return 0;
}

