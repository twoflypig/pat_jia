// 1039.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <list>
#define MAXHUSH 1800000
using namespace std;
vector<list<int>>fx(40006);
int HushTable[1800000];
int N, K;
int course_index, student_num;
int student_index = 1;
int temp_index;
string str_temp;
list<int>::iterator it;
int Hush(const string  str_in)
{
	int temp = 0;
	for (int i = 0; i < 3; i++)
	{
		temp = temp * 26 + str_in[i] - 'A';
	}
	temp = temp * 10 + str_in[3] - '0';
	return temp;
}
int main()
{
	cin >> N >> K;
	memset(HushTable, 0, sizeof(int)*1800000);
	for (int i = 0; i < K; i++)
	{
		cin >> course_index >> student_num;
		for (int j = 0; j < student_num; j++)
		{
			cin >> str_temp;
			temp_index = HushTable[Hush(str_temp)];
			if (temp_index == 0)
			{
				HushTable[Hush(str_temp)] = student_index;
				fx[student_index].push_back(course_index);
				++student_index;
			}
			else
			{
				fx[temp_index].push_back(course_index);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> str_temp;
		temp_index = HushTable[Hush(str_temp)];
		if (fx[temp_index].size() > 0)
		{
			fx[temp_index].sort();
			cout << str_temp << " " << fx[temp_index].size();
			for (it = fx[temp_index].begin(); it != fx[temp_index].end(); it++)
			{
				cout << " " << *it;
			}
			cout << endl;
		}
		else
			cout << str_temp << " 0" << endl;
	}

	cin >> N;
    return 0;
}

