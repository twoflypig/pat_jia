<<<<<<< HEAD
// 1060.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
typedef struct
{
	string f;
	int pos_start;
	int pos_dou;
	int k;
	vector<int> sidata;
}NODE;
NODE fx[2];
int find_not_zero(string &temp)
{
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] != '0' && temp[i] != '.')
		{
			return i;
		}
	}
	return temp.size();
}
void func(NODE & node)
{
	node.pos_dou = node.f.find('.');
	node.pos_start = find_not_zero(node.f);
	if (node.pos_start == node.f.size())//0  0.00
	{
		for (int i = 0; i < N; i++)
		{
			node.sidata.push_back(0);
		}
		node.k = 0;
	}
	else//不是零  0.001 1.000 123 
	{
		if (node.pos_dou == -1)//123
		{
			for (int i = 0; i < N; i++)
			{
				if (i + node.pos_start < node.f.size())
				{
					node.sidata.push_back(node.f[i+ node.pos_start] - '0');
				}
				else
				{
					node.sidata.push_back(0);
				}
			}
			node.k = node.f.size() - node.pos_start;
		}
		else// 0.001 1.0
		{
			//确定非0位置的次数
			if (node.pos_dou > node.pos_start)//10.00
			{
				node.k = node.pos_dou;
			}
			else //0.001
			{
				node.k = node.pos_dou - node.pos_start +1;
			}
			int cout = 0;//跳过.
			for (int i = 0; i < N; )
			{
				int temp = node.pos_start;

				if (i + temp + cout < node.f.size())
				{
					if (node.f[i + temp + cout] != '.')
					{
						node.sidata.push_back(node.f[i + temp + cout] - '0');
						i++;
					}
					else
					{
						cout++;
					}
				}
				else
				{
					node.sidata.push_back(0);
					i++;
				}

			}

		}

	}
}
bool compare(NODE & node1, NODE &node2)
{
	if (node1.sidata.size() == node2.sidata.size() && node1.k == node2.k)
	{
		for (int i = 0; i < node1.sidata.size(); i++)
		{
			if (node1.sidata[i] != node2.sidata[i])
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
void Printf(NODE & node)
{
	cout << "0.";
	for (int i = 0; i < node.sidata.size(); i++)
	{
		cout << node.sidata[i];
	}
	cout << "*10^";
	cout << node.k;
}
int main()
{
	cin >> N>>fx[0].f>>fx[1].f;

	func(fx[0]);
	func(fx[1]);
	if (compare(fx[0], fx[1]) == true)
	{
		cout << "YES ";
		Printf(fx[0]);
	}
	else
	{
		cout << "NO ";
		Printf(fx[0]);
		cout << " ";
		Printf(fx[1]);
	}
	cin >> N;



    return 0;
}

=======
// 1060.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
typedef struct
{
	string f;
	int pos_start;
	int pos_dou;
	int k;
	vector<int> sidata;
}NODE;
NODE fx[2];
int find_not_zero(string &temp)
{
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] != '0' && temp[i] != '.')
		{
			return i;
		}
	}
	return temp.size();
}
void func(NODE & node)
{
	node.pos_dou = node.f.find('.');
	node.pos_start = find_not_zero(node.f);
	if (node.pos_start == node.f.size())//0  0.00
	{
		for (int i = 0; i < N; i++)
		{
			node.sidata.push_back(0);
		}
		node.k = 0;
	}
	else//不是零  0.001 1.000 123 
	{
		if (node.pos_dou == -1)//123
		{
			for (int i = 0; i < N; i++)
			{
				if (i + node.pos_start < node.f.size())
				{
					node.sidata.push_back(node.f[i+ node.pos_start] - '0');
				}
				else
				{
					node.sidata.push_back(0);
				}
			}
			node.k = node.f.size() - node.pos_start;
		}
		else// 0.001 1.0
		{
			//确定非0位置的次数
			if (node.pos_dou > node.pos_start)//10.00
			{
				node.k = node.pos_dou;
			}
			else //0.001
			{
				node.k = node.pos_dou - node.pos_start +1;
			}
			int cout = 0;//跳过.
			for (int i = 0; i < N; )
			{
				int temp = node.pos_start;

				if (i + temp + cout < node.f.size())
				{
					if (node.f[i + temp + cout] != '.')
					{
						node.sidata.push_back(node.f[i + temp + cout] - '0');
						i++;
					}
					else
					{
						cout++;
					}
				}
				else
				{
					node.sidata.push_back(0);
					i++;
				}

			}

		}

	}
}
bool compare(NODE & node1, NODE &node2)
{
	if (node1.sidata.size() == node2.sidata.size() && node1.k == node2.k)
	{
		for (int i = 0; i < node1.sidata.size(); i++)
		{
			if (node1.sidata[i] != node2.sidata[i])
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
void Printf(NODE & node)
{
	cout << "0.";
	for (int i = 0; i < node.sidata.size(); i++)
	{
		cout << node.sidata[i];
	}
	cout << "*10^";
	cout << node.k;
}
int main()
{
	cin >> N>>fx[0].f>>fx[1].f;

	func(fx[0]);
	func(fx[1]);
	if (compare(fx[0], fx[1]) == true)
	{
		cout << "YES ";
		Printf(fx[0]);
	}
	else
	{
		cout << "NO ";
		Printf(fx[0]);
		cout << " ";
		Printf(fx[1]);
	}
	cin >> N;



    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
