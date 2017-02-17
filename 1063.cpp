// 1063.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#define MAX_N 50
#define MAX_K 2000
using namespace std;
vector<map<int, int> >fx(MAX_N);
vector<vector<int> >buffer(MAX_N);
vector<int > num(MAX_N);
vector<vector<int> >quiry(MAX_K);
int N;
int K;
int M;
map<int, int>::iterator map_it;
int main()
{
	int temp = 0;
	int Nc = 0, Nt = 0;
	int base = 0;
	int look = 0;
	int leng = 0;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &M);
		num[i] = M;
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &temp);
			map_it = fx[i].find(temp);
			if (map_it == fx[i].end())
			{
				fx[i].insert(pair<int, int>(temp, j));
				buffer[i].push_back(temp);
			}

		}
		getchar();
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &temp);
		quiry[i].push_back(temp);
		scanf("%d", &temp);
		quiry[i].push_back(temp);
		getchar();
	}
	for (int i = 0; i < K; i++)
	{
		Nc =Nt = 0;
		base = quiry[i][0]-1;
		look = quiry[i][1]-1;
		leng = buffer[look].size();
		for (int j = 0; j <leng; j++)
		{
			map_it = fx[base].find(buffer[look][j]);

			if (map_it != fx[base].end())//找到
			{
				Nc++;
			}
		}

		Nt = fx[base].size() + fx[look].size() - Nc;
		if (i == K - 1)
		{
			printf("%.1f%%", Nc*1.0 / Nt * 100);
		}
		else
		{
			printf("%.1f%%\n", Nc*1.0 / Nt * 100);
		}
	}

	cin >> N;

    return 0;
}

