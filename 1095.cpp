// 1095.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;
int N;//the number of records;
int K;//the numer of queries;
//in和out不配对的要被忽略
//对于每个查询，输出在这个时刻之前的所有停在里面的车数 
//注意 同一辆车的多次in之间没有out则以最后一次in为有效
//最后一行输出停的最长的车以及时长
//思路：插入的时候先比较按时间排序，然后利用map删除重复的in和out
typedef struct
{
	string name;
	string time;
	string state;
	int length;
}RECORD;
typedef struct
{
	int hour;
	int minu;
	int second;
}TIME;
map<string,string > car;//第一个的是主关键字
map<string, string > car2;//第一个的是主关键字
map<string, string >wait_time;//第一个的是主关键字
string max_time= "00:00:00";
string temp_time;
list<string>max_time_car;
list<RECORD> sequence;
vector<string>quiry;
TIME totime(string str1)
{
	TIME temp;
	temp.hour = (str1[0] - '0') * 10 + str1[1] - '0';
	temp.minu = (str1[3] - '0') * 10 + str1[4] - '0';
	temp.second = (str1[6] - '0') * 10 + str1[7] - '0';
	return temp;
}
string tostring(TIME ti)
{
	string str1="00:00:00";
	str1[0] = ti.hour / 10 % 10 + '0';
	str1[1] = ti.hour % 10 + '0';

	str1[3] = ti.minu / 10 % 10 + '0';
	str1[4] = ti.minu % 10 + '0';

	str1[6] = ti.second / 10 % 10 + '0';
	str1[7] = ti.second % 10 + '0';
	return str1;
}
string small(string str1,string str2)
{
	TIME temp1,temp2;
	string str3 = str1;
	temp1 = (totime(str1));
	temp2 = (totime(str2));
	temp1.hour = temp1.hour - temp2.hour;
	temp1.minu = temp1.minu - temp2.minu;
	temp1.second = temp1.second - temp2.second;
	if (temp1.second < 0)
	{
		temp1.second += 60;
		temp1.minu--;
	}
	if (temp1.minu < 0)
	{
		temp1.minu += 60;
		temp1.hour--;
	}


	return  tostring(temp1);
}
int main()
{
	std::cin >> N >> K;
	RECORD input_buffer;
	string quiry_input;
	for (int i = 0; i < N; i++)
	{
		std::cin>>input_buffer.name>>input_buffer.time>>input_buffer.state;
		if (i != 0)
		{
			//compare
			if (input_buffer.time >= sequence.back().time)//back()直接是最后一个元素
			{
				sequence.push_back(input_buffer);
			}
			else 
			{
				for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); ++it)//ps end 取不到
				{
					if (input_buffer.time < (*it).time)
					{
						sequence.insert(it, input_buffer);
						break;
					}
				}
			}
		}
		else
		{
			sequence.push_back(input_buffer);
		}
		
		std::cin.get();
	}
	for (int i = 0; i < K; i++)
	{
		std::cin >> quiry_input;
		quiry.push_back(quiry_input);
		cin.get();
	}
	for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); ++it)//ps end 取不到
	{
		cout << (*it).name << " " << (*it).time <<" "<<(*it).state<< endl;

	}
	cout << "after clear" << endl;
	//取最后一个In  取第一个out
	for (list<RECORD>::reverse_iterator  it = sequence.rbegin(); it != sequence.rend(); )//ps end 取不到
	{
		    map<string, string >::iterator result = car.find((*it).name);
			if (result != car.end())
			{
				//找到了同样的车牌  检查状态
				if ((*it).state == result->second & (*it).state == "in")//同样就删除原来中的重复车
				{
					it = list<RECORD>::reverse_iterator(sequence.erase((++it).base()));
				}
				else//状态不同
				{
					if ((*it).state == "in")
					{
						result->second = "in";
					}
					else
					{
						result->second = "out";
					}
					++it;
				}
			}
			else
			{
				car.insert(pair<string, string>((*it).name, (*it).state));
				++it;
			}
	}
	for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); )//ps end 取不到
	{
		map<string, string >::iterator result = car2.find((*it).name);
		if (result != car2.end())
		{
			//找到了同样的车牌  检查状态
			if ((*it).state == result->second & (*it).state == "out")//同样就删除原来中的重复车
			{
				it = sequence.erase(it);
			}
			else//状态不同
			{
				if ((*it).state == "in")
				{
					result->second = "in";
				}
				else
				{
					result->second = "out";
				}
				++it;
			}
		}
		else
		{
			car2.insert(pair<string, string>((*it).name, (*it).state));
			++it;
		}
	}
	
	for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); ++it)//ps end 取不到
	{
		cout << (*it).name << " " << (*it).time << " " << (*it).state << endl;
	}
	//step3 开始 按时间输出
	int now_car = 0;
	string limit_time;

	list<RECORD>::iterator it = sequence.begin();
	for (int i = 0; i < K; i++)
	{
		limit_time = quiry[i];

		for (; it != sequence.end(); ++it)//ps end 取不到
		{
			if (limit_time >= (*it).time)
			{
				map<string, string >::iterator result = car.find((*it).name);
				if (result != car.end())
				{
					map<string, string >::iterator max_time_car_it = wait_time.find((*it).name);

					//找到了同样的车牌  检查状态
					if ((*it).state == result->second)//同样就删除原来中的重复车  这种情况已经不可能出现了
					{
						now_car++;
                        if(max_time_car_it == wait_time.end() && (*it).state == "in")
						{
							wait_time.insert(pair<string, string>((*it).name, (*it).time));
						}
					}
					else//状态不同
					{
						

						if ((*it).state == "in")
						{
							result->second = "in";
							now_car++;

							if (max_time_car_it != wait_time.end())
							{
								max_time_car_it->second = (*it).time;
							}
							else
							{
								wait_time.insert(pair<string, string>((*it).name, (*it).time));
							}

						}
						else
						{
							result->second = "out";
							now_car--;


							temp_time = small((*it).time, max_time_car_it->second);
							if (temp_time > max_time)
							{
								max_time = temp_time;
								max_time_car.clear();
								max_time_car.push_back((*it).name);
							}
							else if (temp_time == max_time)
							{
								max_time_car.push_back((*it).name);
							}
						}
					}
				}
			}
			else
			{
				cout << now_car << endl;
				break;
			}
		}
	}
	max_time_car.sort();
	for (list<string>::iterator it = max_time_car.begin(); it != max_time_car.end(); ++it)//ps end 取不到
	{
		cout << (*it)<<" ";
	}
	cout << max_time;

	std::cin >> input_buffer.time;

    return 0;
}

