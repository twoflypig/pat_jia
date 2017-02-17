// 1025.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
typedef struct
{
	char registration_number[15];
	int score;
	int final_rank;
	int location_number;
	int local_rank;
}NODE;
vector<NODE>fx;
NODE temp_in;
int pos_start = 0;
int pos_end = 0;
bool compare(NODE v1, NODE v2)
{
	if (v1.score != v2.score)
		return v1.score > v2.score;
	else
		return 	strcmp(&v1.registration_number[0], &v2.registration_number[0] )<0;
}
void localrank(int start, int end)
{
	int rank_count = 1;
	for (int k = start; k <= end; k++)
	{
		if (k != start)
		{
			if (fx[k].score == fx[k - 1].score)
				fx[k].local_rank = fx[k-1].local_rank;
			else
				fx[k].local_rank = rank_count;
		}
		else
		{
			fx[k].local_rank = rank_count;
		}
		rank_count++;
	}//rank;
}
void finalrank(int start, int end)
{
	int rank_count = 1;
	for (int k = start; k <= end; k++)
	{
		if (k != start)
		{
			if (fx[k].score == fx[k - 1].score)
				fx[k].final_rank = fx[k-1].final_rank ;
			else
				fx[k].final_rank = rank_count;
		}
		else
		{
			fx[k].final_rank = rank_count;
		}
		rank_count++;
	}//rank;
}
int main()
{
	cin >> N;
	for (int i= 0; i < N; i++)
	{
		cin >> K;
		cin.get();
		for (int j = 0; j < K; j++)
		{
			scanf("%s %d", &temp_in.registration_number[0], &temp_in.score);
			cin.get();
			temp_in.location_number = i + 1;
			fx.push_back(temp_in);
		}
		pos_end = pos_start + K;
		sort(fx.begin() + pos_start, fx.begin() + pos_end, compare);//sort
		localrank(pos_start, pos_end-1);
		pos_start = pos_end ;
	}
	sort(fx.begin() , fx.end(), compare);//sort
	finalrank(0, fx.size() - 1);
	cout << fx.size() << endl;
	for (int i = 0; i < fx.size(); i++)
	{
		printf("%s %d %d %d\n", &fx[i].registration_number[0], fx[i].final_rank, fx[i].location_number, fx[i].local_rank);
	}
	cin >> N;
    return 0;
}

