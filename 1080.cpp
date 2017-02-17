<<<<<<< HEAD
// 1080.cpp : 定义控制台应用程序的入口点。
//
// (面试成绩+ 笔试成绩) /2
//根据最后的成绩排名
//最后成绩相同的话，根据笔试成绩，还一样的话，相同排名
//每个申请者有K个选择
//根据排名 按选择先后选择学校，都被拒绝的话，这个申请者挂掉
//相同排名，若申请者都申请同一学校，则均被录取

//N（所有考生   M（所有研究生学校  K(一个人有几个选择
//第i个学校的名额
//Ge  Gi K个学校

//输出 每个学校收入的学生结果
//无学生招入就为0
//思路
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
	float G;//总分
	int Ge;
	int Gi;
	int Choice[MAX_CHOICE];
	int rank;
	int number;//自己的编号
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
		//接收每个学生
		cin >> student[i].Ge >> student[i].Gi;
		for (int j = 0; j < K; j++)
		{
			cin >> student[i].Choice[j];
		}
		cin.get();
		student[i].number = i;
		student[i].G = (student[i].Ge + student[i].Gi)*1.0 / 2;
		//差入排序 大数在前
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
				//还等于的话相同排名
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

	//排名
	
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
// 1080.cpp : 定义控制台应用程序的入口点。
//
// (面试成绩+ 笔试成绩) /2
//根据最后的成绩排名
//最后成绩相同的话，根据笔试成绩，还一样的话，相同排名
//每个申请者有K个选择
//根据排名 按选择先后选择学校，都被拒绝的话，这个申请者挂掉
//相同排名，若申请者都申请同一学校，则均被录取

//N（所有考生   M（所有研究生学校  K(一个人有几个选择
//第i个学校的名额
//Ge  Gi K个学校

//输出 每个学校收入的学生结果
//无学生招入就为0
//思路
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
	float G;//总分
	int Ge;
	int Gi;
	int Choice[MAX_CHOICE];
	int rank;
	int number;//自己的编号
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
		//接收每个学生
		cin >> student[i].Ge >> student[i].Gi;
		for (int j = 0; j < K; j++)
		{
			cin >> student[i].Choice[j];
		}
		cin.get();
		student[i].number = i;
		student[i].G = (student[i].Ge + student[i].Gi)*1.0 / 2;
		//差入排序 大数在前
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
				//还等于的话相同排名
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

	//排名
	
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
