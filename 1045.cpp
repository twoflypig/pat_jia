<<<<<<< HEAD
// 1045.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int N;
int L;
int M;
int max(int value1, int value2)
{
	if (value1 < value2)
		return value2;

	return value1;
}
int main()
{
	cin >> N;
	cin.get();

	
	cin >> M;
	vector <int >favorite(M + 1);
	for (int i = 1; i <=M; i++)
	{
		cin >> favorite[i];
	}
	cin.get();

	cin >> L;
	vector<int> strip(L+1);
	vector<vector<int> >fx(M + 1);
	for (int i = 1; i <= L; i++)
	{
		cin >> strip[i];
	}
	fx[0].resize(L + 1);
	for (int i = 1; i <= M; i++)
	{
		fx[i].resize(L + 1);
		for (int j = 1; j <= L; j++)
		{
			if (favorite[i ] == strip[j])
			{
				fx[i][j] = fx[i][j - 1]+1;
			}
			else
			{
				fx[i][j] = max(fx[i - 1][j], fx[i][j - 1]);
			}
		}
	}
	cout << fx[M][L];
	
	cin >> N;
    return 0;
}

=======
// 1045.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int N;
int L;
int M;
int max(int value1, int value2)
{
	if (value1 < value2)
		return value2;

	return value1;
}
int main()
{
	cin >> N;
	cin.get();

	
	cin >> M;
	vector <int >favorite(M + 1);
	for (int i = 1; i <=M; i++)
	{
		cin >> favorite[i];
	}
	cin.get();

	cin >> L;
	vector<int> strip(L+1);
	vector<vector<int> >fx(M + 1);
	for (int i = 1; i <= L; i++)
	{
		cin >> strip[i];
	}
	fx[0].resize(L + 1);
	for (int i = 1; i <= M; i++)
	{
		fx[i].resize(L + 1);
		for (int j = 1; j <= L; j++)
		{
			if (favorite[i ] == strip[j])
			{
				fx[i][j] = fx[i][j - 1]+1;
			}
			else
			{
				fx[i][j] = max(fx[i - 1][j], fx[i][j - 1]);
			}
		}
	}
	cout << fx[M][L];
	
	cin >> N;
    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
