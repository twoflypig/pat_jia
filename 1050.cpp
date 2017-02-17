// 1050.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
int table[400] = {0};
string s1;
string s2;
char c;
int main()
{
	while ((c = getchar()) != '\n')
	{
		s1.append(1, c);
	}
	while ((c = getchar()) != '\n')
	{
		s2.append(1, c);
	}
	for (int i = 0; i < s2.size(); i++)
	{
			table[s2[i]]++;
	}
	int j = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (table[s1[i]] == 0)
		{
			s1[j] = s1[i];
			cout << s1[j];
			j++;
		}
	}

	cin >> s1;
    return 0;
}

