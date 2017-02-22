// 1020.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct tree
{
	int value;
	tree *left;
	tree *right;
}NODE;
int N;
vector<int>postder;
vector<int>inorder;

//˼· �����һ���Ǹ��ڵ�
//
NODE * newNode(int value)
{
	NODE * temnode = new NODE;
	temnode->left = temnode->right = NULL;
	temnode->value = value;
	return temnode;
}
NODE * buildtree(NODE * &root,int postL,int postR,int low, int high)
{
	//��������
	//�ĸ�ָ��  2������
	if (high < 0 || low > high || postL >postR)
	{
		return NULL;
	}
	int middle;
	if (root == NULL)
		root = newNode(0);
	root->value = postder[postR];
	for (int i = low; i <= high; i++)//�������в��Һ����е����һ����
	{
		if (inorder[i] == root->value)
		{
			middle = i;
			break;
		}
	}
	int length =  middle - low;
	root->left = buildtree(root->left, postL ,postL+length -1  ,low, middle - 1);
	root->right = buildtree(root->right, postL + length, postR-1 , middle + 1, high);
	return root;
}
void levelorder(NODE * root)
{
	int count = 0;
	NODE *temp = NULL;
	queue< NODE* >qu;
	qu.push(root);
	while (qu.empty() == false)
	{
		temp = qu.front();
		qu.pop();
		if (count)
			cout << " ";
		count++;
		cout << temp->value;
		if (temp->left != NULL)
			qu.push(temp->left);
		if (temp->right != NULL)
			qu.push(temp->right);
	}
	cout << endl;
}
int main()
{
	NODE *root=NULL;
	cin >> N;
	postder.resize(N);
	inorder.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> postder[i];//���� 
	}
	for (int i = 0; i < N; i++)
	{
		cin >> inorder[i];//����
	}
	//
	root = buildtree(root,0,N-1, 0, N - 1);
	levelorder(root);
    return 0;
}

