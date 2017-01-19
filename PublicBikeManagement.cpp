//============================================================================
// Name        : PublicBikeManagement.cpp
// Author      : hxj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

//Ê¹ÓÃÁÚ½Ó¾ØÕó´æ´¢ÎÞÏòÍ¼
//
//Ò»¸ö¶¥µãÊÇ    ¾àÀë
//´´½¨Ò»¸öÊý×é£ºÃ¿¸ö¶¥µãµÄ×ÔÐÐ³µÊý
#define INFINATE 65535
int main() {

	int CMax;// Ò»¸öÕ¾×ÔÐÐ³µµÄ×ÜÊý
	int N;//Õ¾µÄ×ÜÊý
	int Sp;//ÓÐÎÊÌâµÄ³µÕ¾
	int M ;//³µµÀÊý
    
    //get global information;
	cin >>CMax>>N>>Sp>>M;
	cin.get();
    
    //get bikes
	int station_dis[N+1][N+1]={0};//´ÓiÕ¾µ½jÕ¾µÄ¾àÀë
	int station_bikes[N+1];//Ã¿¸öÕ¾µÄ×ÔÐÐ³µ×ÜÊý
	for(int i = 1 ;i<=N;i++)
	{
        cin>>station_bikes[i];
	}
	cin.get();
	for(int i=0 ;i<N+1;i++)
	{
		for(int j = 0;j <N+1;j++)
		{
			station_dis[i][j] = INFINATE;
		}
	}

    //get  roads information
    int temp_i,temp_j;
	for(int i =1;i<=M;i++)
	{
         cin>> temp_i>>temp_j;
         cin >>station_dis[temp_i][temp_j];
         cin.get();
	}
    
    //begin distrka  from o -> Sp
    int final[N+1] ={0};
    int dis[N+1];//value
    int P[N+1];//road
    int min;
    int k = 0;
    for(int i = 0 ;i<N+1;i++)
    {
    	final[i] = 0;
    	dis[i] = station_dis[0][i];
    	P[i] =-1;
    } 
    
    dis[0] = 0;
    final[0]=1;

	for(int i =1;i<N+1;i++)
	{
          min = INFINATE;
          for(int w =0 ;w<N+1;w++)
          {
          		if( final[w]== 0  && dis[w] <= min)
          		{
          			 k =  w;
          			 min = dis[w];
          		}
          }

          final[k] =1;

          for(int w = 1 ;w<N+1 ;w++)
          {
          		if(!final[w] && (dis[w] >  (dis[k] + station_dis[k][w])))
          		{
          			dis[w] =  dis[k] + station_dis[k][w];
          			P[w]= k;
          		}
          }

	}
    stack <int >output;
    int temp = Sp;
    output.push(temp);
    while(P[temp]!= -1)
    {
    	output.push(P[temp]);
    	temp = P[temp];
    }
    cout<<"0";
    while(output.empty() == false)
    {
    	cout<<"->"<<output.top();
    	output.pop();
    }
	return 0;
}
