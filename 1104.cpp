// 1104.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N;
vector<double>arry;
double  temp = 0;
double sum = 0;
long long fact(int fa1, int fa2)
{
	return  (long long)fa1*fa2;
}
int main()
{
	cin >> N;
	arry.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		arry.push_back(temp);
	}
	//����0 ΪN
	for (int i =1; i <= N; i++)
	{
		sum += fact((N-i+1),i)* arry[i];
	}
	printf("%.2f", sum);
    return 0;
}

