// 1097.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
//先顶一个一个结构体 key  adress  
//vector数组输入
//用map 完成对索引映射
int start_adress;
int start_index = 0;
int delete_index = -1;
int N;
typedef struct
{
	int address;
	int key; 
	int next_pos;
}NODE;
NODE buffer[100000];
int fx[100000]={0};
int fx_key[10000] = {-1};
void Print(int start)
{
	int j = start;
	while(1)
	{
		printf("%05d %d", buffer[j].address, buffer[j].key);
		//cout << setw(5) << setfill('0') << buffer[j].address << " " << buffer[j].key << " ";
		if (buffer[j].next_pos != -1)
		{
			printf(" %05d\n", buffer[j].next_pos);
			//cout << setw(5) << setfill('0') << buffer[j].next_pos << endl;
		}
		else
		{
			printf(" %d\n", buffer[j].next_pos);
			//cout << buffer[j].next_pos << endl;
		}
		if (buffer[j].next_pos != -1)
		{
			j = fx[buffer[j].next_pos];
		}
		else
		{
			break;
		}
	}
}
int main()
{
	NODE input;
	NODE next_node;
	int temp_abs = 0;

	cin >> start_adress >> N;
	cin.get();
	memset(fx_key, -1, sizeof(int) * 10000);
	memset(fx, -1, sizeof(int) * 100000);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &buffer[i].address, &buffer[i].key, &buffer[i].next_pos);
		getchar();
		//cin >> buffer[i].address >> buffer[i].key >> buffer[i].next_pos;
		//cin.get();
		if (buffer[i].address == start_adress)
		{
			start_index = i;
		}
		fx[buffer[i].address] = i;
	}

	if (buffer[start_index].next_pos != -1)
	{

		int last_posindex = start_index;
		int p2 = 0;//p1是正常的，p2是删除的
		int i = 0;
		fx_key[abs(buffer[start_index].key)] = start_index;
		i = fx[buffer[start_index].next_pos];
		while(1)
		{	
		
			if (fx_key[abs(buffer[i].key)] != -1)//找到了  需要删除
			{
				buffer[last_posindex].next_pos = buffer[i].next_pos;
				if (delete_index == -1)
				{
					delete_index = i;
				}
				else
				{
					buffer[p2].next_pos = buffer[i].address;
				
				}
				p2 = i;
			}
			else
			{
				fx_key[abs(buffer[i].key)] = i;
				last_posindex = i;	
			}
			if (buffer[i].next_pos == -1)
			{
				break;
			}
			else
			{
				i = fx[buffer[i].next_pos];
			}
		} 
		Print(start_index);
		buffer[p2].next_pos = -1;
		Print(delete_index);
	}
	else
	{
		Print(start_index);
	}

	cin >> input.address;
    return 0;
}

