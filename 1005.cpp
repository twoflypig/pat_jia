//============================================================================
// Name        : 1005.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string translate(char m)
{
    switch (m)
    {
    case '0': return "zero";
    case '1':return "one";
    case '2': return "two";
    case '3': return "three";
    case '4':return "four";
    case '5':return "five";
    case '6':return "six";
    case '7':return "seven";
    case '8':return "eight";
    case '9':return "nine";
    default: return "error";
    }
}

int main() {
	string data ;
	int sum =0;
	int length=0;
	stringstream ss;
	cin>>data;
	length = data.length();
	for(int i =0; i<length ; i++)
	{
		sum += (data[i] - '0');
	}

	ss << sum;
	ss >> data;
	string temp ;
	length = data.length();
	for(int i = 0 ;i <length ;i++)
	{
		if( i == 0 )
		  cout <<translate( data[i]) ;
		else
		{
		  cout<<" ";
		  cout<<translate( data[i]) ;
		}
	}

//	cout <<sum<<endl;
//	cout <<data.length()<<endl;
//	cout <<data<<endl;
	return 0;
}
