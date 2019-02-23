#include "pch.h"
#include <iostream>
#include <cstring>
#include "struct.h"
using namespace std;
struct order
{
	int no;
	char name[5];
	char start[20];
	char final[20];
	int count;
	order *next;
};
struct station
{
	char sta_name[50];
	int sell;
	station* next;

};
struct train
{
	char name[5];
	int capacity;
	char stations[300];
	train*next;
	station*first;

};
int N = 001;
order *head_order = NULL;
void sell(train*head_t,order*head_o)//买票
{
	char start[20];
	char final[20];
	cout << "请输入起始站：";
	cin.getline(start, 20);
	cout << "请输入到达站：";
	cin.getline(final, 20);
	int key = 0;
	int max = 0;
	for (train*ps = head_t; ps->next != NULL; ps = ps->next)
	{
		station*pb = ps->first;
		while (strcmp(pb->sta_name, start) == -1)
			pb = pb->next;
		if (strcmp(pb->sta_name, start) == 0 && pb->next != NULL)
		{
			key++;
			max = pb->sell;
			station *pw = pb->next;
			while (strcmp(pw->sta_name, final) == -1)
			{
				pw = pw->next;
				if (max <= pw->sell)
					max = pw->sell;
			}
			if (strcmp(pw->sta_name, final) == 0)
				key++;
		}
		if (key == 2)
		{
			cout << "车次：" << ps->name << ",余票：" << ps->capacity - max << endl;
			ps = ps->next;
		}
		else
			ps = ps->next;
	}
	char name[5];
	int count;
	cout << "请输入车次：";
	cin.getline(name, 5);
	cout <<"请输入购票数：";
	cin >> count;
	order *porder = new order;
	porder->next = head_o;
	head_o = porder;
	strcpy(head_o->name, name);
	strcpy(head_o->final, final);
	strcpy(head_o->start, start);
	head_o->count = count;
	head_o->no = N;
	cout << "订单号为：" << head_o->no << "，购票成功";
	N++;
	train*ptrain = head_t;
	for (; strcmp(ptrain->name, name) != 0; ptrain = ptrain->next)
	{
		;
	}
	station*pstation = ptrain->first;
	for (; strcmp(pstation->sta_name, start) != 0; pstation = pstation->next)
	{
		;
	}
	for (; strcmp(pstation->sta_name, final) != 0; pstation = pstation->next)
	{
		pstation->sell += count;
	}
}

order *delete_sell(order*head_o)
{
	int no;
	cout << "请输入订单号：";
	cin >> no;
	order*pt = head_o;
	order*ps = head_o->next;
	if (pt->no == no)
	{
		head_o = head_o->next;
		delete pt;
		cout << "成功删除订单";
	}
	else
	{
		while (ps->no != no)
		{
			if (ps->next == NULL && ps->no != no)
			{
				cout << "错误的订单号";
				break;
			}
			ps = ps->next;
			pt = pt->next;
		}
		pt->next = ps->next;
		delete ps;
		cout << "成功删除订单";
	}
}
void output_order(order*head)
{
	cout << "订单号" << "车次" << "出发站" << "到达站" << "票数" << "\t" << endl;
	for (; head->next != NULL; head = head->next)
	{
		cout << head->no << head->name << head->start << head->final << head->count << "\t" << endl;
	}
}