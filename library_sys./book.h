#ifndef book_H
#define book_H
#include<iostream>
using namespace std;

class book
{
public:
	book(int a=0, string b= {}, string c= {}, string d= {}) 
	{
		id = a;
		name = b;
		writer = c;
		year = d;
	}
	int id;
	string name;
	string writer;
	string year;
};

class library :public book
{
public:
	library(int id = 0, string name = {}, string writer = {}, string year = {}, char r[7] = {})
		:book(id, name, writer, year)
	{
		for (int i = 0; i < 6; i++)
		{
			reader[i] = ' ';
		}
	}
	char reader[7] = {};
	book x;
};

#endif 

