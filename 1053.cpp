// 1053.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
vector<list<int> >tree(100);
vector<int >weight(100);
vector<bool >Check(100);
int N, M,S;
int index,K;
int temp = 0;
vector<vector<int >>s_weight;
vector<int>tempweight;
bool cmp(vector<int>v1, vector<int>v2)
{
	return v1>v2;
}
void dfs(int index, int &total)
{
	if (Check[index] == false)
	{
		Check[index] = true;
		tempweight.push_back(weight[index]);
		total += weight[index];
		if (tree[index].empty() == false)
		{
			for (list<int>::iterator it = tree[index].begin(); it != tree[index].end(); it++)
			{
				if (Check[*it] == false)
				{
					dfs(*it, total);
				}
			}
		}
		else
		{
			if (total == S)
				s_weight.push_back(tempweight);
		}
		tempweight.pop_back();
		total -= weight[index];
	}
}
int main()
{
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> index >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> temp;
			tree[index].push_back(temp);
		}
	}
	int total = 0;
	dfs(0,total);

	sort(s_weight.begin(), s_weight.end(), cmp);
	for (int i = 0; i < s_weight.size(); i++)
	{
		for (int j = 0; j < s_weight[i].size(); j++)
		{
			if (j)
				cout << " ";
			cout << s_weight[i][j];
		}
		cout << endl;
	}

	cin >> N;
    return 0;
}

