// 1051.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int M, N,K;
list<int >fx;
bool failflag =false;
int k = 0;//processing
int main()
{
	cin >> M >> N >> K;
	vector<int >buffer(N);
	vector<int >standard(N);
	vector<int >output;
	cin.get();
	for (int i = 0; i < N; i++)
	{
		standard[i] = i + 1;
	}
	for (int i = 0; i < K; i++)
	{
	
		for (int j = 0; j < N; j++)
		{
			cin >> buffer[j];
		}

		for (int j = 0; j < N; j++)
		{
			//processing
			for (; k < N&&standard[k] <= buffer[j]; k++)
			{
				fx.push_back(standard[k]);
			}
			if (fx.size()<=M&&fx.empty() == false && fx.back() == buffer[j])
			{
					fx.pop_back();
			}
			else
			{
				failflag = true;
				break;
			}
		}
		failflag == true ? output.push_back(-1) : output.push_back(1);
		cin.get();
		//reset
		k = 0;
		failflag = false;
		fx.clear();
	}
	for (int i = 0; i < K; i++)
	{
		output[i] == 1? cout << "YES" << endl: cout << "NO" << endl;
	}

	cin >> N;
    return 0;
}

