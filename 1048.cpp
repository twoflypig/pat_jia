// 1048.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
int N,M;
vector<int >arry;
int main()
{
	int temp = 0;
	int low = 0;
	int high = 0;
	cin >> N >> M;
	cin.get();
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arry.push_back(temp);
	}
	sort(arry.begin(), arry.begin()+N);
	
	high = N - 1;
	low = 0;
	while (low < high)
	{
		if (arry[low] + arry[high] > M)
		{
			high--;
		}
		else if (arry[low] + arry[high] < M)
		{
			low++;
		}
		else
		{
			cout << arry[low] << " " << arry[high];
			break;
		}
	}
	if (low >= high)
	{
		cout << "No Solution";
	}
	cin >> N;

    return 0;
}

