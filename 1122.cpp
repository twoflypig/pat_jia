// 1122.cpp : �������̨Ӧ�ó������ڵ㡣
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
//Ҫ�������·������һ���򵥻���ֻ��һȦ�����Ұ������н���������ĿҪ��
//������Ҫ�������жϣ�·������ͨ������Ҫ��·��ͷβ�����ִ���ӦΪ2�Σ��м��Ϊ1�Σ����е㶼������ֹ���
bool check(int index)
{
	//index���ܷ��ʵ��Ľڵ�
	for (int i = 0; i < verarry.size(); i++)
	{
		if (i < verarry.size() - 1)
		{
			if (G[verarry[i]][verarry[i + 1]] == 0)//��ͨ
			{
				return false;
			}
		}
		++tage[verarry[i]];
	}
	if (verarry[verarry.size() - 1] !=verarry[0] || verarry.size() <vertexs)//��ͨ
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
	tage.resize(vertexs+1);//��Ӧ����ı��
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
		//��һ��DFS����
		if (check(verarry[0]) == true)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}
    return 0;
}

