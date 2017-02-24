// 1055.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include  <vector>
#include <queue>
using namespace std;

typedef struct node
{
	string name;
	int age;
	int worth;
}NODE;
bool cmp2(NODE &v1, NODE &v2)
{
	if (v1.worth != v2.worth)
		return v1.worth > v2.worth;
	else if (v1.age != v2.age)
		return v1.age < v2.age;
	else
		return v1.name < v2.name;
}
vector<NODE>arry;
vector<NODE>arry2;
int agenumer[201] = { 0 };
int keeptable[100000] = { 0 };
int id = 0;
NODE temnode;
int tempint;
int N, K,M,low,high;
int flag = 0;
int hadcheck = 0;

int main()
{
	cin >> N >> K;
	arry.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arry[i].name >> arry[i].age >> arry[i].worth;
	}

	sort(arry.begin(), arry.end(), cmp2);
	for (int i = 0; i < N; i++)
	{
		if (agenumer[arry[i].age] < 101)
		{
			agenumer[arry[i].age]++;
			keeptable[id++] = i;
		}

	}
	
	for (int i = 0; i < K; i++)
	{
		cin >> M >> low >> high;
		//scanf("%d %d %d", &M, &low, &high);
		flag = 0;
		printf("Case #%d:\n", i + 1);
		hadcheck = 0;
		for (int j = 0; j <id && hadcheck < M; j++)
		{
			if (arry[keeptable[j]].age <= high &&arry[keeptable[j]].age >= low)
			{
				hadcheck++;
				cout << arry[keeptable[j]].name;
				printf(" %d %d\n", arry[keeptable[j]].age, arry[keeptable[j]].worth);// arry[tempint].name << " " << arry[tempint].age << " " << arry[tempint].worth << endl;
			}
		}
		if(hadcheck == 0)
			cout << "None" << endl;
	}
    return 0;
}

