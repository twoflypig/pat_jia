// 1077.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string > sent(500);
int N;
string ::iterator rootp,cmpp;
int minsize = 99999;
int flag = 0;
int number = 0;
string outstr;
int main()
{
	cin >> N;
	cin.get();
	for (int i = 0; i < N; i++)
	{
		getline(cin,sent[i]);
		if (sent[i].size() < minsize)
			minsize = sent[i].size();
	}
	for (int i = 1; i <= minsize; i++)
	{
		rootp = sent[0].end() - i;
		for (int j = 0; j < N; j++)
		{
			cmpp = sent[j].end() - i;
			if (*cmpp != *rootp)
			{
				flag = 1;//至少1个
				break;
			}
		}
		if (flag)
			break;
		number++;
		
	}
	outstr = sent[0].substr(sent[0].size() - number, number);
		if (outstr.empty() == true)
		{
			cout << "nai";
		}
		else
		{
			cout << outstr;
		}

	cin >> N;

    return 0;
}

