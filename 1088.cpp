// 1088.cpp : 定义控制台应用程序的入口点。
//
//long int 
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int  K = 0;
typedef struct
{
	long long  upper;
	long long  downer;
}NODE;
NODE buff[2];
int  gcd(int a, int b)
{
	if (b == 0)return a;
	else return gcd(b, a%b);
}
void Init(NODE &v)
{

	if (v.downer < 0)
	{
		v.downer = -v.downer;
		v.upper = -v.upper;
	}
	if (v.upper == 0)
	{
		v.downer = 1;
	}
	else
	{
		int prime = gcd(abs(v.upper), abs(v.downer));
		v.upper /= prime;
		v.downer /= prime;
	}
}
NODE sum(NODE v1, NODE v2)
{
	NODE temp;
	temp.upper = v1.upper*v2.downer + v1.downer*v2.upper;
	temp.downer = v1.downer*v2.downer;
	Init(temp);
	return temp;
}
NODE differ(NODE v1, NODE v2)
{
	NODE temp;
	temp.upper = v1.upper*v2.downer - v1.downer*v2.upper;
	temp.downer = v1.downer*v2.downer;
	Init(temp);
	return temp;
}
NODE prodect(NODE v1, NODE v2)
{
	NODE temp;
	temp.upper = v1.upper*v2.upper;
	temp.downer = v1.downer*v2.downer;
	Init(temp);
	return temp;
}
NODE quotient(NODE v1, NODE v2)
{
	NODE temp;
	temp.upper = v1.upper*v2.downer;
	temp.downer = v1.downer*v2.upper;
	Init(temp);
	return temp;
}
void Print(NODE v1)
{
	int flag = 0;
	if (v1.downer == 0)
	{
		cout << "Inf";
		return;
	}
	if (v1.upper == 0)
	{
		cout << "0";
		return;
	}
	else if (v1.upper < 0)
	{
		flag = 1;
		cout << "(";
	}
	if (v1.downer == 1)
		cout << v1.upper;
	else if(abs(v1.upper) <v1.downer)
	{
		cout << v1.upper << "/" << v1.downer;
	}
	else
	{
			cout << v1.upper / v1.downer << " ";
			cout << abs(v1.upper%v1.downer) << "/" << v1.downer;
	}
	if (flag)
		cout << ")";
	
}
int main()
{
	NODE temp;
	scanf("%lld/%lld %lld/%lld", &buff[0].upper, &buff[0].downer, &buff[1].upper, &buff[1].downer);
	Init(buff[0]);
	Init(buff[1]);


	temp = sum(buff[0], buff[1]);
	Print(buff[0]);
	cout << " + ";
	Print(buff[1]);
	cout << " = ";
	Print(temp);
	cout << endl;

	temp = differ(buff[0], buff[1]);
	Print(buff[0]);
	cout << " - ";
	Print(buff[1]);
	cout << " = ";
	Print(temp);
	cout << endl;

	temp = prodect(buff[0], buff[1]);
	Print(buff[0]);
	cout << " * ";
	Print(buff[1]);
	cout << " = ";
	Print(temp);
	cout << endl;

	temp = quotient(buff[0], buff[1]);
	Print(buff[0]);
	cout << " / ";
	Print(buff[1]);
	cout << " = ";
	Print(temp);


	cin >> K;
    return 0;
}

