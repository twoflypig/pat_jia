//============================================================================
// Name        : 1006.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct
{
     string id;
     string sign_in_time;
     string sign_out_time;
}id_infor;
//1:means str1 < str2
bool  firstcompare(string str1,string str2)
{
	int length = str1.length();
   for(int i =0; i <length;i++)
   {
	   if(str1[i] < str2[i])
	   {
		   return  true;
	   }
	   else if(str1[i] > str2[i])
	   {
		   return false;
	   }
	   else
	   {

	   }

   }
   return true;
}
//1:means str1 > str2
bool  lastcompare(string str1,string str2)
{
	int length = str1.length();
   for(int i =0; i <length;i++)
   {
	   if(str1[i] > str2[i])
	   {
		   return  true;
	   }
	   else if(str1[i] < str2[i])
	   {
		   return false;
	   }
	   else
	   {

	   }

   }
   return true;
}
int main() {

	int M ;
	id_infor first,last,temp;
	cin >> M;

	for(int i = 0 ; i<M ;i++)
	{
		cin >> temp.id>>temp.sign_in_time>>temp.sign_out_time;
		cin.get();// throw off /n
		if(i == 0 )
		{
            first.id =last.id = temp.id;;
            first.sign_in_time = last.sign_in_time = temp.sign_in_time;
            first.sign_out_time = last.sign_out_time = temp.sign_out_time;
		}
		else
		{
			//check first
			if( firstcompare(first.sign_in_time,temp.sign_in_time)== false)
			{
	            first.id = temp.id;;
	            first.sign_in_time  = temp.sign_in_time;
	            first.sign_out_time  = temp.sign_out_time;
			}
			if(lastcompare(last.sign_out_time,temp.sign_out_time)== false)
			{
		          last.id = temp.id;;
		          last.sign_in_time = temp.sign_in_time;
		          last.sign_out_time = temp.sign_out_time;

			}

		}


	}

	cout << first.id << " "<<last.id;


	return 0;
}
