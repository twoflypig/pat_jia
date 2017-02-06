// 1043.cpp : 定义控制台应用程序的入口点。
//指针要再看看 又忘了！

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int>fx;
typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
}NODE,*PNODE;
bool compare(int a,int b)
{
	if (a < b)
	{
		return true;
	}
	else//a>=b
	{
		return false;
	}
}
bool compareMirron(int a, int b)
{
	if (a >= b)
	{
		return true;
	}
	else//a<b
	{
		return false;
	}
}
void CheckTree(PNODE &pnode,int low, int high,int &cout,bool (*com)(int a,int b))
{
	if (low > high)
		return;
	int middle;
	int flag = 0;
	pnode = new NODE();
	pnode->value= fx[low];
	pnode->left = pnode->right = NULL;
	cout++;
	if (low == high)
		return;
	for (middle = low + 1; middle <= high;	middle++)
	{
		if (com(fx[middle], fx[low]) == false)//a>=b
		{
			break;
		}
	}
	if (middle > high)//说明为单个孩子只有左孩子
	{
		CheckTree(pnode->left, low + 1, high, cout, com);
	}
	else
	{
		for (int i = middle + 1; i <= high; i++)
		{
			if (com(fx[i], fx[low]) == true)//a<b
			{
				return;
			}
		}
		CheckTree(pnode->left, low + 1, middle - 1, cout, com);
		CheckTree(pnode->right, middle, high, cout, com);
	}
}
void post_dfs(PNODE &pnode)
{
	static int count = 0;
	if (pnode)
	{
		post_dfs(pnode->left);
		post_dfs(pnode->right);
		
		if (count == 0)
		{
			count++;
		}
		else
		{
			cout << " ";
		}
		cout << pnode->value;
	}
}
int main()
{
	int temp;
	int cout1 =0 ;
	int cout2 =0 ;
	NODE *root = NULL;
	NODE *root2 = NULL;
	cin >> N;
	cin.get();

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		fx.push_back(temp);
	}
	CheckTree(root, 0, fx.size()-1, cout1, compare);
	CheckTree(root2, 0, fx.size() - 1, cout2, compareMirron);
	if (cout1 == N)
	{
		cout << "YES" << endl;
		post_dfs(root);
	}
	else if (cout2 == N)
	{
		cout << "YES" << endl;
		post_dfs(root2);
	}
	else
	{
		cout << "NO";
	}
	//cout << "point:" << cout1 << endl;
	//post_dfs(root);
	cin >> N;
    return 0;
}

