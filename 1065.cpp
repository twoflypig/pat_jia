// 1065.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
long double  A, B,C;
int N;
vector<long double > inA,inB,inC;
int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		inA.push_back(A);
		inB.push_back(B);
		inC.push_back(C);
		cin.get();
	}
	for (int i = 0; i < N; i++)
	{
		cout << "Case #" << i+1 << ": ";
		if (inA[i] + inB[i] > inC[i])
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	cin >> N;
    return 0;
}

