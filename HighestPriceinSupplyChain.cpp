// HighestPriceinSupplyChain.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <math.h>
//相当于统计树的深度，最深的有几条
//采用BFS
//
int N;
float P;
float r;
vector<int>chain;
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
	cin.get();
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		chain.push_back(input);
		if (input == -1)
		{
			buffer.push(i);//store the root
		}
	} 
	end = buffer.back();
	while (buffer.empty() == false)
	{
		aim_find = buffer.front();
	
		
		for (int i = 0; i < N; i++)
		{
			if (chain[i] == aim_find)
			{
				buffer.push(i);
				length++;
			}
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

