#include"pch.h"

#include<iostream>
using namespace std;
void add_train(train* head)
{
	train *pt = new train;
	pt->next = head;
	head = pt;
    cout << "请输入火车信息";
	cin >> head->name;
	cin >> head->capacity;
	cin >> head->stations;
	char *ps = head->stations;
	
	if (*ps == '|')
	{
		ps++;
		station*pb = new station;
		head->first = pb;
		int i = 0;
		for (; *ps != '|'; ps++)
		{

			pb->sta_name[i] = *ps;
			i++;
		}
		pb->sta_name[i] = 0;
	}
	while (*ps != '#')
	{
		if (*ps == '|')
		{
			ps++;
			station*pb = new station;
			head->first = pb;
			int i = 0;
			for (; *ps != '|'; ps++)
			{

				pb->sta_name[i] = *ps;
				i++;
			}
			pb->sta_name[i] = 0;
		}
	}


}