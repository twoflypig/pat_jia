// 1056.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

#include <queue>
using namespace std;
int N, G;
vector<int >Wi;
vector<int >order;
vector<bool>tage;
vector<int >arry;
vector<int >Trank;
queue <int >outque;
int hadcheck = 0;
int main()
{
	cin >> N >> G;
	Wi.resize(N);
	order.resize(N);
	tage.resize(N);
	arry.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> Wi[i];
	}
	for (int i = 0; i < N; i++)
		cin >> order[i];
	int peopleUp = 0;
	int max_weight =-1;
	int max_index = 0;
	while (hadcheck < N)
	{
		peopleUp = 0;
		for (int i = 0 ; i<N ;)//ѡ��3���� j��ʾ���˶��ٸ���
		{
			Trank.clear();
			max_weight = -1;
			for (; i < N && Trank.size() <G; i++) //��G����
			{
				if (tage[order[i]] == false)
				{
					Trank.push_back(order[i]);
					if (max_weight < Wi[order[i]])
					{
						max_weight = Wi[order[i]];
						max_index = order[i];
					}
				}
			}
			for (int j = 0; j < Trank.size(); j++)//
			{
				if ( Wi[Trank[j]] == max_weight)//��������
				{
					peopleUp++;
				}
				else
				{
					tage[Trank[j]] = true;//���Ϊ�Ѿ�����  Trank�������Ǳ��
					outque.push(Trank[j]);// = 0;
					hadcheck++;
				}
			}
		}
		//������һ�ֽ���
		while (outque.empty() == false)
		{
			arry[outque.front()] = peopleUp + 1;
			outque.pop();
		}
		if (hadcheck == N - 1)
		{
			arry[max_index] =1;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i)
			cout << " ";
		cout << (arry[i]);
	}

    return 0;
}

