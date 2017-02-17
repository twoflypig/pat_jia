<<<<<<< HEAD
// 1078.cpp : �������̨Ӧ�ó������ڵ㡣
//���������ϣ����
//�������λ��
//��ϣ����������Ϊ H��K�� = key %TSize, TSize�ǹ�ϣ�����󳤶ȣ�����̽Ѱ�����ڳ�ͻ
//��ĳߴ������������������Ĳ������������ñ�����һ�����С������
//MSize�Ǳ�ĳ���
//N�Ǹ���

//��� ��0��ʼ����������λ��

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
#define MAX 10000
int MSize, N;
int fx[MAX] = { 0 };

int H(int key,int TSize)
{
	return key%TSize;
}
bool CheckPrime(int value)
{
	int num = sqrt(value);
	if (value == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i <= num; i++)
		{
			if (value % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int FindPrime(int value)
{
	for (int i = value + 1; ; i++)
	{
		if (CheckPrime(i) == true)
		{
			return i;
		}
	}
}
int HashAdd(int pos)
{
	if (fx[pos] == 0)
	{
		fx[pos]++;
		return pos;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int input = 0;
	int buffer = 0;
	cin >> MSize >> N;
	
	if (CheckPrime(MSize) == false)
	{
		MSize = FindPrime(MSize);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		buffer = HashAdd(H(input, MSize));
		if (i)
		{
			cout << " ";
		}
		if ( buffer == -1)//û�ɹ�
		{
			int k = 1;

			while (k <= MSize / 2)
			{
				buffer = HashAdd(H(H(input, MSize) + k*k, MSize));
				if (buffer != -1)
				{
					cout << buffer;
					break;
				}
				else
				{
					k++;
				}
			}
			if (k > MSize / 2)
			{
				cout << "-";
			}

		}
		else
		{
			cout << buffer;
		}
	}

	cin >> input;
    return 0;
}

=======
// 1078.cpp : �������̨Ӧ�ó������ڵ㡣
//���������ϣ����
//�������λ��
//��ϣ����������Ϊ H��K�� = key %TSize, TSize�ǹ�ϣ�����󳤶ȣ�����̽Ѱ�����ڳ�ͻ
//��ĳߴ������������������Ĳ������������ñ�����һ�����С������
//MSize�Ǳ�ĳ���
//N�Ǹ���

//��� ��0��ʼ����������λ��

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
#define MAX 10000
int MSize, N;
int fx[MAX] = { 0 };

int H(int key,int TSize)
{
	return key%TSize;
}
bool CheckPrime(int value)
{
	int num = sqrt(value);
	if (value == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i <= num; i++)
		{
			if (value % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int FindPrime(int value)
{
	for (int i = value + 1; ; i++)
	{
		if (CheckPrime(i) == true)
		{
			return i;
		}
	}
}
int HashAdd(int pos)
{
	if (fx[pos] == 0)
	{
		fx[pos]++;
		return pos;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int input = 0;
	int buffer = 0;
	cin >> MSize >> N;
	
	if (CheckPrime(MSize) == false)
	{
		MSize = FindPrime(MSize);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		buffer = HashAdd(H(input, MSize));
		if (i)
		{
			cout << " ";
		}
		if ( buffer == -1)//û�ɹ�
		{
			int k = 1;

			while (k <= MSize / 2)
			{
				buffer = HashAdd(H(H(input, MSize) + k*k, MSize));
				if (buffer != -1)
				{
					cout << buffer;
					break;
				}
				else
				{
					k++;
				}
			}
			if (k > MSize / 2)
			{
				cout << "-";
			}

		}
		else
		{
			cout << buffer;
		}
	}

	cin >> input;
    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
