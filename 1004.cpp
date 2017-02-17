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
	//头插法
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
	//step1  读入总节点数和非叶节点总数
	//step2 对于每个非页节点，依次读入节点编号 总数 孩子的节点数
	//step3构造单链表
	//step4运用队列
	int N,M ;
	//step1
	cin >> N>>M;
	Head node[N];

	//初始化
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

        	  Add_list(node[id-1],id_data);//根节点编号为1
          }
          cin.get();//去掉回车符
    }

    //setp4  运用队列看是否数每层的叶子节点数  默认 编号1是根节点
    queue <int >q1;
    NODE * p1;
    int pend;//指向每层的最后一个节点
    int ptemp;
    int count = 0 ;
    int outflag =0;//标记输出
    //根节点有子节点
	if (node[0].pnext != NULL)
	{
		q1.push(1);//把根节点压入作为开头
		pend = q1.back();
		while (q1.empty() == false) {
			ptemp = q1.front();	//取得节点编号
			q1.pop();

			//当该节点非空的时候 把孩子全加进来
			p1 = node[ptemp - 1].pnext;
			if (p1 == NULL) {
				//当前叶节点数加1
				count++;
			} else {
				while (p1 != NULL) {
					q1.push(p1->number);
					p1 = p1->pnextnode;
				}

			}
			//更新结尾，计数一层
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
    //输出看下对不对
//	cout <<"now start"<<endl;
//    for(int i =0;i<N ;i++)
//    {
//    	Print_list(node[i]);
//    }

	return 0;
}
