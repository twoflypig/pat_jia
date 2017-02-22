// 1100.cpp : 定义控制台应用程序的入口点。
//
//最容易犯的错误是13的整倍数输出问题，例如39，应该输出maa而不是maa tret。
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int>table;
map<string, int>table2;
string mon[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string mon2[13] = { "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
string temstr;
string temstr2;
vector<string>earthtoMar;
int N;
int temnum;
void earthtomars(int value)
{
		int temp = value % 13;
		if (temp == 0 && value>=13)
		{

		}
		else
		{
			earthtoMar.push_back(mon[temp]);
		}
		value /= 13;
		temp = value % 13;
		if (temp == 0)
			return;
		else
			earthtoMar.push_back(mon2[temp]);
}
int main()
{
	cin >> N;
	cin.get();
	for (int i = 0; i < 13; i++)
	{
		table[mon[i]] = i;
	}
	for (int i = 0; i < 13; i++)
	{
		table2[mon2[i]] = i;
	}
	for (int i = 0; i < N; i++)
	{
		getline(cin, temstr);
		if (temstr[0] <= '9'&& temstr[0] >= '0')
		{
			earthtoMar.clear();
			sscanf(temstr.c_str(), "%d", &temnum);
			earthtomars(temnum);
			for (int i =earthtoMar.size()-1; i >=0; i--)
			{
				if (i != earthtoMar.size()-1)
					cout << " ";
				cout << earthtoMar[i];
			}
			cout << endl;
		}
		else
		{
			int sum = 0;
			int temp =1;
			temstr2.clear();
			for (int i = 0 ; i <temstr.size(); i++)
			{
				if ( temstr[i] == ' ')
				{
					temstr2 = temstr.substr(i + 1, temstr.size() -i);
					temstr.erase(temstr.begin() + i, temstr.end());
					break;
				}
			}
			if (table2.find(temstr) != table2.end())
			{
				temp = table2[temstr];
				sum += (temp * 13);
				if (temstr2.size()!=0)
				{
					temstr = temstr2;
				}
			}
			if (table.find(temstr) != table.end())
			{
				temp = table[temstr];
				sum += temp;
			}
			cout << sum << endl;
		}
	}
    return 0;
}

