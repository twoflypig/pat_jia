// 1070.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, SumAmount, Result;
double Profit = 0;
typedef struct
{
	int amount;
	int price;
	double rate;
}NODE;
bool compare(NODE v1, NODE v2)
{
	return v1.rate > v2.rate;
}
int main()
{
	cin >> N >> SumAmount;
	vector<NODE>fx(N);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i].amount;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i].price;
	}
	for (int i = 0; i < N; i++)
	{
		fx[i].rate = fx[i].price*1.0/fx[i].amount;
	}
	sort(fx.begin(), fx.end(), compare);
	for (int i = 0; i < N&&SumAmount>0; i++)
	{
		Result = SumAmount - fx[i].amount;
		if (Result < 0)
		{
			Profit += (fx[i].price *SumAmount*1.0/fx[i].amount);
			SumAmount = 0;
		}
		else
		{
			Profit += (fx[i].price);
			SumAmount = Result;
		}
	}

	printf("%.2f", Profit);

	cin >> N;
    return 0;
}

