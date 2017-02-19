// 1032.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
//map<int, int>table;
int table[100000] = {0};
typedef struct
{
	int adress;
	char key;
	int next;
}NODE;
int start1, start2;
int N;
int id1, id2;
vector<NODE> fx;
NODE tempnode;
int main()
{
	scanf("%d %d %d", &start1, &start2, &N);
	getchar();
	memset(&table, 0, 100000 * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d %c %d", &tempnode.adress, &tempnode.key, &tempnode.next);// >> tempnode.key >> tempnode.next;
		getchar();
		table[tempnode.adress] = i;
		fx.push_back(tempnode);
	}
	int length1 = 0;
	int p1 = start1;
	int length2= 0;
	int p2 = start2;
	while (p1 != -1)
	{
		p1 = fx[table[p1]].next;
		length1++;
	}
	while (p2 != -1)
	{
		p2 = fx[table[p2]].next;
		length2++;
	}
	if (length1 <length2)//认为2是短的
	{
		swap(length1, length2);
		swap(start1, start2);
	}

	p1 = start1;
	int i = 0;
	while (length1 - i != length2)
	{
		p1 = fx[table[p1]].next;
		i++;
	}

	p2 = start2;
	while (p1 != -1 && p2 != -1)
	{
		id1 = table[p1];
		id2 = table[p2];
		if (fx[id1].adress== fx[id2].adress)
		{
			break;
		}
		p1 = fx[id1].next;
		p2 = fx[id2].next;

	}
	if (p1 == -1 || p2 == -1)
		cout << "-1";
	else
		printf("%05d",fx[table[p1]].adress);

	cin >> N;

    return 0;
}

