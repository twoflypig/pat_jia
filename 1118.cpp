// 1118.cpp : �������̨Ӧ�ó������ڵ㡣
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
//�ڼ����в���
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
	//�ҵ��ϰֺ�ѹ��·��
	while (father[temp] != temp)
	{
		z = temp;
		father[temp] = index;
		temp = father[z];
	}
	return index;
}
//���Union ����  ���µ�����ʱ���Ὣ����֯��һ���������һ���������ϵģ���ôv1 v2 v3 v4  father[v4]�����ҵ�father,v3��v1v2v3��father���ϲ������еļ�����
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

