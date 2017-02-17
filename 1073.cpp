// 1073.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string fx;
string orignal;
int k = 0;
int start = 0;
int p_end;
int pro_pos = 0;
int zero_count = 0;
int main()
{
	cin >> fx;
	if (fx[0] == '+' || fx[0] == '-')
		start = 1;
	else
		start = 0;
	pro_pos = start + 1;
	for (p_end = start; fx[p_end] != 'E'; p_end++);
	orignal = fx.substr(start, p_end-1);//pend point to E pos
	sscanf(&fx.substr(p_end + 1, fx.size() - 1)[0], "%d", &k);
	if (fx[0] == '-')
		cout << '-';
	if (pro_pos + k +1>=p_end )
	{
		for (int i = 0; i < orignal.size(); i++)
		{
			if (orignal[i] != '.')
				cout << orignal[i];
		}
		zero_count = pro_pos + k + 1 - p_end;
		while (zero_count--)
			cout << '0';
		//说明是大于后面的次数
	}
	else if (pro_pos + k  < p_end-1 && k>=0)
	{
		for (int i = 0; i < orignal.size(); i++)
		{
			if (orignal[i] != '.')
				cout << orignal[i];
			if (pro_pos + k -1  == i)
				cout << '.';
		}
	}
	else
	{
			cout << "0.";
			zero_count = abs(k)-1;
			while (zero_count--)
				cout << '0';
			for (int i = 0; i < orignal.size(); i++)
			{
				if (orignal[i] != '.')
					cout << orignal[i];
			}
	}
	

	cin >> zero_count;
    return 0;
}

