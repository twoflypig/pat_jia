// 1021.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��ô���ʱ��أ�
#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> >G;
vector<int >length;
vector<bool>tage;
vector<int >connect;
int N;
int v1, v2;
int hadcheck = 0;//�Ѿ����ʵĽڵ���
int temleng = -1;
int maxleng = 0;
int connectindex = 1;
int addflag = 0;
void dfs(int index, int & number, int deep)
{
	tage[index] = true;
	number++;//��¼�����Ѿ����ʹ�����
	deep++;
	for (int i = 0; i < G[index].size(); i++)//��index�ڵ�ĺ��ӽ��з���
	{
		if (tage[G[index][i]] == false)
		{
			dfs(G[index][i], number, deep);
		}
	}
	temleng = max(temleng, deep);
	deep--;
}
int find 
int main()
{
	cin >> N;
	G.resize(N + 1);
	length.resize( N + 1);
	tage.resize(N + 1);
	connect.resize(N + 1);
	for (int i = 0; i < N-1; i++)//ע���Ŵ�1-N
	{
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	//��ʼdfs
	//��ͬͼ��һ��dfs�Ϳ��Է����꣬�������ͨͼһ�η��ʲ���
	//һ�η���ʱ��¼�Ѿ����ʵĸ���
	int deep;
	for (int i = 1; i <= N; i++)
	{
		hadcheck = 0;
		temleng = 0;
		deep = 0;
		dfs(i, hadcheck, deep);
		addflag = 0;
		for (int j = 1; j <= N; j++)//�ò��鼯��˼��
		{
			if (hadcheck <N)
			{
				if ( (i == 1 && tage[j] == true) ||(tage[j] == true && connect[j]==0 ))//��һ��
				{
					addflag = 1;
					connect[j] = connectindex;
				}
			}
			tage[j] = false;
		}
		if (addflag)
			connectindex++;
		length[i] = temleng;
		maxleng = max(maxleng, temleng);
	}
	if (connectindex > 1)
		printf("Error: %d components", connectindex-1);
	else
	{
		for (int i = 1; i <= N; i++)
			if (length[i] == maxleng)
				cout << i<<endl;
	}
    return 0;
}

