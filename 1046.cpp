// 1046.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int N;
int M;
int c1, c2;
vector<int >output;
int min(int v1,int v2)
{
	return v1 > v2 ? v2 : v1;
}
void swap(int& va, int &vb)
{
	int temp = 0;
	temp = va;
	va = vb;
	vb = temp;
}
int main()
{
	cin >> N;

	vector<int >fx(N+1);
	vector<int >fa(N + 1);
	vector<int >fb(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> fx[i];
	}
	cin.get();
	
	//计算从0到这些点的距离
	for (int i = 2; i <= N; i++)
	{
		fa[i] = fx[i-1]+fa[i-1];
	}
	for (int i = N; i >=1; i--)
	{
		if (i == N)
		{
			fb[i] = fx[N];
		}
		else
		{
			fb[i] = fx[i] + fb[i+1];
		}
	}

	cin >> M;
	cin.get();
	for (int i = 0; i < M; i++)
	{
		cin >> c1 >> c2;
		if (c1 > c2)
			swap(c1, c2);//c2max
		cin.get();
		output.push_back(min( fa[c2] - fa[c1], fb[c2] +  fa[c1]));
	}
	for (int i = 0; i < M; i++)
	{
		cout << output[i] << endl;
	}

	cin >> N;
    return 0;
}

