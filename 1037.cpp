// 1037.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Nc;
int Np;
vector<int >cc_z;
vector<int >cc_f;
vector<int >pp_z;
vector<int >pp_f;
bool cmp(int v1, int v2)
{
	return abs(v1) > abs(v2);
}
int sum = 0;
int temp = 0;
int p1_start, p1_end;
int p2_start, p2_end;
int main()
{
	cin >> Nc;
	for (int i = 0; i < Nc; i++)
	{
		cin >>temp ;
		if (temp > 0)
			cc_z.push_back(temp);
		else
			cc_f.push_back(temp);
	}
	cin >> Np;
	for (int i = 0; i < Np; i++)
	{
		cin >> temp;
		if (temp > 0)
			pp_z.push_back(temp);
		else
			pp_f.push_back(temp);
	}
	sort(cc_z.begin(), cc_z.end(), cmp);
	sort(cc_f.begin(), cc_f.end(), cmp);
	sort(pp_f.begin(), pp_f.end(), cmp);
	sort(pp_z.begin(), pp_z.end(), cmp);
	for (int i = 0, j = 0; i < cc_z.size() && j < pp_z.size(); i++, j++)
	{
		sum += cc_z[i] * pp_z[j];
	}
	for (int i = 0, j = 0; i < cc_f.size() && j < pp_f.size(); i++, j++)
	{
		sum += cc_f[i] * pp_f[j];
	}
	cout << sum;
	return 0;
}

