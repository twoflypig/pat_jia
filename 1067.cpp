// 1067.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int N;
int number = 0;
void swap(int &v1, int &v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

int main()
{
	int base, find;
	cin >> N;
	vector<int>fx(N);
	vector<int>pos_index(N);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i];
		pos_index[fx[i]] = i;
	}

	while (1)
	{
		base = pos_index[0];//0��Ӧ��λ��
		find = pos_index[base];//0��Ӧ��λ�õı�������λ��
		if (base != find)
		{
			swap(pos_index[fx[base]], pos_index[fx[find]]);//����ӳ���
			swap(fx[base], fx[find]);//��������
		}
		else
		{
			//�ҵ�һ��û�ж������
			int i = 1;
			for (;i<N&&pos_index[i] == i ; i++) ;
			if (i == N) break;
			swap(fx[base], fx[pos_index[i]]);//��������
			swap(pos_index[0], pos_index[i]);//����ӳ���

		}
		number++;
	}

	cout << number;


	cin >> N;
    return 0;
}

