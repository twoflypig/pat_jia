// 1047.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
#define MAX_N 400000
#define MAX_K 2501
using namespace std;

vector<list<string>>arry(MAX_K);
int N, K, C;
int main()
{
	string in_strtemp;
	int temp;
	scanf("%d %d", &N, &K);
	getchar();
	for (int i = 0; i < N; i++)
	{
		in_strtemp.resize(5);
		scanf("%s %d", &in_strtemp[0], &C);
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &temp);
			arry[temp].push_back(in_strtemp);
		}
		getchar();
	}
	for (int i = 1; i <= K; i++)
	{
		if (arry[i].size() != 0)
		{
			arry[i].sort();
			printf("%d %d\n", i, arry[i].size());
			list<string>::iterator it_end = arry[i].end();
			for (list<string>::iterator it = arry[i].begin(); it != it_end; it++)
			{
				puts((*it).c_str());
				//cout << *it << endl;
			}
		}
	}

	cin >> N;
    return 0;
}

