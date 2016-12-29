//============================================================================
// Name        : 1002.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//Sample Input
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
//Sample Output
//3 2 1.5 1 2.9 0 3.2
//============================================================================

#include <iostream>
using namespace std;
#include <iomanip>
int main() {

	int n1 =0;
	int exdata =0;//临时存放次数
	float codata =0;//临时存放系数
    int n2 =0;
    int final_count =0;//最终二项次数
    char flag =0;//从刚开头非零数开始
    float sum[1001]={0};//0~1000
	//第一个数的输入
    cin >> n1;

	for(int i=0;i<n1;i++)
	{
		cin >> exdata>>codata;
		sum[exdata] += codata;
	}
	cin.get();
    //第二个数的输入
    cin >> n2;
	for(int i=0;i<n2;i++)
	{
		cin >> exdata>>codata;
		sum[exdata] += codata;
	}

    //判断总数
	for(int i=0;i<1001;i++)
	{
		if( (int(sum[i]*10))/10 !=0 )
		{
			final_count++;
		}
	}

	//输出
    cout <<final_count;
	for(int i=1000;i>=0;i--)
	{
		if(  (int(sum[i]*10))/10 !=0)
		{
			cout<<" " <<(i)<<" "<<setprecision(1) << setiosflags(ios::fixed) <<sum[i];
		}

	}
}
