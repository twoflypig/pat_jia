// 1074.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int K;
typedef struct
{
	int adress;
	int key;
	int next_ad;
}NODE;
int HushTable[100002] = { 0 };
vector<NODE> buff;
vector<NODE> buff2;
NODE temp_in;
int start_ad;
int store_startad = 0;
int k;
int had_reverse= 0 ;
int this_reverse = 0;
int main()
{
	cin >> start_ad >>N>>K;
	for (int i = 0; i < N; i++)
	{
		cin >> temp_in.adress >> temp_in.key >> temp_in.next_ad;
		buff.push_back(temp_in);
		HushTable[temp_in.adress] = i;
	}
	while (had_reverse + K <= N )
	{
		k = K;
		this_reverse = 0;
		store_startad = start_ad;
		while (k)
		{
			if (start_ad != -1)
			{
				buff2.push_back(buff[HushTable[start_ad]]);
				start_ad = buff[HushTable[start_ad]].next_ad;
			}
			else
				break;
			--k;
			this_reverse++;
		}
		if( this_reverse == K)
		{ 
			reverse(buff2.begin() + had_reverse, buff2.begin() + had_reverse + K);
			had_reverse += K;
		}
		else
		{
			buff2.erase(buff2.begin() + had_reverse, buff2.begin() + had_reverse + this_reverse);
			start_ad = store_startad;
			break;
		}
	}
	for (int i = 0; i < buff2.size() - 1; i++)
	{
		buff2[i].next_ad = buff2[i + 1].adress;
	}
	if (buff2.size() > 0)
		buff2[buff2.size() - 1].next_ad = start_ad;

	for (int i = 0; i < buff2.size() ; i++)
	{
		printf("%05d %d ", buff2[i].adress, buff2[i].key);
		if (buff2[i].next_ad == -1)
			printf("%d", -1);
		else
			printf("%05d\n", buff2[i].next_ad);
	}
	while (start_ad != -1)
	{
		printf("%05d %d ", buff[HushTable[start_ad]].adress, buff[HushTable[start_ad]].key);
		if (buff[HushTable[start_ad]].next_ad == -1)
			printf("%d", -1);
		else
			printf("%05d\n", buff[HushTable[start_ad]].next_ad);
		start_ad = buff[HushTable[start_ad]].next_ad;
	}

	cin >> start_ad;
    return 0;
}

