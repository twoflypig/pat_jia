// 1082.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//˼· ÿ��4��������
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
	//���ҵ�һ��������������һ������Ȼ�����������Ƿ�ȫ��
	for (int i = pos_number; i >= 1; i--)
	{
		if (i % 4 == 0 && i!=pos_number && i != 0)
		{
			//���ǰһ�����ǲ���0
			if (str[back(pos_number) + 1] == '0')
				zero = 0;
			Print(table2[pos_index]);
			pos_index--;
		}
		if (str[back(i)] != '0')
		{
			if (zero == 0)//ǰ��û��0 ����Լ����Լ���λ��
			{
				Print(table[str[back(i)] - '0']);
				if (i != 0)
				{
					Print(table3[i % 4]);
				}
			}
			else//ǰ����0�����һ��0  Ȼ��������Լ�  ��һ�ֿ��ܾ���0�Ѿ�������ǰ���80�� ��10801080
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
		else//��ǰΪ0  �Ȳ����
		{
			zero = 1;
		}
	}
	return 0;
}

