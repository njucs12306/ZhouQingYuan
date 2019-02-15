#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
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

station*creat_sta_list(char stations[])
{
	station*head = NULL;
char*ps = stations;
if (*ps == '|')
{
	ps++;
	station*pt = new station;
	head = pt;
	int i = 0;
	for (; *ps != '|'; ps++)
	{

		head->sta_name[i] = *ps;
		i++;
	}
	head->sta_name[i] = 0;
}

while (*ps != '#')
{
	if (*ps == '|')
	{
		ps++;
		station*pb = new station;
		pb->next = head;
		head = pb;
		int i = 0;
		for (; *ps != '|'&&*ps != '#'; ps++)
		{

			head->sta_name[i] = *ps;
			i++;
		}
		head->sta_name[i] = 0;
	}
}
	return head;
}
train*creat_tra_list()
{
	char File_name[20];
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
}