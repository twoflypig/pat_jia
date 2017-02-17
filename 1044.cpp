<<<<<<< HEAD
// 1044.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vector>
int N;
int M;
vector<int >Min_i;
vector<int >Min_j;
int Min=65535;
//树状数组
int main()
{
	cin >> N >> M;
	cin.get();
	vector<int >fx(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i];
	}
	int i = 0, j = 0;
	int sum = fx[0];
	int flag = 0;
	while (i <= N &&j<=N)
	{
		if (sum <M)
		{
			j++;
			sum += fx[j];
		}
		else if (sum > M)
		{
			sum -= fx[i];
			i++;

			if (sum < Min)
			{
				Min = sum;
				Min_i.clear();
				Min_j.clear();
				Min_i .push_back(i);
				Min_j .push_back(j);
			}
			else if (sum == Min)
			{
				Min_i.push_back(i);
				Min_j.push_back(j);
			}
		}

		if(sum == M)
		{
			printf("%d-%d\n", i+1, j+1);
			sum -= fx[i];
			i++;
			flag = 1;
		}

	}
	if (flag == 0)
	{
		for (int i = 0; i < Min_i.size(); i++)
		{
			printf("%d-%d\n", Min_i[ i] + 1, Min_j[j] + 1);
		}
	}
	cin >> N;
    return 0;
}

=======
// 1044.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vector>
int N;
int M;
vector<int >Min_i;
vector<int >Min_j;
int Min=65535;
//树状数组
int main()
{
	cin >> N >> M;
	cin.get();
	vector<int >fx(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i];
	}
	int i = 0, j = 0;
	int sum = fx[0];
	int flag = 0;
	while (i <= N &&j<=N)
	{
		if (sum <M)
		{
			j++;
			sum += fx[j];
		}
		else if (sum > M)
		{
			sum -= fx[i];
			i++;

			if (sum < Min)
			{
				Min = sum;
				Min_i.clear();
				Min_j.clear();
				Min_i .push_back(i);
				Min_j .push_back(j);
			}
			else if (sum == Min)
			{
				Min_i.push_back(i);
				Min_j.push_back(j);
			}
		}

		if(sum == M)
		{
			printf("%d-%d\n", i+1, j+1);
			sum -= fx[i];
			i++;
			flag = 1;
		}

	}
	if (flag == 0)
	{
		for (int i = 0; i < Min_i.size(); i++)
		{
			printf("%d-%d\n", Min_i[ i] + 1, Min_j[j] + 1);
		}
	}
	cin >> N;
    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
