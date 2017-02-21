// 1118.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 10010

int N;
int K;
int tembird;
//在集合中查找
bool findflag = false;
int id1, id2;
int totalbirds = 0;
int father[MAX] = { 0 };
bool exist[MAX];
int cnt[MAX] = { 0 };
int totaltree = 0;
int findfather(int index)
{
	int temp = index;
	int z;
	while (index != father[index])
	{
		index = father[index];
	}
	//找到老爸后压缩路径
	while (father[temp] != temp)
	{
		z = temp;
		father[temp] = index;
		temp = father[z];
	}
	return index;
}
//这个Union 操作  来新的数据时，会将其组织在一起，如果出现一个其他集合的，那么v1 v2 v3 v4  father[v4]正好找到father,v3是v1v2v3的father，合并到已有的集合中
void Union(int index1, int index2)
{
	index1 = findfather(index1);
	index2 = findfather(index2);
	if (index1 != index2)
	{
		father[index1] = index2;
	}
}
int main()
{
	memset(cnt, 0, sizeof(int)*MAX);
	for (int i = 0; i < MAX; i++)
	{
		father[i] = i;
		exist[i] = false;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> K>>id1;
		exist[id1] = true;
		for (int j = 0; j < K-1; j++)
		{
			cin >> tembird;
			exist[tembird] = true;
			Union(id1, tembird);
		}
	}
	for (int i = 1; i <= MAX; i++)
	{
		if (exist[i] == true)
		{
			int fa = findfather(i);
			cnt[fa]++;
		}
	}
	totaltree = 0;
	totalbirds = 0;
	for (int i = 1; i <= MAX; i++)
	{
		if (exist[i] == true && cnt[i]!=0)
		{
			totaltree++;
			totalbirds += cnt[i];
		}
	}
	cout << totaltree << " " << totalbirds << endl;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> id1 >> id2;
		if(findfather(id1) == findfather(id2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

    return 0;
}

