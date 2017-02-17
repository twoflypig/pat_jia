//============================================================================
// Name        : 1001.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int a ,b;
    int c= 0;
    int flag  =0;
    int i=0;

    stack <int> first;
	cin>>a>>b;

	c= a+b;//a+b;

	if(c<0) // 下面处理都是以正数开始
	{
		cout << "-";
		c =-c;
	}

	for( i=0;i<10;i++) //把每一个数变为个位
	{
		first.push(c%10);
		c=c/10;
	}


	for(i=0;i<10;i++)
	{
		a =first.top();

		if(a != 0 && flag ==0 )//搜索高位第一个不为零的数
		{
			flag =1;

		}

		if(flag ==1)  //搜索到后开始输出
		{
			std::cout <<a  ;

			if(i%3 ==0 && i!=0 && i!=9)
			{
				std::cout << "," ;
			}
		}


		first.pop();
	}

	if (flag ==0)//结果为0的话直接输出一个0
	{
		cout << "0";

	}


	return 0;
}
