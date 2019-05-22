#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
using namespace std;

//class A
//{
//public:
//	void TestFunc1()
//	{
//		cout << this << endl;
//		this->_a = 20;
//		cout << "TestFunc1()" << endl;
//	}
//
//	void TestFunc2()
//	{
//		this->_a = 10;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* ps = nullptr;
//	ps->TestFunc1();//可能会崩溃 空指针访问成员变量
//	return 0;
//}
//class Test
//{
//public:
//	void TestFunc()
//	{
//		//cout << &this << endl;  看不了 this是const常量
//		Test* const& p = this;
//		cout << &p << endl;
//	}
//private:
//	int _t;
//};
//int main()
//{
//	int* p = nullptr;
//	int*& q = p;
//	cout << &p << endl;
//	cout << &q << endl;
//	Test t;
//	t.TestFunc();
//	system("pause");
//	return 0;
//}

//空类  大小为1
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date();" << this << endl;
//	}
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void InitDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void PrintDate()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d;
//	Date d1(2018, 5, 8);
//	Date d2();//d2是函数名，不是创建一个对象，而是一个函数声明，没有参数，返回一个日期类型对象的函数声明
//	d.InitDate(2019, 1, 5);
//	d.PrintDate();
//	system("pause");
//	return 0;
//}

//用户没有定义，编译器生成的构造函数：默认的构造函数，而且一定是无参的。
class Date
{
public:
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d; //用户没有定义，编译器生成的构造函数：默认的构造函数，而且一定是无参的。
	return 0;
}
