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
	int lasttemp = 0;
	int sum = 0;
	int N ;
	int max =0;

	int negtive = 0;
	int pstart = 0;
	int pend = 0;
	int maxpstart = 0;
	cin >>N;
	cin.get();

	for(int i = 0;i<N;i++)
	{
		lasttemp = temp;
	    cin >>temp;


	    if(temp < 0 && sum <=0 )
	    {
	         pstart = i ;
	    }
	    else if(lasttemp!= 0 && temp == 0 && sum <=0)
	    {
	    	 pstart =  i;
	    }
	    else if(temp >0 && sum <=0)
	    {
	    	 pstart = i ;
	    }

	    if(temp < 0)
	    {
	    	negtive++;
	    }

	    sum += temp;


	    if(sum <0)
	    {
	    	 sum = 0;
	    }


		if(max < sum )
		{
			max = sum;
			maxpstart = pstart;
			pend = i;
		}
		else if(max == sum && lasttemp !=0&&temp == 0 && pend == 0 )//add
		{
			maxpstart = pstart;
			pend =i;
		}
	}
	if(N  == negtive && N !=0)
	{
		cout <<max<<" "<< 0<<" "<<(N-1)<<endl;
	}
	else
	{
		 cout <<max<<" "<< maxpstart<<" "<<pend<<endl;
	}

	return 0;
}
