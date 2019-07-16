#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 1999, int month = 2, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" << endl;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(Date& d)" << endl;
//	}
//
//	Date& DateAdd(int day)
//	{
//		_day += day;
//		return *this;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//	Date operator+(int day)
//	{
//		Date tmp(*this);
//		tmp._day += day;
//		return tmp;
//	}
//	bool operator == (const Date& d)
//	{
//		return _year == d._year&&
//			_month == d._month&&
//			_day == d._day;
//	}
//	bool operator != (const Date& d)
//	{
//		return !(*this == d);
//	}
//	Date& operator = (const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	//++d1
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//	Date operator++(int)
//	{
//		Date tmp(*this);
//		_day += 1;
//		return tmp;
//	}
//	Date& operator--()
//	{
//		_day -= 1;
//		return *this;
//	}
//	Date operator--(int)
//	{
//		Date tmp(*this);
//		_day -= 1;
//		return tmp;
//	}
//	Date* operator&()
//	{
//		return this;
//	}
//
//	//不能修改成员函数
//	void TestFunc() const
//	{
//		//_day++;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////不能重载的运算符：.*、::、sizeof、?:、.
//int main()
//{
//	Date d;
//	Date d1(2009, 1, 5);
//	Date d2(d1);
//	Date d3(2018, 1, 3);
//	d3 = d1;
//
//	d1 = d1 +3;
//	d1 = d2 = d3;
//
//	Date d4(1995,7,5);
//	d = d4++;
//	d = ++d4;
//	cout << &d << endl;
//
//	const Date d1;
//	d1.TestFunc();
//	Date d2;
//	d2.TestFunc();
//	system("pause");
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour,int minute,int second)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{
//
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	//初始化列表
//	//1.初始化列表中成员的出现次序，不代表其真正的初始化次序
//	//2.成员变量在初始化列表的初始化次序为其在类中的声明次序
//	//最好不要使用成员初始化成员
//	//eg：:_year(year)
//	//    ,_day(day)
//	//    ,_month(day)
//	//初始化时_year正常，_month随机数(day还没初始化),_day正常
//	Date(int year = 1999, int month = 5, int day = 5)
//		:_year(year)
//		//：this->_year(year)   错误：this指向当前对象的，初始化时对象还没有成功
//		, _month(month)
//		, _day(day)
//		, _r(_day)
//		, _a(_day)
//		, _t(0, 0, 0)              //, _t()   //调用无参的构造函数
//
//
//
//	{
//		//构造函数体中是赋初值，不是初始化
//	/*	_year = year;
//		_month = month;
//		_day = day;*/
//		//r = day;
//	}
//	/*Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//		, _r(d._r)
//		, _a(d._a)
//	{
//
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//	int& _r;
//	const int _a;
//	Time _t;
//
//	
//};
//int main()
//{
//	//在编译器编译期间，已经为main分配好了栈空间
//	//该空间中已经包含了函数体中的局部变量
//	/*Date d1(2019, 2, 8);//构造函数调用之前，对象是不存在的
//	Date d2(d1);*/
//
//	return 0;
//}
//
//
////构造函数的作用
////1.对象构造完整
////2.单参数的隐式类型转换（explicit 不允许转换）
//
//
////类总共创建了多少个对象？
////计数的变量----不能包含在每个对象中，应该是所有对象共享的
////使用全局变量（不安全）若将g_count赋值为0，就将其修改了
////普通成员变量                       static成员变量
////可以在初始化列表中初始化                不可以
////每个对象都包含                          只有一份，所有对象共享，没有包含在具体的对象中
////必须通过对象访问                        可以通过对象直接访问也可以通过类名加作用域的方式访问
//using namespace std;
//int g_count = 0;
//class Test
//{
//public:
//	Test()
//		//:_count(0)
//	{
//		//g_count++;
//		_count++;
//	}
//
//	Test(Test& t)
//	{
//		//g_count++;
//		_count++;
//	}
//
//	static int GetCount()
//	{
//		return _count;
//	}
//
//	~Test()
//	{
//		//g_count--;
//		_count--;
//	}
//
//private:
//	int _b;
//	//int _count;
//public:
//	static int _count;//定义一个共享的成员变量
//};
//int Test::_count = 0;
//void TestCount()
//{
//	Test t1, t2;
//	//cout << g_count << endl;
//	cout << t1.GetCount() << endl;
//}
//int main()
//{
//	Test t1, t2;
//	cout << t1.GetCount() << endl;
//	/*cout << sizeof(t1) << endl;
//	cout << &t1._count << "=" << &t2._count << endl;
//	cout << Test::_count << endl;
//
//	int a = 10;
//	a = t1._count;
//	a = Test::_count;*/
//	TestCount();
//	cout << t1.GetCount() << endl;
//	//cout << g_count << endl; 
//	return 0;
//}


//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class Date{
//public:
//	Date(int year = 2019, int month = 5, int day = 5, int ref = 10)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _N(10)
//		, _ref(ref)
//		, _aa(10)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//	const int _N;
//	int& _ref;
//	A _aa;
//};
//int main()
//{
//	Date d(2018, 9, 10);
//	system("pause");
//	return 0;
//}
//
//class Array
//{
//public:
//	Array(int size)
//		:_size(size)
//		, _array((int*)malloc(sizeof(int)*_size))
//	{}
//	
//
//private:
//	int _size;
//	int* _array;
//};
//int main()
//{
//	Array a(10);
//	return 0;
//}



//class Date{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator<<(istream& in, Date& d);
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//istream& operator<<(istream& in,Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//int main()
//{
//	Date d1(2019, 1, 17);
//	Date d2(2019, 1, 18);
//	cout << d1 << d2 << endl;
//	return 0;
//}


class Solution
{
public:
	class Sum{
	public:
		Sum()
		{
			ret += i;
			++i;
		}
	};
	int sum_Solution(int n)
	{
		ret = 0;
		i = 1;
		//Sum array[n];
		Sum* p = new Sum[n];
		delete[] p;
		return ret;
	}
private:
     static int ret;
	 static int i;
	
};
int Solution::ret = 0;
int Solution::i = 1;

int main()
{
	int n;
	cin >> n;
	cout << Solution().sum_Solution(n)<< endl;
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int monthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
		int nday = monthDays[month - 1] + day;
		if (month > 2 && ((year % 4 == 0) && (year / 100 != 0) || year % 400 == 0))
			nday += 1;
		cout << nday << endl;
	}
	system("pause");
	return 0;
}

