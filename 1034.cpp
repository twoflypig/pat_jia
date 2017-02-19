// 1034.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 2001
using namespace std;
typedef struct
{
	string name;
	int number;
}Head;
int G[MAX][MAX] = { 0 };
map<string, int>table;
map<string, int >outpeople;
vector<int>TotalTime(2001);//点权
vector<bool>Check(2001);//是否已经方位
string str1, str2;
int time1;
int N, Thresh;
int id1, id2;
int users_index=0;
int tempPrice = 0;
int maxIndex = 0;
int countPerone = 0;

bool cmp(Head v1, Head v2)
{
	return strcmp(v1.name.c_str() , v2.name.c_str())<0;
}
int  Add_User(string strin,int time =0)
{
	map<string, int>::iterator it = table.find(strin);
	if (it != table.end())
	{
		TotalTime[it->second] += time;
		return it->second;
	}
	else
	{
		table.insert(pair<string, int>(strin, users_index));
		TotalTime[users_index] += time;
		users_index++;
		return users_index-1;
	}
}
void dfs(int visitindex,int & time)
{
	if (Check[visitindex] == false)
	{
		countPerone++;
		Check[visitindex] = true;
		for (int i = 0; i < users_index; i++)
		{
			if (G[visitindex][i] != 0)
			{
				time += G[visitindex][i];//累计权值
				G[visitindex][i] = G[i][visitindex] = 0;
				if (TotalTime[maxIndex] < TotalTime[i])
					maxIndex = i;
				dfs(i, time);
			}
		}
	}
}
int main()
{
	cin >> N >> Thresh;
	for (int i = 0; i < N; i++)
	{
		cin >> str1 >> str2 >> time1;
		id1 = Add_User(str1, time1);
		id2 = Add_User(str2, time1);
		G[id1] [id2] +=time1;
		G[id2] [id1] += time1;
	}
	for (int i = 0; i < users_index; i++)
	{
		if (Check[i] == false)
		{
			maxIndex = i;
			countPerone = 0;
			tempPrice = 0;
			dfs(i, tempPrice);
			if (tempPrice > Thresh &&countPerone > 2)
			{
				for (map<string, int >::iterator it = table.begin(); it != table.end(); it++)
				{
					if (it->second == maxIndex)
					{
						outpeople[it->first] = countPerone;
					}
				}
			}
		}
	}
	cout << outpeople.size() << endl;
	for (map<string, int>::iterator it = outpeople.begin(); it != outpeople.end(); it++)
		cout << it->first << " " << it->second << endl;

	cin >> N;
	return 0;
}

