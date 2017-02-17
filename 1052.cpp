// 1052.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef struct
{
	int Address;
	int key;
	int Next;
}NODE;
vector<NODE>fx;
vector<NODE>fx2;
map<int, int >table;
map<int, int>::iterator it;
int N;
int start_ad;
int now_pos;
bool compare(NODE V1, NODE V2)
{
	return V1.key < V2.key;
}
int main()
{
	cin >> N>> start_ad;
	fx.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i].Address >> fx[i].key >> fx[i].Next;
		table.insert(pair<int, int>(fx[i].Address, i));
	}
	//delete
	now_pos = start_ad;
	while (now_pos >= 0)
	{
		it = table.find(now_pos);
		if (it != table.end())
		{
			now_pos = it->second;
			fx2.push_back(fx[now_pos]);
			now_pos = fx[now_pos].Next;
		}
		else
		{
			break;
		}
	} 


	sort(fx2.begin(), fx2.end(), compare);


	if (fx2.size() > 0)
	{
		if (fx2.size() > 1)
		{
			for (int i = 0; i < fx2.size() - 1; i++)
			{
				fx2[i].Next = fx2[i + 1].Address;
			}
		}
		fx2[fx2.size() - 1].Next = -1;
		printf("%d %05d\n", fx2.size(), fx2[0].Address);
	}
	else
	{
		printf("%d %d\n", 0, -1);
	}

	for (int i = 0; i < fx2.size(); i++)
	{
		printf("%05d %d ", fx2[i].Address, fx2[i].key);
		if (fx2[i].Next == -1)
			printf("%d", -1);
		else
			printf("%05d\n", fx2[i].Next);
	}

	cin >> N;

    return 0;
}

