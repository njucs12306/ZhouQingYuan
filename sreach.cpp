#include "pch.h"
#include <iostream>
#include <cstring>
#include "struct.h"
using namespace std;


void sreach1(train*head_train)//按班次查找
{
	char key[5];
	cin.getline(key, 5);
	train*pt = head_train;
	while (strcmp(pt->name, key) == -1)
	{
		if(pt->next!=NULL)
			pt = pt->next;
		else
		{
			cout << "暂无该班次";
			break;
		}
	}
	if (strcmp(pt->name, key) == 0)
	{
		cout << "班次号：" <<pt->name <<endl;
		cout << "最大载客量：" <<pt->capacity<<endl ;
		station *ps = pt->first;
		for (; ps->next != NULL; ps = ps->next)
		{
			cout << ps->sta_name << "站，余票：" << ps->sell<<endl;
		}
	}

	

}

void sreach2(train*head_train)//按站查找
{   
	char start[20];
	char final[20];
	cout << "请输入起始站：";
	cin.getline(start, 20);
	cout << "请输入到达站：";
	cin.getline(final, 20);
	int key = 0;
	int max = 0;
	for (train*ps = head_train; ps->next != NULL; ps = ps->next)
	{
		station*pb = ps->first;
		while (strcmp(pb->sta_name, start) == -1 )
			pb = pb->next;
		if (strcmp(pb->sta_name, start) == 0 && pb->next != NULL)
		{
			key++;
			max = pb->sell;
			pb = pb->next;
			while (strcmp(pb->sta_name, final) == -1)
			{
				pb = pb->next;
				if (max <= pb->sell)
					max = pb->sell;
			}
			if (strcmp(pb->sta_name, final) == 0)
				key++;
		}
		if (key == 2)
		{
			cout << "车次：" << ps->name << ",余票：" << ps->capacity-max << endl;
			ps = ps->next;
		}
		else
			ps = ps->next;
	}
}