//============================================================================
// Name        : 1008.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define up_time  6
#define down_time 4
#define stop_time 5
int main() {

	int N ;
	int temp = 0;
	int lastfloor = 0;
	int sub = 0;
	int onlynumber = 0;
	int sum = 0;
	cin >>N ;

	int floor[100]={0};

	for(int i = 0 ;i<N ;i++)
	{
		cin >> temp;

	   floor[i] = temp ;

	}

	for(int i =0 ;i<N;i++)
	{
		 sub = floor[i] - lastfloor;

		 if(sub >0)
	     {
	    	sum += up_time * sub;
	     }
	     else
	     {
	    	 sum += down_time *(-sub);
	     }

	     lastfloor = floor[i];
	}
	sum +=  N * stop_time;

	cout << sum;

	return 0;
}
