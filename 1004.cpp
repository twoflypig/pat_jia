//============================================================================
// Name        : 1004.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//firstly ,we should collect the ways we want to get
//============================================================================

#include <iostream>
#include <malloc.h>
#include <queue>
using namespace std;

//

typedef struct Node
{
     int number ;
     struct Node * pnextnode;
}NODE;
typedef struct Head
{
	NODE * pnext;
}Head;
int Add_list(Head & phead,int data)
{
	//ͷ�巨
	NODE * p2 = (NODE*)malloc(sizeof(NODE));
	if(p2 ==NULL)
	{
		cout <<"memory failed"<<endl;
		return 0;
	}

    p2->number = data;
    p2->pnextnode = phead.pnext;
    phead.pnext = p2;
    return  0;
}
void Print_list(Head & phead)
{
	NODE* p1 = phead.pnext;
	if(p1 != NULL)
	{
		while(p1!=NULL)
		{
			cout << p1->number<<" ";
			p1=p1->pnextnode;
		}
	}
	else
	{

		cout << "-1"<<endl;
	}

}
int main() {
	//step1  �����ܽڵ����ͷ�Ҷ�ڵ�����
	//step2 ����ÿ����ҳ�ڵ㣬���ζ���ڵ��� ���� ���ӵĽڵ���
	//step3���쵥����
	//step4���ö���
	int N,M ;
	//step1
	cin >> N>>M;
	Head node[N];

	//��ʼ��
    for (int i =0 ;i <N ;i++)
    {
    	node[i].pnext = NULL ;
    }
    //step2
    for (int i =0 ;i <M ;i++)
    {
          int id;
          int length;
          int id_data;
          cin >> id>>length;

          for(int j = 0; j  < length ;j++)
          {
        	  cin >> id_data;

        	  Add_list(node[id-1],id_data);//���ڵ���Ϊ1
          }
          cin.get();//ȥ���س���
    }

    //setp4  ���ö��п��Ƿ���ÿ���Ҷ�ӽڵ���  Ĭ�� ���1�Ǹ��ڵ�
    queue <int >q1;
    NODE * p1;
    int pend;//ָ��ÿ������һ���ڵ�
    int ptemp;
    int count = 0 ;
    int outflag =0;//������
    //���ڵ����ӽڵ�
	if (node[0].pnext != NULL)
	{
		q1.push(1);//�Ѹ��ڵ�ѹ����Ϊ��ͷ
		pend = q1.back();
		while (q1.empty() == false) {
			ptemp = q1.front();	//ȡ�ýڵ���
			q1.pop();

			//���ýڵ�ǿյ�ʱ�� �Ѻ���ȫ�ӽ���
			p1 = node[ptemp - 1].pnext;
			if (p1 == NULL) {
				//��ǰҶ�ڵ�����1
				count++;
			} else {
				while (p1 != NULL) {
					q1.push(p1->number);
					p1 = p1->pnextnode;
				}

			}
			//���½�β������һ��
			if (ptemp == pend) {
				pend = q1.back();
				if(outflag == 0 )
				{
					cout << count;
					outflag++;
				}
				else
				{
					cout <<" "<< count;
				}

				count = 0;
			}

		}
	}
	else
	{
		cout << "1";
	}
    //������¶Բ���
//	cout <<"now start"<<endl;
//    for(int i =0;i<N ;i++)
//    {
//    	Print_list(node[i]);
//    }

	return 0;
}
