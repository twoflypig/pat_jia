// HighestPriceinSupplyChain.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <math.h>
//�൱��ͳ��������ȣ�������м���
//����BFS
//ʹ��һ����ά��������ʾ���׺���
int N;
float P;
float r;
queue <int>buffer;



int main()
{
	int input = 0;
	int aim_find;
	int end;
	int height=0;
	int length = 0;
	int store_length = 0;

	cin >> N >> P >> r;

	vector<vector<int >> martix(N);
	cin.get();
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (input == -1)
		{
			buffer.push(i);
		}
		else
		{
			martix[input].push_back(i);
		}
	} 
	end = buffer.back();

	while (buffer.empty() == false)
	{
		aim_find = buffer.front();
	
		for (vector<int>::iterator iter = martix[aim_find].begin(); iter != martix[aim_find].end(); iter++)
		{
			buffer.push(*iter);
			length++;
		}

		buffer.pop();	

		if (aim_find == end)
		{
			if (buffer.empty() == false)
			{
				end = buffer.back();
				store_length = length;
				length = 0;
				
			}
			
			height++;
		}
	
	}	

    cout <<fixed<< setprecision(2) << P*  pow(1+r*1.0/100,height-1) <<" "<<store_length << endl;

	cin >> input;

    return 0;
}
