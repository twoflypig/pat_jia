<<<<<<< HEAD
// 1080.cpp : �������̨Ӧ�ó������ڵ㡣
//
// (���Գɼ�+ ���Գɼ�) /2
//�������ĳɼ�����
//���ɼ���ͬ�Ļ������ݱ��Գɼ�����һ���Ļ�����ͬ����
//ÿ����������K��ѡ��
//�������� ��ѡ���Ⱥ�ѡ��ѧУ�������ܾ��Ļ�����������߹ҵ�
//��ͬ�������������߶�����ͬһѧУ�������¼ȡ

//N�����п���   M�������о���ѧУ  K(һ�����м���ѡ��
//��i��ѧУ������
//Ge  Gi K��ѧУ

//��� ÿ��ѧУ�����ѧ�����
//��ѧ�������Ϊ0
//˼·
#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#define MAX_SCHOOL 100
#define MAX_CHOICE 5
#define MAX_APPLICATIORS 40000
using namespace std;
int num_applicator = 0;
int num_school = 0;
int K = 0;
int arrySchools[MAX_SCHOOL];
int arryApplicators[MAX_APPLICATIORS];
int Allrank = 0;
vector<list<int>> request(MAX_SCHOOL);
list<int >Need;
typedef struct
{
	float G;//�ܷ�
	int Ge;
	int Gi;
	int Choice[MAX_CHOICE];
	int rank;
	int number;//�Լ��ı��
}NODE;
NODE student[MAX_APPLICATIORS];
void swap(NODE & node1, NODE &node2)
{
	NODE temp;
	temp = node1;
	node1 = node2;
	node2 = temp;
}
int main()
{
	int temp_choice;
	cin >> num_applicator >> num_school >> K;
	cin.get();
	for (int i = 0; i < num_school; i++)
	{
		cin >> arrySchools[i];
	}
	cin.get();

	
	for (int i = 0; i < num_applicator; i++)
	{
		//����ÿ��ѧ��
		cin >> student[i].Ge >> student[i].Gi;
		for (int j = 0; j < K; j++)
		{
			cin >> student[i].Choice[j];
		}
		cin.get();
		student[i].number = i;
		student[i].G = (student[i].Ge + student[i].Gi)*1.0 / 2;
		//�������� ������ǰ
		for (int j = i - 1; j >= 0; j--)
		{
			if (student[j].G < student[j + 1].G)
			{
				swap(student[j], student[j + 1]);
				
			}
			else if (student[j].G == student[j+1].G)
			{
				if (student[j].Ge < student[j + 1].Ge)
				{
					swap(student[j], student[j + 1]);
				}
				//�����ڵĻ���ͬ����
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 0; i < num_applicator; i++)
	{
		if (i < num_applicator - 1)
		{
			if (student[i].G != student[i + 1].G)
			{
				student[i].rank = Allrank++;
			}
			else if (student[i].Ge != student[i + 1].Ge)
			{
				student[i].rank = Allrank++;
			}
			else
			{
				student[i].rank = Allrank;
			}
		}
		else
		{
			if (student[i].G != student[i - 1].G)
			{
				student[i].rank = Allrank++;
			}
			else if (student[i].Ge != student[i - 1].Ge)
			{
				student[i].rank = Allrank++;
			}
			else
			{
				student[i].rank = Allrank;
			}
		}
	}

	//����
	
	for (int ran = 0,i=0; ran < Allrank; ran++)//rank
	{
		for (  ; student[i].rank == ran;i++ )//i in same rank
		{
			for (int j = 0; j < K; j++)
			{
				temp_choice = student[i].Choice[j];
				if (arrySchools[temp_choice] >0)
				{
					request[temp_choice].push_back(student[i].number);
					Need.push_back(temp_choice);
					break;
				}
			}
		}
		//gengxin
		while (Need.empty() == false)
		{
			temp_choice = Need.back();
			Need.pop_back();
			arrySchools[temp_choice]--;
		}
		
	}
	for (int i = 0; i < num_school; i++)
	{

		request[i].sort();
		for (int j= 0;request[i].empty() == false ; j++)
		{
			if (j)
				cout << " ";
			cout << request[i].front();
			request[i].pop_front();
		}
		cout << endl;

	}

	//for (int i = 0; i < num_applicator; i++)
	//{
	//	cout <<"G:" <<student[i].G<<" Ge"<<student[i].Ge <<" Gi:"<<student[i].Gi<<" Rank:"<<student[i].rank<< endl;
	//}
	cin >> K;

    return 0;
}

=======
// 1080.cpp : �������̨Ӧ�ó������ڵ㡣
//
// (���Գɼ�+ ���Գɼ�) /2
//�������ĳɼ�����
//���ɼ���ͬ�Ļ������ݱ��Գɼ�����һ���Ļ�����ͬ����
//ÿ����������K��ѡ��
//�������� ��ѡ���Ⱥ�ѡ��ѧУ�������ܾ��Ļ�����������߹ҵ�
//��ͬ�������������߶�����ͬһѧУ�������¼ȡ

//N�����п���   M�������о���ѧУ  K(һ�����м���ѡ��
//��i��ѧУ������
//Ge  Gi K��ѧУ

//��� ÿ��ѧУ�����ѧ�����
//��ѧ�������Ϊ0
//˼·
#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#define MAX_SCHOOL 100
#define MAX_CHOICE 5
#define MAX_APPLICATIORS 40000
using namespace std;
int num_applicator = 0;
int num_school = 0;
int K = 0;
int arrySchools[MAX_SCHOOL];
int arryApplicators[MAX_APPLICATIORS];
int Allrank = 0;
vector<list<int>> request(MAX_SCHOOL);
list<int >Need;
typedef struct
{
	float G;//�ܷ�
	int Ge;
	int Gi;
	int Choice[MAX_CHOICE];
	int rank;
	int number;//�Լ��ı��
}NODE;
NODE student[MAX_APPLICATIORS];
void swap(NODE & node1, NODE &node2)
{
	NODE temp;
	temp = node1;
	node1 = node2;
	node2 = temp;
}
int main()
{
	int temp_choice;
	cin >> num_applicator >> num_school >> K;
	cin.get();
	for (int i = 0; i < num_school; i++)
	{
		cin >> arrySchools[i];
	}
	cin.get();

	
	for (int i = 0; i < num_applicator; i++)
	{
		//����ÿ��ѧ��
		cin >> student[i].Ge >> student[i].Gi;
		for (int j = 0; j < K; j++)
		{
			cin >> student[i].Choice[j];
		}
		cin.get();
		student[i].number = i;
		student[i].G = (student[i].Ge + student[i].Gi)*1.0 / 2;
		//�������� ������ǰ
		for (int j = i - 1; j >= 0; j--)
		{
			if (student[j].G < student[j + 1].G)
			{
				swap(student[j], student[j + 1]);
				
			}
			else if (student[j].G == student[j+1].G)
			{
				if (student[j].Ge < student[j + 1].Ge)
				{
					swap(student[j], student[j + 1]);
				}
				//�����ڵĻ���ͬ����
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 0; i < num_applicator; i++)
	{
		if (i < num_applicator - 1)
		{
			if (student[i].G != student[i + 1].G)
			{
				student[i].rank = Allrank++;
			}
			else if (student[i].Ge != student[i + 1].Ge)
			{
				student[i].rank = Allrank++;
			}
			else
			{
				student[i].rank = Allrank;
			}
		}
		else
		{
			if (student[i].G != student[i - 1].G)
			{
				student[i].rank = Allrank++;
			}
			else if (student[i].Ge != student[i - 1].Ge)
			{
				student[i].rank = Allrank++;
			}
			else
			{
				student[i].rank = Allrank;
			}
		}
	}

	//����
	
	for (int ran = 0,i=0; ran < Allrank; ran++)//rank
	{
		for (  ; student[i].rank == ran;i++ )//i in same rank
		{
			for (int j = 0; j < K; j++)
			{
				temp_choice = student[i].Choice[j];
				if (arrySchools[temp_choice] >0)
				{
					request[temp_choice].push_back(student[i].number);
					Need.push_back(temp_choice);
					break;
				}
			}
		}
		//gengxin
		while (Need.empty() == false)
		{
			temp_choice = Need.back();
			Need.pop_back();
			arrySchools[temp_choice]--;
		}
		
	}
	for (int i = 0; i < num_school; i++)
	{

		request[i].sort();
		for (int j= 0;request[i].empty() == false ; j++)
		{
			if (j)
				cout << " ";
			cout << request[i].front();
			request[i].pop_front();
		}
		cout << endl;

	}

	//for (int i = 0; i < num_applicator; i++)
	//{
	//	cout <<"G:" <<student[i].G<<" Ge"<<student[i].Ge <<" Gi:"<<student[i].Gi<<" Rank:"<<student[i].rank<< endl;
	//}
	cin >> K;

    return 0;
}

>>>>>>> 614bff6c67fa29ab0353f26a5240b55b03a63311
