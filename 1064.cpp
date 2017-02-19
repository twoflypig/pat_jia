// 1064.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int i_count = 0;
int number_count = 0;
void middle_visit(vector<int>& local,vector<int >&data,int pos,int &count)
{
	if (pos <= N)
	{
		middle_visit(local, data, 2 * pos,count);//left
		local[pos] = data[count++];
		middle_visit(local, data, 2 * pos+1,count);//left
	}
}
int main()
{
	cin >> N;
	cin.get();
	vector<int >fx(N+1);
	vector<int >buffer(N);
	for (int i = 0; i < N; i++)
	{
		cin >> buffer[i];
	}
	sort(buffer.begin(), buffer.end());
	middle_visit(fx, buffer, 1, i_count);
	for (vector<int>::iterator it = fx.begin() + 1; it != fx.end(); it++)
	{
		if (number_count)
			cout << " ";
		cout << *it;
		number_count++;
	}
	cin >> N;

    return 0;
}

