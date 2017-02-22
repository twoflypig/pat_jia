// 1123.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
int  comflag = 0;
typedef struct node
{
	int value;
	int height;
	struct node * left;
	struct node * right;
}NODE;
queue<NODE* >levelorder;
NODE *temnode;
void updateHeight(NODE *root);

int GetHeight(NODE *root)
{
	if (root == NULL)	 return 0;
	else
		return root->height;
}
int getBalanceFactor(NODE *root)
{
	return GetHeight(root->left) - GetHeight(root->right);
}
void L(NODE * &root)
{
	NODE *temnode = root->right;
	root->right = temnode->left;
	temnode->left = root;
	updateHeight(root);
	updateHeight(temnode);
	root = temnode;//�ؼ���һ����Ҫ��rootŪ����
}
void R(NODE * &root)
{
	NODE *temnode = root->left;
	root->left = temnode->right;
	temnode->right = root;
	updateHeight(root);
	updateHeight(temnode);
	
	root = temnode;//�ؼ���һ����Ҫ��rootŪ����
}
void updateHeight(NODE *root)
{
	if (root != NULL)
		root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
}
NODE * createnode(int value)
{
	    NODE *p;
		p = new NODE;
		p->value = value;
		p->left= p->right = NULL;
		p->height = 1;
		return p;
}
void inserttree(NODE * &p, int value)
{
	if (p == NULL)
	{
		p = createnode(value);
		return;
	}
	if (value <=p->value )
	{
		inserttree(p->left, value);
		updateHeight(p);
		if (getBalanceFactor(p) == 2)
		{
			if (getBalanceFactor(p->left) == 1)
			{
				R(p);
			}
			else if (getBalanceFactor(p->left) == -1)
			{
				L(p->left);
				R(p);
				
			}
		}
	}
	else
	{
		inserttree(p->right, value);
		updateHeight(p);
		if (getBalanceFactor(p) == -2)
		{
			if (getBalanceFactor(p->right) == -1)
			{
				L(p);
			}
			else if (getBalanceFactor(p->right) == 1)
			{
				R(p->right);
				L(p);
				
			}
		}
	}
}
bool check(NODE *root)
{
	int totalnumber=0;
	comflag = 0;

	levelorder.push(root);
	while (levelorder.empty() == false)
	{
		temnode = levelorder.front();
		levelorder.pop();

		if (temnode == NULL)//�սڵ�Ͳ���Ϊ
		{
			if (comflag == 0)//��һ�μ�⵽�ո�
			{
				if (totalnumber == N)
				{
					comflag = 2;
					return true;
				}
				else
				{
					comflag = 1;//��⵽�ո�ʱ�㻹û��
				}
			}

		}
		else//�ǿսڵ� ���� 
		{
			
			if (totalnumber)
				cout << " ";
			totalnumber++;
			cout << temnode->value;
			levelorder.push(temnode->left);
			levelorder.push(temnode->right);
		}

	}
	if (comflag == 1 || comflag == 0)
		return false;
}

int main()
{
	NODE *proot =NULL;
	int temint;	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temint;
		inserttree(proot, temint);//���ﲻ���� &root��ԭ����  &root��һ��������ַ
	}
	if (check(proot) == true)
	{
		cout <<endl<< "YES" << endl;
	}
	else
	{
		cout << endl << "NO" << endl;
	}

    return 0;
}

