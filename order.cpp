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
void sell(train*head_t,order*head_o)//��Ʊ
{
	char start[20];
	char final[20];
	cout << "��������ʼվ��";
	cin.getline(start, 20);
	cout << "�����뵽��վ��";
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
			cout << "���Σ�" << ps->name << ",��Ʊ��" << ps->capacity - max << endl;
			ps = ps->next;
		}
		else
			ps = ps->next;
	}
	char name[5];
	int count;
	cout << "�����복�Σ�";
	cin.getline(name, 5);
	cout <<"�����빺Ʊ����";
	cin >> count;
	order *porder = new order;
	porder->next = head_o;
	head_o = porder;
	strcpy(head_o->name, name);
	strcpy(head_o->final, final);
	strcpy(head_o->start, start);
	head_o->count = count;
	head_o->no = N;
	cout << "������Ϊ��" << head_o->no << "����Ʊ�ɹ�";
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
	cout << "�����붩���ţ�";
	cin >> no;
	order*pt = head_o;
	order*ps = head_o->next;
	if (pt->no == no)
	{
		head_o = head_o->next;
		delete pt;
		cout << "�ɹ�ɾ������";
	}
	else
	{
		while (ps->no != no)
		{
			if (ps->next == NULL && ps->no != no)
			{
				cout << "����Ķ�����";
				break;
			}
			ps = ps->next;
			pt = pt->next;
		}
		pt->next = ps->next;
		delete ps;
		cout << "�ɹ�ɾ������";
	}
}
void output_order(order*head)
{
	cout << "������" << "����" << "����վ" << "����վ" << "Ʊ��" << "\t" << endl;
	for (; head->next != NULL; head = head->next)
	{
		cout << head->no << head->name << head->start << head->final << head->count << "\t" << endl;
	}
}