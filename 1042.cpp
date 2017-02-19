// 1042.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int repeat = 0;
vector<string>card(55);
vector<string>newcard(55);
vector<int >order(55);
string strtemp;
string strtemp2="0";
int main()
{
	cin >> repeat;
	for (int i = 1; i <= 54; i++)
	{
		cin >> order[i];
	}
	//sort(order.begin(), order.end());
	//produce cards
	for (int j = 0; j < 4; j++)
	{
		if (j == 0)
			strtemp = "S0";
		else if (j == 1)
			strtemp = "H0";
		else if (j == 2)
			strtemp = "C0";
		else
			strtemp = "D0";
		for (int i = 1; i <= 13; i++)
		{
			if (i >= 10)
			{
				strtemp[1] = '1';
				card[i+j*13] = strtemp;
				strtemp2[0] = i % 10 + '0';
				card[i+j*13].append(strtemp2);
			}
			else
			{
				strtemp[1] = i + '0';
				card[i+j*13] = strtemp;
			}
		}
	}
	card[53] = "J1";
	card[54] = "J2";
	for (int i = 0; i < repeat; i++)
	{
		for (int j = 1; j <= 54; j++)
		{
			newcard[order[j]] = card[j];
		}
		card = newcard;
	}
	for (int i = 1; i <= 54; i++)
	{
		if (i!=1)
			cout << " ";
		cout << card[i];
	}

	cin >> repeat;
    return 0;
}

