// 1095.cpp : �������̨Ӧ�ó������ڵ㡣
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
//in��out����Ե�Ҫ������
//����ÿ����ѯ����������ʱ��֮ǰ������ͣ������ĳ��� 
//ע�� ͬһ�����Ķ��in֮��û��out�������һ��inΪ��Ч
//���һ�����ͣ����ĳ��Լ�ʱ��
//˼·�������ʱ���ȱȽϰ�ʱ������Ȼ������mapɾ���ظ���in��out
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
map<string,string > car;//��һ���������ؼ���
map<string, string > car2;//��һ���������ؼ���
map<string, string >wait_time;//��һ���������ؼ���
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
			if (input_buffer.time >= sequence.back().time)//back()ֱ�������һ��Ԫ��
			{
				sequence.push_back(input_buffer);
			}
			else 
			{
				for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); ++it)//ps end ȡ����
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
	for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); ++it)//ps end ȡ����
	{
		cout << (*it).name << " " << (*it).time <<" "<<(*it).state<< endl;

	}
	cout << "after clear" << endl;
	//ȡ���һ��In  ȡ��һ��out
	for (list<RECORD>::reverse_iterator  it = sequence.rbegin(); it != sequence.rend(); )//ps end ȡ����
	{
		    map<string, string >::iterator result = car.find((*it).name);
			if (result != car.end())
			{
				//�ҵ���ͬ���ĳ���  ���״̬
				if ((*it).state == result->second & (*it).state == "in")//ͬ����ɾ��ԭ���е��ظ���
				{
					it = list<RECORD>::reverse_iterator(sequence.erase((++it).base()));
				}
				else//״̬��ͬ
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
	for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); )//ps end ȡ����
	{
		map<string, string >::iterator result = car2.find((*it).name);
		if (result != car2.end())
		{
			//�ҵ���ͬ���ĳ���  ���״̬
			if ((*it).state == result->second & (*it).state == "out")//ͬ����ɾ��ԭ���е��ظ���
			{
				it = sequence.erase(it);
			}
			else//״̬��ͬ
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
	
	for (list<RECORD>::iterator it = sequence.begin(); it != sequence.end(); ++it)//ps end ȡ����
	{
		cout << (*it).name << " " << (*it).time << " " << (*it).state << endl;
	}
	//step3 ��ʼ ��ʱ�����
	int now_car = 0;
	string limit_time;

	list<RECORD>::iterator it = sequence.begin();
	for (int i = 0; i < K; i++)
	{
		limit_time = quiry[i];

		for (; it != sequence.end(); ++it)//ps end ȡ����
		{
			if (limit_time >= (*it).time)
			{
				map<string, string >::iterator result = car.find((*it).name);
				if (result != car.end())
				{
					map<string, string >::iterator max_time_car_it = wait_time.find((*it).name);

					//�ҵ���ͬ���ĳ���  ���״̬
					if ((*it).state == result->second)//ͬ����ɾ��ԭ���е��ظ���  ��������Ѿ������ܳ�����
					{
						now_car++;
                        if(max_time_car_it == wait_time.end() && (*it).state == "in")
						{
							wait_time.insert(pair<string, string>((*it).name, (*it).time));
						}
					}
					else//״̬��ͬ
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
	for (list<string>::iterator it = max_time_car.begin(); it != max_time_car.end(); ++it)//ps end ȡ����
	{
		cout << (*it)<<" ";
	}
	cout << max_time;

	std::cin >> input_buffer.time;

    return 0;
}

