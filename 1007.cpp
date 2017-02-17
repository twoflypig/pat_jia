//============================================================================
// Name        : 1007.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int temp=0;
	int sum = 0;
	int N ;
	int max =0;

	int finalstart = 0;
	int finalend = 0;
	int tempstart = 0;
	int tempend = 0;

	cin >>N;
	cin.get();

	int *input = new int[N];
	for(int i = 0 ;i<N ;i++)
	{
		cin >>input[i];
	}
	finalend = N-1;
	for(int i = 0;i<N;i++)
	{
	    temp = input[i];



	    if(sum >= 0)
	    {
	    	 sum+= temp;
	    	 tempend = i;
	    }
	    else
	    {
	    	 sum = 0;
	    	 sum+= temp;
	         tempstart = i;
	         tempend = i;

	    }

	    if(max <sum  || (sum == 0 && finalend == N-1))
	    {
	    	max = sum;
	    	finalend = tempend;
	    	finalstart = tempstart;
	    }

	}
	cout << max <<" "<<input[finalstart]<<" "<< input[finalend];

	return 0;
}
