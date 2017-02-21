// 1121.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX 100010
using namespace std;
int table[MAX] = { 0 };
bool tage[MAX];
vector<int> lol;
vector<int >arry;
int main()
{
	memset(table, -1, MAX*sizeof(int));
	memset(tage, false, MAX * sizeof(bool));
	int N;
	cin >> N;
	int id1, id2;
	for (int i = 0; i < N; i++)
	{
		cin >> id1 >> id2;
		table[id1] = id2;
		table[id2] = id1;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> id1;
		tage[id1] = true;
		arry.push_back(id1);
	}
	for (int i = 0; i < N; i++)
	{
		if (table[arry[i]] == -1)
		{
			lol.push_back(arry[i]);
		}
		else if (tage[arry[i]] == false && tage[table[arry[i]]] == true)
		{
			lol.push_back(arry[i]);
		}
		else if (tage[arry[i]] == true && tage[table[arry[i]]] == false)
		{
			lol.push_back(arry[i]);
		}
	}
	sort(lol.begin(), lol.end());
	cout << lol.size() << endl;
	for (int i = 0; i < lol.size(); i++)
	{
		if (i)
			cout << " ";
		printf("%5d", lol[i]);
	}
	//cout << endl;
    return 0;
}

