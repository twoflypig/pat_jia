// 1071.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<string, int>fx;
vector<int >table;
vector<string>output;
int index = 0;
int max_occ = 1;//at least is one
bool check(char &in)
{
	if (in <= 'z' && in >= 'a')
	{
		return true;
	}
	else if (in <= 'Z' && in >= 'A')
	{
		in = in - 'A' + 'a';
		return true;
	}
	else if (in >= '0'&& in <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	char c;
	string buffer;
	while ( (c = getchar()) != '\n')
	{
			if (check(c) == true)
			{
				buffer.append(1, c);
			}
			else 
			{
				if (buffer.empty() == false)
				{
					//����map��
					map<string, int>::iterator it = fx.find(buffer);
					if (it != fx.end())//�ҵ���
					{
						table[it->second]++;
						if (max_occ < table[it->second])
						{
							max_occ = table[it->second];
						}
					}
					else//û�ҵ�  ���� sitrng-index
					{
						fx.insert(pair<string, int>(buffer, index++));
						table.push_back(1);
					}
					buffer.clear();
				}
			}
	}
	for (map<string, int>::iterator it = fx.begin(); it != fx.end(); it++)
	{
		if (table[it->second] == max_occ)
		{
			output.push_back(it->first);
		}
	}
	sort(output.begin(), output.end());

	cout << output[0] << " " << max_occ;

	cin >> index;
    return 0;
}

