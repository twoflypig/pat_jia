// 1058.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
typedef struct
{
	int a;
	int b;
	int c;
}NODE;
NODE fx[2];
using namespace std;
int main()
{
	scanf("%d.%d.%d %d.%d.%d", &fx[0].a, &fx[0].b, &fx[0].c, &fx[1].a, &fx[1].b, &fx[1].c);
	fx[0].c += fx[1].c;
	if (fx[0].c >= 29)
	{
		fx[0].c -= 29;
		fx[0].b++;
	}
	fx[0].b += fx[1].b;
	if (fx[0].b >= 17)
	{
		fx[0].b -= 17;
		fx[0].a++;
	
	}
	fx[0].a += fx[1].a;
	cout << fx[0].a <<"."<< fx[0].b <<"."<< fx[0].c << endl;

	cin >> fx[0].a;
    return 0;
}

