#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;


void test()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}
void print(list<int> l)
{
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test1()
{
	list<int> l;
	l.push_back(1);
	l.push_front(2);
	l.pop_back();
	l.pop_front();
	print(l);
}

void test2()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	print(l);
	list<int>::iterator it = find(l.begin(), l.end(), 3);
	if (it != l.end())
	{
		l.insert(it, 30);
	}
	//it = find(l.begin(), l.end(), 3);
	//l.erase(it);
	//迭代器失效(不能访问，不能++)
	//cout << *it << endl;
	it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}
	print(l);
}
void test3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(2);
	l.push_back(3);
	l.push_back(3);
	l.push_back(3);
	l.push_back(4);
	l.push_back(2);
	l.push_back(2);
	print(l);
	l.unique();
	print(l);

}
int main()
{
	//test();
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}