// 1082.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//思路 每隔4个数搜索
string str;
string table[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string table2[3] = { "","Wan","Yi" };
string table3[4] = { "Qian","","Shi","Bai",};
int back(int value)
{
	return str.size() - value;
}
void Print(string loc)
{
	static int i= 0;
	if (i && loc !="")
		cout <<" ";
	cout << loc;
	i++;
}
int main()
{
	int dt = 0;
	int pos_number = 0;
	int pos_index = 0;
	cin >> str;
	if (str[0] == '-')
	{
		dt += 1;
		cout << "Fu ";
	}
	else if (str[0] == '+')
	{
		dt += 1;
		cout << "Zheng ";
	}
	for (dt; dt < str.size(); dt++)
	{
		if (str[dt] != '0')
			break;
	}
	int zero_flag = 0;
	for (int i = str.size() - 1; i >= dt; i--)
	{
		pos_number++;
		if (pos_number % 4 == 0)
			pos_index++;
		if (str[i] != '0')
			zero_flag = 1;
	}
	if (pos_number % 4 == 0)
		pos_index--;
	if (zero_flag == 0)
	{
		cout << "ling" << endl;
		return 0;
	}
	int zero = 0;
	//先找第一个非零的数输出第一个数，然后检查区间内是否全零
	for (int i = pos_number; i >= 1; i--)
	{
		if (i % 4 == 0 && i!=pos_number && i != 0)
		{
			//检测前一个数是不是0
			if (str[back(pos_number) + 1] == '0')
				zero = 0;
			Print(table2[pos_index]);
			pos_index--;
		}
		if (str[back(i)] != '0')
		{
			if (zero == 0)//前面没有0 输出自己和自己的位数
			{
				Print(table[str[back(i)] - '0']);
				if (i != 0)
				{
					Print(table3[i % 4]);
				}
			}
			else//前面有0，输出一个0  然后再输出自己  有一种可能就是0已经摆阔在前面的80了 如10801080
			{
				Print(table[0]);
				Print(table[str[back(i)] - '0']);
				if (i != 0)
				{
					Print(table3[i % 4]);
				}
				zero = 0;
			}
		}
		else//当前为0  先不输出
		{
			zero = 1;
		}
	}
	return 0;
}

