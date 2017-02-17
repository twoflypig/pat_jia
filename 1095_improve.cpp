// 1095_improve.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAX 10005
const int MAXRANGE = 24 * 60 * 60;
string decToTime(int time)
{
	char str[20];
	sprintf(str, "%02d:%02d:%02d", time / (60 * 60), time / 60 % 60, time % 60);
	return string(str);
}
int timeToDec(int h, int m, int s)
{
	return (h * 60 + m) * 60 + s;
}
class Car
{
public:
	string ID;
	int time;
	bool out;
public:
	bool isMatch(const Car &c)
	{
		return this->ID == c.ID&& this->time < c.time && this->out == false && c.out == true;
	}
	bool operator <(const Car &c) const
	{
		if (this->ID != c.ID)
		{
			return this->ID < c.ID;
		}
		else if (this->time != c.time)
		{
			return this->time < c.time;
		}
		else
		{
			return !this->out;
		}
	}
};
Car cars[MAX];
int sumCnt[MAXRANGE];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int h, m, s;
		cin >> cars[i].ID;
		scanf("%d:%d:%d", &h, &m, &s);
		cars[i].time = timeToDec(h, m, s);
		string status;
		cin >> status;
		if (status == "out")
		{
			cars[i].out = true;
		}
		else
		{
			cars[i].out = false;
		}
	}
	sort(cars, cars + N);

	map<string, int> parkTime;
	int maxParkTime = -1;
	for (int i = 0; i < N - 1; i++)
	{
		if (cars[i].isMatch(cars[i + 1]))
		{
			parkTime[cars[i].ID] += cars[i + 1].time - cars[i].time;
			if (maxParkTime < parkTime[cars[i].ID])
			{
				maxParkTime = parkTime[cars[i].ID];
			}
			sumCnt[cars[i].time]++;
			sumCnt[cars[i + 1].time]--;
		}
	}
	for (int i = 1; i < MAXRANGE; i++)
	{
		sumCnt[i] += sumCnt[i - 1];
	}
	for (int i = 0; i < K; i++)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		printf("%dn", sumCnt[timeToDec(h, m, s)]);
	}
	map<string, int>::iterator it;
	for (it = parkTime.begin(); it != parkTime.end(); ++it)
	{
		if (it->second == maxParkTime)
		{
			cout << it->first << " ";
		}
	}
	cout << decToTime(maxParkTime) << endl;
	int tmem;
	cin >> tmem;
	return 0;
}

