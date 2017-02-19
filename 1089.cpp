// 1089.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N;
vector<int>orignal;
vector<int>result;
vector<int>workarry;
int temp; 
int move_flag = 0;
bool okflag = false;
bool compare(vector<int >&v1, vector<int> &v2)
{
	for (int i = 0; i < N; i++)
		if (v1[i] != v2[i])
			return false;
	return true;
}
void Print(vector<int>&v1)
{
	for (int i = 0; i < N; i++)
	{
		if (i)
			cout << " ";
		cout << v1[i];
	}
}

void mergesort(int start, int end)
{
	sort(workarry.begin() + start, workarry.begin() + end);
}
void merge(int start, int end)
{
	int middle = (start + end) / 2;
	int dt = pow(2,1);
	for (int i = 1; dt < N; i++)
	{
		dt = pow(2, i);
		start = 0;
		end = start + dt;
		while (end <= N)
		{
			mergesort(start, end);
			start = end;
			end = start + dt;
		}
		if(end>N && start<N)
			mergesort(start, N);
		if (okflag == false)
		{
			if (compare(workarry, result) == true)
				okflag = true;
		}
		else
		{
			cout << "Merge Sort" << endl;
			Print(workarry);
			break;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		orignal.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		result.push_back(temp);
	}
	//先插入排序
	workarry = orignal;
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (workarry[j] < workarry[j - 1])
			{
				swap(workarry[j], workarry[j - 1]);
				if(okflag ==true)
					move_flag = 1;
			
			}
			else
				break;
		}
		if (okflag == false)
		{
			if (compare(workarry, result) == true)
				okflag = true;
		}
		else
		{
			if (move_flag == 1)
			{
				cout << "Insertion Sort" << endl;
				Print(workarry);
				break;
			}
		}
	}
	//归并排序
	workarry = orignal;
	if (okflag == false)
	{
		merge(0, N-1);
	}

	cin >> N;
    return 0;
}

