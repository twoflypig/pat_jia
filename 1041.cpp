<<<<<<< HEAD
// 1041.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100001
int N;
int fx[MAX_N] = { 0 };
int flag = 0;
int main()
{
	cin >> N;
	vector<int >data(N);
	for (int i = 0; i <N; i++)
	{
		cin >> data[i];
		fx[data[i]]++;
	}
	for (int i = 0; i < N; i++)
	{
		if (fx[data[i]] == 1)
		{
			cout << data[i];
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "None";
	}
	//cin >> N;
    return 0;
}

=======
// 1041.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100001
int N;
int fx[MAX_N] = { 0 };
int flag = 0;
int main()
{
	cin >> N;
	vector<int >data(N);
	for (int i = 0; i <N; i++)
	{
		cin >> data[i];
		fx[data[i]]++;
	}
	for (int i = 0; i < N; i++)
	{
		if (fx[data[i]] == 1)
		{
			cout << data[i];
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "None";
	}
	//cin >> N;
    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
