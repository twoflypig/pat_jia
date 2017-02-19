// 1108.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
string temp;
double value;
int effcount = 0;
double sum = 0;
int state = 0;
int flag = 0;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		state = 0;
		flag = 0;
		//check;
		for (int j = 0; j < temp.size(); j++)
		{
			if (state == 0)
			{
				if (temp[j] == '+' || temp[j] == '-')
					state = 1;//ok
				else if (temp[j] <= '9' && temp[j] >= '0')
					state = 1;//ok;
				else
				{
					flag = 1;
					break;
				}
			}
			else if (state == 1)//check . or number
			{
				if (temp[j] == '.')
					state = 2;
				else if (temp[j] < '0' && temp[j] >'9')
				{
					//error;
					flag = 1;
					break;
				}
			}
			else if (state <= 3)
			{
				if (temp[j] < '0' || temp[j] >'9')
				{
					flag = 1;//error;
					break;
				}
				state++;
			}
			else
			{
				flag = 1;//error;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "ERROR: " << temp<< " is not a legal number"<<endl;
		}
		else
		{
			sscanf(temp.c_str(), "%lf", &value);//double lf scanf

			if (value <= 1000 && value >= -1000)
			{
				effcount++;
				sum += value;
			}
			else
			{
				cout << "ERROR: " << temp << " is not a legal number" << endl;
			}
		}

	}
	if( effcount == 0)
		printf("The average of %d numbers is Undefined", effcount);
	else if( effcount ==1)
		printf("The average of 1 number is %.2lf\n", value);
	else
		printf("The average of %d numbers is %.2lf\n", effcount, sum / effcount);


    return 0;
}

