// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//


//============================================================================
// Name        : PublicBikeManagement.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define INFINATE 65535
int station_dis[500 + 1][500 + 1] = { 0 };//´ÓiÕ¾µ½jÕ¾µÄ¾àÀë
int station_bikes[500 + 1];//Ã¿¸öÕ¾µÄ×ÔÐÐ³µ×ÜÊý
int final[500 + 1] = { 0 };
int sum = 0;
int min_sum = INFINATE;
int CMax;// Ò»¸öÕ¾×ÔÐÐ³µµÄ×ÜÊý
int N;//Õ¾µÄ×ÜÊý
int Sp;//ÓÐÎÊÌâµÄ³µÕ¾
int M;//³µµÀÊý
int charges = 0;//the charges of a road
int min_charges = INFINATE;
stack<int >road;
stack<int >min_road;
stack<int >output;
int abs(int value)
{
	if (value<0)
	{
		return -value;
	}
	return value;
}
int dfs(int start, int N)
{
	
	for (int i = 1; i <= N; i++)
	{
		if (station_dis[start][i] != INFINATE)
		{
			if (i == Sp) //it is available from start to i
			{
				charges += station_dis[start][i];
				sum += station_bikes[i];
				if (min_charges > charges)
				{
					min_charges = charges;
					min_road = road;
					min_sum = sum;
				}
				else if (min_charges == charges)//check the number of bikes when charge of roads are same  
				{
					int temp1 =  CMax / 2 * (min_road.size() + 1) - min_sum;//send bikes
					int temp2 =  CMax / 2 * (road.size() + 1) - sum ;//send bikes
					if (abs(temp1) > abs(temp2) && temp1 > temp2)
					{
						//find a smaller road
						min_road = road;
						min_sum = sum;
					}
				}
				charges -= station_dis[start][i];
				sum -= station_bikes[i];
			}
			else if (final[i] == 0)
			{
				sum += station_bikes[i];
				charges += station_dis[start][i];
				final[i] = 1;
				road.push(i);
				dfs(i, N);
				road.pop();
				sum -= station_bikes[i];
				charges -= station_dis[start][i];
			}
		}
	}

	return 0;
}

int main() {



	//get global information;
	cin >> CMax >> N >> Sp >> M;
	cin.get();

	//get bikes
	for (int i = 1; i <= N; i++)
	{
		cin >> station_bikes[i];
		final[i] = 0;
	}
	cin.get();
	for (int i = 0; i<N + 1; i++)
	{
		for (int j = 0; j <N + 1; j++)
		{
			station_dis[i][j] = INFINATE;
		}
	}

	//get  roads information
	int temp_i, temp_j;
	for (int i = 1; i <= M; i++)
	{
		cin >> temp_i >> temp_j;
		cin >> station_dis[temp_i][temp_j];
		cin.get();
	}

	//begin dfs  from o -> Sp
	final[0] = 1;
	dfs(0, N);
	//end
	output.push(Sp);
	while (min_road.empty() == false)
	{
		output.push(min_road.top());
		min_road.pop();
	}
	int send = 0;
	int receive = 0;
	send = CMax / 2 *(output.size()) - min_sum ;
	if (send < 0)
	{
		receive = -send;
		send = 0;
	}
	cout <<send <<" ";
	cout << 0;
	while (output.empty() == false)
	{
		cout << "->" << output.top();
		output.pop();
	}
	cout << " " << receive;

	getchar();
	return 0;
}
