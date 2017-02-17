<<<<<<< HEAD
// 1098.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#define MAX 100
using namespace std;
//�ȼ���������
//�ټ�������
int data2[MAX];
int several_result[MAX];
int heat[MAX];
int insert[MAX];
int N;
void swap(int & value, int &value2)
{
	int temp = value;
	value = value2;
	value2 = temp;
}
bool compare(int(&arry1)[MAX], int(&arry2)[MAX])
{
	for (int i = 0; i < N; i++)
	{
		if (arry1[i] != arry2[i])
		{
			return false;
		}
	}
	return  true;
}
void Print(int(&arry)[MAX])
{
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			cout << arry[0];
		}
		else
		{
			cout << " " << arry[i];
		}

	}
}
//�����Ļ� �Ǵ�ĩ�˿�ʼ��ǰ������
void maxTreeAdjust(int(&arry)[MAX],int father,int length)//�����
{
	int child = 2*father+1;
	while (child <length)
	{
		if (child + 1 < length &&  arry[child] < arry[child + 1])
		{
			child++;
		}
		if (arry[father] < arry[child])
		{
			swap(arry[father], arry[child]);
		}
		else
		{
			break;
		}
		father = child;
		child = 2 * father + 1;
	}
}
int main()
{

	int temp;
	int flag = 0;
	cin >> N;
	cin.get();

	for (int i = 0; i <N; i++)
	{
		cin >> data2[i];
		heat[i] = data2[i];
		insert[i] = data2[i];
	}
	cin.get();

	for (int i = 0; i <N; i++)
	{
		cin >> several_result[i];
	}
	//��������
	for (int i = 1; i < N; i++)
	{
		if (compare(insert, several_result) == true)
		{
			cout << "Insertion Sort" << endl;
		    flag = 1;
		}
		for (int j = i; j >= 1; j--)
		{
			if (insert[j] < insert[j - 1])
			{
				swap(insert[j], insert[j - 1]);
			}
			else
			{
				break;
			}
		}
		if (flag == 1)
		{
			Print(insert);
			break;
		}
	}
	if (flag == 0)//�Ƕ�����
	{
		cout << "Heap Sort" << endl;
		//�ҵ��ұ��Ѿ��ź����λ��
		int right_pos = N - 1;
		for (; right_pos >= 0; right_pos--)
		{
			if (insert[right_pos] != several_result[right_pos])
			{
				break;
			}
		}
		//�ҵ��󣬿�ʼ��������������
		//����ǰ�ȵ�һ��
		for (int j = right_pos; j >= 0; j--)
		{
			maxTreeAdjust(several_result,j, right_pos+1);
		}
		swap(several_result[0], several_result[right_pos]);
		for (int j = right_pos - 1; j >= 0; j--)
		{
			maxTreeAdjust(several_result,j, right_pos);
		}
		Print(several_result);
	}
	cin >> temp;
    return 0;
}

=======
// 1098.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#define MAX 100
using namespace std;
//�ȼ���������
//�ټ�������
int data2[MAX];
int several_result[MAX];
int heat[MAX];
int insert[MAX];
int N;
void swap(int & value, int &value2)
{
	int temp = value;
	value = value2;
	value2 = temp;
}
bool compare(int(&arry1)[MAX], int(&arry2)[MAX])
{
	for (int i = 0; i < N; i++)
	{
		if (arry1[i] != arry2[i])
		{
			return false;
		}
	}
	return  true;
}
void Print(int(&arry)[MAX])
{
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			cout << arry[0];
		}
		else
		{
			cout << " " << arry[i];
		}

	}
}
//�����Ļ� �Ǵ�ĩ�˿�ʼ��ǰ������
void maxTreeAdjust(int(&arry)[MAX],int father,int length)//�����
{
	int child = 2*father+1;
	while (child <length)
	{
		if (child + 1 < length &&  arry[child] < arry[child + 1])
		{
			child++;
		}
		if (arry[father] < arry[child])
		{
			swap(arry[father], arry[child]);
		}
		else
		{
			break;
		}
		father = child;
		child = 2 * father + 1;
	}
}
int main()
{

	int temp;
	int flag = 0;
	cin >> N;
	cin.get();

	for (int i = 0; i <N; i++)
	{
		cin >> data2[i];
		heat[i] = data2[i];
		insert[i] = data2[i];
	}
	cin.get();

	for (int i = 0; i <N; i++)
	{
		cin >> several_result[i];
	}
	//��������
	for (int i = 1; i < N; i++)
	{
		if (compare(insert, several_result) == true)
		{
			cout << "Insertion Sort" << endl;
		    flag = 1;
		}
		for (int j = i; j >= 1; j--)
		{
			if (insert[j] < insert[j - 1])
			{
				swap(insert[j], insert[j - 1]);
			}
			else
			{
				break;
			}
		}
		if (flag == 1)
		{
			Print(insert);
			break;
		}
	}
	if (flag == 0)//�Ƕ�����
	{
		cout << "Heap Sort" << endl;
		//�ҵ��ұ��Ѿ��ź����λ��
		int right_pos = N - 1;
		for (; right_pos >= 0; right_pos--)
		{
			if (insert[right_pos] != several_result[right_pos])
			{
				break;
			}
		}
		//�ҵ��󣬿�ʼ��������������
		//����ǰ�ȵ�һ��
		for (int j = right_pos; j >= 0; j--)
		{
			maxTreeAdjust(several_result,j, right_pos+1);
		}
		swap(several_result[0], several_result[right_pos]);
		for (int j = right_pos - 1; j >= 0; j--)
		{
			maxTreeAdjust(several_result,j, right_pos);
		}
		Print(several_result);
	}
	cin >> temp;
    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
