// 1059.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef struct
{
	int pi;
	int k;
}NODE;
vector<NODE>buffer;
bool CheckPrime(int value)
{
	int num = sqrt(value);
	if (value >= 2)
	{
		for (int i = 2; i <= num; i++)
		{
			if (value % i == 0)
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}
int main()
{
	int input;
	int in_buffer;
	NODE tempNode;
	cin >> input;
	in_buffer = input;
	if (input >= 2)
	{
		int middle = sqrt(input)+1;
		for (int i = 2; i <= middle; i++)
		{
			if (CheckPrime(i) == true)
			{
				tempNode.pi = i;
				tempNode.k = 0;
				while (input%i == 0)
				{
					tempNode.k++;
					input /= i;
				}
				if (tempNode.k > 0)
				{
					buffer.push_back(tempNode);
				}
			}
			if (CheckPrime(input) == true)
			{
				if (buffer.size() > 0)
				{
					if (input < buffer.back().pi)
					{
						for (int j = 0; j < buffer.size(); j++)
						{
							if (buffer[j].pi == input)
							{
								buffer[j].k++;
							}
						}
					}
					else
					{
						tempNode.pi = input;
						tempNode.k = 1;
						buffer.push_back(tempNode);
					}
				}
				else
				{
					tempNode.pi = input;
					tempNode.k = 1;
					buffer.push_back(tempNode);
				}
				break;
			}
			if (input == 1)
			{
				break;
			}
		}
	}
	else
	{
		tempNode.pi = input;
		tempNode.k = 1;
		buffer.push_back(tempNode);
	}
	cout << in_buffer << "=";
	for (int i = 0; i < buffer.size(); i++)
	{
		if (i)
		{
			cout << "*" << buffer[i].pi;
			if (buffer[i].k>=2)
			{
				cout << "^" << buffer[i].k;
			}
		}
		else
		{
			cout << buffer[i].pi;
			if (buffer[i].k >= 2)
			{
				cout << "^" << buffer[i].k;
			}
		}
	}
	cin >> input;
    return 0;
}

