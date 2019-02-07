#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;
struct train 
{
	char name[10];
	int capacity;
	char station[200];
};
//主菜单显示函数
void main_menu()                    
{
	cout << endl << "                                  欢迎使用12306选票系统";
	for (int i = 0; i < 3; i++)
	{
		cout <<endl;
	}
	for (int i = 0; i < 30; i++)
	{
		cout <<" ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      1 录入班次信息       ："<<endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      2 操作班次信息       ："<<endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      3 查询班次信息       ："<<endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      4 售票与退票系统     ："<<endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      5 导出票务系统       ："<<endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      6 退出系统           ："<<endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}

}    
//操作班次菜单显示函数
void menu2()
{
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      1 添加/修改班次      ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      2 删除班次           ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      3 返回主菜单         ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}
}
//班次查询菜单显示函数
void menu3()
{
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      1 按班次查询         ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	} 
	cout << "：      2 按站查询           ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      3 返回主菜单         ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}
}
//票务系统菜单显示函数
void menu4()
{
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      1 售票               ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      2 订单浏览           ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      3 退票               ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	cout << "：      4 返回主菜单         ：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 30; i++)
	{
		cout << "*";
	}
}
//添加班次函数（待定）
train *add()
{
	train *pt = new train;
	cin >> pt->name;
	cin >> pt->capacity ;
	cin >> pt->station;
	return pt;
}
//删除班次函数（待定）
void delete_train(train *pt)
{
	delete pt;
}
//修改班次函数（待定）
train *alter_train(train *pt)
{
	delete_train(pt);
	return add();
}
//从文件读入火车信息函数
char *input_train()
{
	char content[4000];
	content[0] = '\0';
	FILE *fp = fopen("mytrain.txt", "r");
	if (!fp)
	{
		cout << "文件打开失败";
	}
	else
	{
		while (!feof(fp))
		{
		    char part[200];
			fgets(part, sizeof(part) - 1, fp);
			strcat(content, part);
		}
		cout << content;
	}
	return content;
}
//根据读入信息建立火车数据函数
//void data_train(char *pt)
//{
//	int count_train = 1;
//	for (char *psome = pt; psome != '\0'; psome++)
//	{
//		if (*psome == '\n')
//			count_train++;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		train *p
//	}
//}

int main()
{
	char *pt = input_train();
	return 0;
}

