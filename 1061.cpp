// 1061.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>;
using namespace std;
vector<string>fx(4);
int CapitalCharacter[300] = {0};
char c;
int state = 0;
void Print(int value)
{
	switch (value)
	{
	case 0:
	{
		cout << "MON";
		break;
	}
	case 1:
	{
		cout << "TUE";
		break;
	}
	case 2:
	{
		cout << "WED";
		break;
	}
	case 3:
	{
		cout << "THU";
		break;
	}
	case 4:
	{
		cout << "FRI";
		break;
	}
	case 5:
	{
		cout << "SAT";
		break;
	}
	case 6:
	{
		cout << "SUN";
		break;
	}

	default:
		break;
	}
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> fx[i];
	}
	//对str1遍历
	for (int i = 0; i < fx[0].size(); i++)
	{
		c = fx[0].at(i);
		if ((c <= 'Z' && c >= 'A') || (c <= '9'&& c >= '0'))
		{
			CapitalCharacter[c]++;
		}
	}
	//对str2搜索
	for (int i = 0; i < fx[1].size()&& state<=1; i++)
	{
		c = fx[1].at(i);
		if ((c <= 'Z' && c >= 'A') || (c <= '9'&& c >= '0'))
		{
			if (CapitalCharacter[c] != 0)
			{

				switch (state)
				{
				case 0:
				{
					if (c <= 'Z' && c >= 'A')
					{
						Print(c - 'A');
						cout << " ";
						state++;
					}
					break;
				}
				case 1:
				{
					if (c <= '9'&& c >= '0')
					{
						cout << 0 << c << ":";

					}
					else
					{
						cout << (int)(c - 'A' + 10) << ":";
					}
					state++;
					break;
				}
				default:
					break;
				}
			}
		}
	}
	//搜索str3 str4
	int i = 0, j = 0;
	while (i < fx[2].size() && j < fx[3].size())
	{
		if (fx[2].at(i) == fx[3].at(j) &&  (fx[2].at(i)>='A'&& fx[2].at(i) <= 'Z' || fx[2].at(i) >= 'a'&& fx[2].at(i) <= 'z'))
		{
			break;

		}
		else
		{
			i++;
			j++;
		}
	}
	printf( "%02d", i);

	cin >> i;
    return 0;
}

