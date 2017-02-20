// 1109.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct
{
	string name;
	double heght;
}NODE;
int N;
int K;
int limit = 0;
vector<NODE>arry;
vector<vector<string>>martix;
bool cmp(NODE &v1, NODE &v2)
{
	if (v1.heght != v2.heght)
		return v1.heght > v2.heght;
	else
		return v1.name < v2.name;
}
int fx(int v1,int total)
{
	if (v1 == 0)
	{
		return (total / 2 );
	}
	else
	{
		if (v1 % 2 == 1)
		{
			return  (total / 2) - (v1+1)/2;
		}
		else
		{
			return  (total / 2) + (v1)/2;
		}
	}
	//第一个数放K
}
int main()
{
	int M = 0,k;
	cin >> N >> K;
	arry.resize(N );
	for (int i = 0; i < N; i++)
	{
		cin >> arry[i].name >> arry[i].heght;
	}
	sort(arry.begin(), arry.end(), cmp);
	M = round(N *1.0/ K);//多处的人放最后一行
	martix.resize(M, vector<string>(N%K + K));

	k = 0;
	for (int i = 0; i < M; i++)
	{
		if (i == 0)
			limit = N%K + K;
		else
			limit = K;
		for (int j = 0; j < limit; j++)
		{
			martix[i][fx(j, limit)] = arry[k++].name;
		}
		for (int j = 0; j < limit; j++)
		{
			if (j)
				cout << " ";
			cout << martix[i][j];
		}
		cout << endl;


	}

    return 0;
}

