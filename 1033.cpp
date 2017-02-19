// 1033.cpp : 定义控制台应用程序的入口点。
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
int findFlag = 0;//没有找到，但找到大一点的
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
		//在距离内找一个最小的  初始时不能包括自己
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
		if (findFlag == 1)//有站点找到
		{
			tem_store = (station[aim_station].distance - travelMax)*1.0 / Davg;
			if (station[aim_station].price < now_price)//当前高  看下原有的耗油量够不够
			{
					if (tem_store < store)
						store -= tem_store;
					else
					{
						priceSpend += now_price *(tem_store - store);
						store = 0;
					}
			}
			else//当前价格低  
			{
				if (travelMax + CarDisMax >= D)//如果是终点，就冲过去
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
				else//加满油？？？？
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
			if (travelMax + CarDisMax >= D)//如果是终点，就冲过去
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

