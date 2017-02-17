<<<<<<< HEAD
// 1068.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int M;
int flag = 0;
bool compare(int v, int v2)
{
	return v < v2;
}
int main()
{
	cin >> N>>M;
	cin.get();

	vector<int >fx(N);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i];
	}
	sort(fx.begin(), fx.end(), compare);
	vector<vector<bool>> table(N+1);
	for (int i = 0; i <= N; i++)
	{
		table[i].resize(M + 1);
		for (int j = 0; j <= M; j++)
		{
			table[i][j] = false;
		}
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == N - 1 && j== 0)
			{
					table[N - 1][0] = true;
			}
			else
			{
				if (j - fx[i] >= 0)
				{
					table[i][j] = table[i + 1][j] || table[i + 1][j - fx[i]];
				}
				else
				{
					table[i][j] = table[i + 1][j] ;
				}
				
			}
		}
	}
	int m = M;
	int number = 0;
	for (int i =0; i <N && m>0; i++)
	{
		if (m - fx[i] >= 0)
		{
			if (N == 1)
			{
				if (m - fx[i] == 0)
				{
					cout << fx[i];
					flag = 1;
				}
			}
			else if (table[i+1][m -fx[i]] == true)
			{
				
				if (number)
					cout << " ";
				cout << fx[i];
				number++;
				m -= fx[i];
				flag = 1;
			}
		}
	}
	if (flag == 0)
	{
		cout << "No Solution";
	}
	//cout << endl;
	//for (int i = 0; i < N; i++)
	//{
	//	cout << fx[i] << " ";
	//	for (int j = 0; j <= M; j++)
	//	{
	//		cout << table[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cin >> N;
    return 0;
}

=======
// 1068.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int M;
int flag = 0;
bool compare(int v, int v2)
{
	return v < v2;
}
int main()
{
	cin >> N>>M;
	cin.get();

	vector<int >fx(N);
	for (int i = 0; i < N; i++)
	{
		cin >> fx[i];
	}
	sort(fx.begin(), fx.end(), compare);
	vector<vector<bool>> table(N+1);
	for (int i = 0; i <= N; i++)
	{
		table[i].resize(M + 1);
		for (int j = 0; j <= M; j++)
		{
			table[i][j] = false;
		}
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == N - 1 && j== 0)
			{
					table[N - 1][0] = true;
			}
			else
			{
				if (j - fx[i] >= 0)
				{
					table[i][j] = table[i + 1][j] || table[i + 1][j - fx[i]];
				}
				else
				{
					table[i][j] = table[i + 1][j] ;
				}
				
			}
		}
	}
	int m = M;
	int number = 0;
	for (int i =0; i <N && m>0; i++)
	{
		if (m - fx[i] >= 0)
		{
			if (N == 1)
			{
				if (m - fx[i] == 0)
				{
					cout << fx[i];
					flag = 1;
				}
			}
			else if (table[i+1][m -fx[i]] == true)
			{
				
				if (number)
					cout << " ";
				cout << fx[i];
				number++;
				m -= fx[i];
				flag = 1;
			}
		}
	}
	if (flag == 0)
	{
		cout << "No Solution";
	}
	//cout << endl;
	//for (int i = 0; i < N; i++)
	//{
	//	cout << fx[i] << " ";
	//	for (int j = 0; j <= M; j++)
	//	{
	//		cout << table[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cin >> N;
    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
