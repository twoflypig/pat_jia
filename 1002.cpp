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
	int exdata =0;//��ʱ��Ŵ���
	float codata =0;//��ʱ���ϵ��
    int n2 =0;
    int final_count =0;//���ն������
    char flag =0;//�Ӹտ�ͷ��������ʼ
    float sum[1001]={0};//0~1000
	//��һ����������
    cin >> n1;

	for(int i=0;i<n1;i++)
	{
		cin >> exdata>>codata;
		sum[exdata] += codata;
	}
	cin.get();
    //�ڶ�����������
    cin >> n2;
	for(int i=0;i<n2;i++)
	{
		cin >> exdata>>codata;
		sum[exdata] += codata;
	}

    //�ж�����
	for(int i=0;i<1001;i++)
	{
		if( (int(sum[i]*10))/10 !=0 )
		{
			final_count++;
		}
	}

	//���
    cout <<final_count;
	for(int i=1000;i>=0;i--)
	{
		if(  (int(sum[i]*10))/10 !=0)
		{
			cout<<" " <<(i)<<" "<<setprecision(1) << setiosflags(ios::fixed) <<sum[i];
		}

	}
}
