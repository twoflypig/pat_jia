// 1062.cpp : 定义控制台应用程序的入口点。
//
//sage      talent  virtue   ：根据总分非增排序  超过H
//nobleman     -    virtue
//fool man     -       -
//small man talent     -
//N L H
//N为排序的总数 L要求所有的分数高于L才会被排
//给的形式为 ID_NUMBER  Virtue_grade  Talent_Grade
//若有总分相同根据美德分排序非增，如果还有，就以ID的增序排序
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L,H;

typedef struct
{
	int ID_Number;
	int Virtue_Grade;
	int Talent_Grade;
	int Total;
}STUDENT;
vector<STUDENT>Sage, nobleman, foolman, smallman;
STUDENT temp_in;
void Print(vector<STUDENT> &v1)
{
	for(vector<STUDENT>::iterator it= v1.begin();it!=v1.end();it++)
	{
		cout << it->ID_Number <<" "<< it->Virtue_Grade <<" "<< it->Talent_Grade << endl;
	}
}
bool compare(STUDENT v1, STUDENT v2)
{
	if (v1.Total != v2.Total)
		return  v1.Total > v2.Total;
	else if ( v1.Virtue_Grade != v2.Virtue_Grade)
		return v1.Virtue_Grade > v2.Virtue_Grade;
	else 
		return v1.ID_Number < v2.ID_Number;
}
int main()
{
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> temp_in.ID_Number >> temp_in.Virtue_Grade >> temp_in.Talent_Grade;
		if (temp_in.Virtue_Grade >= L && temp_in.Talent_Grade >= L)
		{
			temp_in.Total = temp_in.Talent_Grade + temp_in.Virtue_Grade;
			if (temp_in.Talent_Grade >= H && temp_in.Virtue_Grade >= H)
			{
				Sage.push_back(temp_in);
			}
			else if (temp_in.Talent_Grade < H && temp_in.Virtue_Grade >= H)
			{
				nobleman.push_back(temp_in);
			}
			else if (temp_in.Talent_Grade < H && temp_in.Virtue_Grade < H && temp_in.Talent_Grade<= temp_in.Virtue_Grade)
			{
				foolman.push_back(temp_in);
			}
			else
			{
				smallman.push_back(temp_in);
			}
		}
	}
	sort(Sage.begin(), Sage.end(), compare);
	sort(nobleman.begin(), nobleman.end(), compare);
	sort(foolman.begin(), foolman.end(), compare);
	sort(smallman.begin(), smallman.end(), compare);
	cout << Sage.size() + nobleman.size() + foolman.size() + smallman.size()<<endl;
	Print(Sage);
	Print(nobleman);
	Print(foolman);
	Print(smallman);

	cin >> N;
	
}
