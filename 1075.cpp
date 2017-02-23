// 1075.cpp : 定义控制台应用程序的入口点。
//or those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000
using namespace std;
typedef struct node
{
	int id;
	int qustionid[6];
	int max_score; 
	int perfect;
	node()
	{
		id = 0;
		qustionid[0] = 0;
		qustionid[1] = qustionid[2] = qustionid[3] = qustionid[4] = qustionid[5] = -2;
		max_score = -1;
		perfect = 0;
	}
}NODE;
bool cmp(NODE v1, NODE v2)
{
	if (v1.qustionid[0] != v2.qustionid[0])//总分
		return v1.qustionid[0] > v2.qustionid[0];
	else if (v1.perfect != v2.perfect)//完美数
		return v1.perfect > v2.perfect;
	else//id
		return false;
}
vector<NODE>arry;
NODE temnode;
int questionMAX[6];
int N,K, M;
void Print(int value,int rank)
{
	printf("%d %05d %d", rank, arry[value].id, arry[value].qustionid[0]);
	for (int j = 1; j <= K; j++)
	{
		cout << " ";
		if (arry[value].qustionid[j] == -2)
			cout << '-';
		else if (arry[value].qustionid[j] == -1)
			cout << '0';
		else
			cout<<arry[value].qustionid[j];
	}
	cout << endl;
}
int main()
{
	cin >> N >> K >> M;
	arry.resize(N + 1);//从1开始计数
	for (int i=1; i <= K; i++)
	{
		cin>>questionMAX[i];
	}
	int id, queid, score;
	for (int i = 0; i < M; i++)
	{
		cin >> id >> queid >> score;
		//if (score != -1)//提交不是-1则
		//{
			arry[id].id = id;
			arry[id].qustionid[queid] = max(arry[id].qustionid[queid], score);
			arry[id].max_score = max(arry[id].qustionid[queid], arry[id].max_score);
		//}
		//else
		//{
		//	arry[id].id = id;
		//	arry[id].qustionid[queid] = -1;//标记为提交过
		//}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
				if(arry[i].qustionid[j]>=0)
					arry[i].qustionid[0] += arry[i].qustionid[j];
				if (arry[i].qustionid[j] == questionMAX[j])
					arry[i].perfect++;
		}
	}
	stable_sort(arry.begin() + 1, arry.end(), cmp);
	int rank = 1;
	int samerank = 1;
	for (int i = 1; i <= N; i++)
	{
		//检查是否提交过
		if (arry[i].max_score>=0)
		{
			if (i == 1)
			{
				Print(i, rank);
				samerank = 1;
				temnode = arry[i];
			}
			else
			{
				if (arry[i].qustionid[0] == temnode.qustionid[0])//当前与上一个总分相同
				{
					Print(i, samerank);
				}
				else
				{
					Print(i, rank);//总分不同
					samerank = rank;
					temnode = arry[i];
				}
			}
			rank++;
		}

	}
    return 0;
}

