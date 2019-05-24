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
//class Date
//{
//public:
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
//	Date d; //用户没有定义，编译器生成的构造函数：默认的构造函数，而且一定是无参的。
//	return 0;
//}


//构造函数在对象的整个生命周期只调用一次
//class Date
//{
//public: 
//	Date()
//	{
//		cout << "Date(int, int, int)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d;
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

#include <cassert>
#include <malloc.h>
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		cout << "SeqList(int, int)" <<endl;
//		_array = (int*)malloc(sizeof(int)*capacity);
//		assert(_array);
//		_capacity = capacity;
//		_size = 0;
//	}
//	//编译器默认的
//	//~Seqlist()
//	//{}
//	~SeqList()
//	{
//		if (_array)
//		{
//			free(_array);
//			_capacity = _size = 0;
//		}
//		cout << "~SeqLise()" << endl;
//	}
//private:
//	int* _array;
//	int _capacity;
//	int _size;
//};
//void TestSeqList()
//{
//	SeqList s;
//}
//int main()
//{
//	TestSeqList();
//	system("pause");
//	return 0;
//}

class String
{
public:
	String(const char* str = "")
	{
		cout << "String(char)" << endl;
		if (str == nullptr)
			str = "";
		_str = (char*)malloc(strlen(str)+1);
		strcpy(_str, str);
	}
	~String()
	{
		free(_str);
		_str = nullptr;
		cout << "~String()" << endl;
	}
private:
	char* _str;
};
//void TestString()
//{
//	String s1("hello");
//	String s2(s1);
//}
//int main()
//{
//	TestString();
//	system("pause");
//	return 0;
//}

//class Person
//{
//	//生成默认的构造函数----将对象中_name和_gender两个String类型的对象构造好
//	//生成默认的析构函数----将对象中_name和_gender两个String类型的对象析构
//private:
//	String _name;
//	String _gender;
//	int age;
//};
//void TestPerson()
//{
//	Person p;
//}
//int main()
//{
//	TestPerson();
//	//String s(nullptr);
//	system("pause");
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 1990, int month = 2, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" <<this<< endl;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(Date& d)" <<this<< endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" <<this << endl;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1;
//	Date d2(d1);
//}
//int main()
//{
//	TestDate();
//	system("pause");
//	return 0;
//}

















