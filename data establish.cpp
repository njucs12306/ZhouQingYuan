#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

station*creat_sta_list(char stations[])
{
	station*headst = NULL;
char*ps = stations;
if (*ps == '|')
{
	ps++;
	station*pt = new station;
	headst = pt;
	int i = 0;
	for (; *ps != '|'; ps++)
	{

		headst->sta_name[i] = *ps;
		i++;
	}
	headst->sta_name[i] = 0;
}

while (*ps != '#')
{
	if (*ps == '|')
	{
		ps++;
		station*pb = new station;
		pb->next = headst;
		headst = pb;
		int i = 0;
		for (; *ps != '|'&&*ps != '#'; ps++)
		{

			headst->sta_name[i] = *ps;
			i++;
		}
		headst->sta_name[i] = 0;
	}
}
	return headst;
}
train*creat_tra_list()
{
	char File_name[20];
	cout << "请输入文件名称：";
	cin.getline(File_name, 20);
	ifstream infile;
	infile.open(File_name);
	train*head = NULL;
	train*pt = new train;
	head = pt;
	infile >> pt->name;
	infile >> pt->capacity;
	infile >> pt->stations;
	pt->first = creat_sta_list(pt->stations);
	while (infile.good())
	{
		train*ps = new train;
		ps->next = head;
		head = ps;
		infile >> ps->name;
		infile >> ps->capacity;
		infile >> ps->stations;
		ps->first = creat_sta_list(ps->stations);
	}
	return head;
}