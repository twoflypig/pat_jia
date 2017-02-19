// 1033.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Cmax, D, Davg, N;
typedef struct
{
	double price;
	int distance;
}NODE;
vector<NODE >station(501);
bool cmp(NODE v1, NODE v2)
{
	if (v1.distance != v2.distance)
		return v1.distance < v2.distance;
	else
		return v1.price < v2.price;
}
double travelMax = 0;
double priceSpend = 0;
double CarDisMax = 0;
int aim_station = 0;
double now_price = 0;
int findFlag = 0;//û���ҵ������ҵ���һ���
double store = 0;
double tem_store = 0;
int main()
{
	cin >> Cmax >> D >> Davg >> N;
	CarDisMax = Cmax*Davg;
	for (int i = 0; i < N; i++)
	{
		cin >> station[i].price >> station[i].distance;
	}
	sort(station.begin(), station.begin() + N, cmp);
	now_price = station[0].price;
	aim_station = 0;
	store = 0;
	while (travelMax < D)
	{
		//�ھ�������һ����С��  ��ʼʱ���ܰ����Լ�
		findFlag = 0;
		aim_station = aim_station + 1;
		for (int i = aim_station; i < N && station[i].distance <= travelMax + CarDisMax  ; i++)
		{
			if (station[aim_station].price >= station[i].price)
			{
				aim_station = i;
				findFlag = 1;
			}
		}
		if (findFlag == 1)//��վ���ҵ�
		{
			tem_store = (station[aim_station].distance - travelMax)*1.0 / Davg;
			if (station[aim_station].price < now_price)//��ǰ��  ����ԭ�еĺ�����������
			{
					if (tem_store < store)
						store -= tem_store;
					else
					{
						priceSpend += now_price *(tem_store - store);
						store = 0;
					}
			}
			else//��ǰ�۸��  
			{
				if (travelMax + CarDisMax >= D)//������յ㣬�ͳ��ȥ
				{
					tem_store = (D - travelMax)*1.0 / Davg;
					if (tem_store < store)
						store -= tem_store;
					else
					{
						priceSpend += now_price *(tem_store - store);
						store = 0;
					}
					travelMax = D;
					break;
				}
				else//�����ͣ�������
				{
					priceSpend += now_price*(Cmax - store);
					store = Cmax - tem_store;
				}
			}
			travelMax = station[aim_station].distance;
			now_price = station[aim_station].price;
		}
		else
		{
			if (travelMax + CarDisMax >= D)//������յ㣬�ͳ��ȥ
			{
				tem_store = (D - travelMax)*1.0 / Davg;
				if (tem_store < store)
					store -= tem_store;
				else
				{
					priceSpend += now_price *(tem_store - store);
					store = 0;
				}
				travelMax = D;
			}
			else
			{
				priceSpend += now_price*(Cmax - store);
				travelMax += CarDisMax;
			}
			break;
		}
	}
	if (travelMax == D)
		printf("%.2lf", priceSpend);
	else
		printf("The maximum travel distance = %.2lf", travelMax);//<<travelMax;

	cin >> N;
	
    return 0;
}

