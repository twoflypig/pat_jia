// 1093.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int >P;
vector<int >A;
vector<int >T;
vector<int>::iterator it;
string in;
int local_a;
int P_count, T_count;
int sum = 0;
int high, middle,low;
int Fx(vector<int> const &v1,int v2)
{
	if (v1.size() == 1)
	{
		if (v1[0] <v2 )
			return 1;
		else return 0;
	}
	else if (v1.size() == 0)
	{
		return 0;
	}
	else
	{
		low = 0;
		high = v1.size() - 1;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (v1[middle] < local_a)
			{
				low = middle + 1;
			}
			else if (v1[middle] > local_a)
			{
				high = middle - 1;
			}
			else
			{
				break;
			}
		}
		if (v1[middle] < local_a)
			return middle + 1;
		else
			return middle;
	}
}
int main()
{
	cin >> in;
	for (int i = 0; i < in.size(); i++)
	{
		switch (in[i])
		{
		case 'P':
		{
			P.push_back(i);
			break;
		}
		case 'A':
		{
			A.push_back(i);
			break;
		}
		case 'T':
		{
			T.push_back(i);
			break;
		}
		default:break;

		}
	}
	for (int i = 0; i < A.size(); i++)
	{
		local_a = A[i];

		P_count = Fx(P, local_a);

		T_count = T.size() - Fx(T, local_a); ;

		sum = (sum+(T_count*P_count)) % 1000000007;
	}
	cout << sum;

	cin >> sum;
	
    return 0;
}

