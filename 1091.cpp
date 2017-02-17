// 1091.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>

#define CHECKED 1
#define NOTCHECKED 0
using namespace std;
int N, M, L, T;
typedef struct
{
	int x;
	int y;
	int z;
}POINT;
void fixed(vector<vector<vector<int >>> & map, POINT & point)
{
	map[point.x][point.y][point.z] = 0;
}
void make_point(POINT  &point,int x, int y, int z)
{
	point.x = x;
	point.y = y;
	point.z = z;
}
int main()
{
	int temp_input;
	cin >> N >> M >> L >> T;

	vector<vector<vector<int >>> data(L);
	vector<POINT >point;
	queue<POINT> buffer;
	POINT temp_point,temp_point2;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < L; i++)
	{
		data[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			data[i][j].resize(M);
			for (int k = 0; k < M; k++)
			{
				cin >> temp_input;
				data[i][j][k]= (temp_input);
				if (temp_input == 1)
				{
					temp_point.x = i;
					temp_point.y = j;
					temp_point.z = k;

					point.push_back(temp_point);
				}
			}
			cin.get();
		}
	}
	if (point.size() == 0)
	{
		cout << 0;
	}
	else
	{
		
		for (int i = 0; i < point.size(); i++)
		{
			if (data[point[i].x][point[i].y][point[i].z] == 1)
			{
				buffer.push(point[i]);
				fixed(data, point[i]);
				count =1 ;
				//等一个点的bfs完成
				while (buffer.empty() == false)
				{
					temp_point = buffer.front();
					buffer.pop();
					//check 6 directions
					if (temp_point.x + 1 <L && data[temp_point.x + 1][temp_point.y][temp_point.z] == 1)
					{
						make_point(temp_point2, temp_point.x + 1, temp_point.y, temp_point.z);
						buffer.push(temp_point2);
						fixed(data, temp_point2);
						count++;
					}
					if (temp_point.y + 1 <N&&data[temp_point.x][temp_point.y + 1][temp_point.z] == 1)
					{
						make_point(temp_point2, temp_point.x , temp_point.y+1, temp_point.z);
						buffer.push(temp_point2);
						fixed(data, temp_point2);
						count++;
					}
					if (temp_point.z + 1 <M && data[temp_point.x][temp_point.y ][temp_point.z+1] == 1)
					{
						make_point(temp_point2, temp_point.x, temp_point.y, temp_point.z+1);
						buffer.push(temp_point2);
						fixed(data, temp_point2);
						count++;
					}
					if (temp_point.x - 1 >=0 && data[temp_point.x-1][temp_point.y][temp_point.z ] == 1)
					{
						make_point(temp_point2, temp_point.x - 1, temp_point.y, temp_point.z);
						buffer.push(temp_point2);
						fixed(data, temp_point2);
						count++;
					}
					if (temp_point.y - 1 >=0 && data[temp_point.x ][temp_point.y-1][temp_point.z] == 1)
					{
						make_point(temp_point2, temp_point.x , temp_point.y-1, temp_point.z);
						buffer.push(temp_point2);
						fixed(data, temp_point2);
						count++;
					}
					if (temp_point.z - 1 >= 0 && data[temp_point.x][temp_point.y ][temp_point.z-1] == 1)
					{
						make_point(temp_point2, temp_point.x, temp_point.y, temp_point.z -1);
						buffer.push(temp_point2);
						fixed(data, temp_point2);
						count++;
					}
				}
				if (count >= T)
				{
					sum += count;
				}
			}
		}
		cout << sum;
	}
	cout << endl;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cout << data[i][j][k] << " ";
			}
			cout << endl;
		}
	}
	

	cin >> temp_input;
    return 0;
}

