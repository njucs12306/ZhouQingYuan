#pragma once
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
struct order
{
	int no;
	char name[5];
	char start[20];
	char final[20];
	int count;
};