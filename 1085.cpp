// 1085.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
long double N, p;
int M, m;
int pMax,pMin;
int flag = 0;
long double c1, c2;
int maxnumber = 1;
int main()
{
	cin >> N >> p;
	cin.get();
	vector<long double>fx(N);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i];
	}
	sort(fx.begin(), fx.end());
	for (pMin = 0;pMin <N; pMin++)
	{
		while (pMin + maxnumber < N && fx[pMin + maxnumber] <= fx[pMin] * p) maxnumber++;
	}

		cout << maxnumber;
	cin >> N;
	return 0;
}

