// 1114.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef struct people
{
	int M_estate;
	int Area;
	set<int>selfset;
	people() :M_estate(0), Area(0) {};
}NODE;
typedef struct
{
	int min_id;
	int totalnum;
	double avg_estate;
	double avg_area;

}FMAILY;
int N;
vector<NODE>arry(10001);
vector<FMAILY>family;
FMAILY temfam;
vector<bool>visit(10001);
vector<int>table;
int id,mother,father,child,k;
void dfs(int id, FMAILY & famnode)
{
	if (visit[id] == false)
	{
		visit[id] = true;
		famnode.min_id = min(famnode.min_id, id);
		famnode.totalnum++;
		famnode.avg_area += arry[id].Area;
		famnode.avg_estate += arry[id].M_estate;
		for (set<int>::iterator it = arry[id].selfset.begin(); it != arry[id].selfset.end(); it++)
		{
			if (visit[*it] == false)
			{
				dfs(*it, famnode);
			}
		}
	}
}
bool cmp(FMAILY &v1, FMAILY &v2)
{
	if (v1.avg_area != v2.avg_area)
		return v1.avg_area > v2.avg_area;
	else
		return v1.min_id < v2.min_id;
}
int main()
{
	cin >> N;
	table.resize(N);
	for (int i = 0; i <N; i++)
	{
		cin >> id >> father >> mother>>k;
		table[i] = id;
		if (father != -1)
		{
			arry[id].selfset.insert(father);
			arry[father].selfset.insert(id);
		}
		if (mother != -1)
		{
			arry[mother].selfset.insert(id);
			arry[id].selfset.insert(mother);
		}
		for (int j = 0; j < k; j++)
		{
			cin >> child;
			arry[id].selfset.insert(child);
			arry[child].selfset.insert(id);
		}
		cin >> arry[id].M_estate >> arry[id].Area;
	}
	//开始遍历
	for (int i = 0; i < N; i++)
	{

		if (visit[table[i]] == false)
		{
			temfam.avg_area = 0;
			temfam.avg_estate = 0;
			temfam.totalnum = 0;
			temfam.min_id = 9999;
			dfs(table[i], temfam);//统计量
			temfam.avg_area /= temfam.totalnum;
			temfam.avg_estate /= temfam.totalnum;
			family.push_back(temfam);
		}

	}
	sort(family.begin(), family.end(), cmp);
	cout << family.size() << endl;
	for (int i = 0; i < family.size(); i++)
	{
		printf("%04d %d %.3f %.3f\n", family[i].min_id, family[i].totalnum, family[i].avg_estate, family[i].avg_area);
	}
    return 0;
}

