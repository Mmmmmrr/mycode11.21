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
//	//�����޸ĳ�Ա����
//	void TestFunc() const
//	{
//		//_day++;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////�������ص��������.*��::��sizeof��?:��.
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
//	//��ʼ���б�
//	//1.��ʼ���б��г�Ա�ĳ��ִ��򣬲������������ĳ�ʼ������
//	//2.��Ա�����ڳ�ʼ���б�ĳ�ʼ������Ϊ�������е���������
//	//��ò�Ҫʹ�ó�Ա��ʼ����Ա
//	//eg��:_year(year)
//	//    ,_day(day)
//	//    ,_month(day)
//	//��ʼ��ʱ_year������_month�����(day��û��ʼ��),_day����
//	Date(int year = 1999, int month = 5, int day = 5)
//		:_year(year)
//		//��this->_year(year)   ����thisָ��ǰ����ģ���ʼ��ʱ����û�гɹ�
//		, _month(month)
//		, _day(day)
//		, _r(_day)
//		, _a(_day)
//		, _t(0, 0, 0)              //, _t()   //�����޲εĹ��캯��
//
//
//
//	{
//		//���캯�������Ǹ���ֵ�����ǳ�ʼ��
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
//	//�ڱ����������ڼ䣬�Ѿ�Ϊmain�������ջ�ռ�
//	//�ÿռ����Ѿ������˺������еľֲ�����
//	/*Date d1(2019, 2, 8);//���캯������֮ǰ�������ǲ����ڵ�
//	Date d2(d1);*/
//
//	return 0;
//}
//
//
////���캯��������
////1.����������
////2.����������ʽ����ת����explicit ������ת����
//
//
////���ܹ������˶��ٸ�����
////�����ı���----���ܰ�����ÿ�������У�Ӧ�������ж������
////ʹ��ȫ�ֱ���������ȫ������g_count��ֵΪ0���ͽ����޸���
////��ͨ��Ա����                       static��Ա����
////�����ڳ�ʼ���б��г�ʼ��                ������
////ÿ�����󶼰���                          ֻ��һ�ݣ����ж�����û�а����ھ���Ķ�����
////����ͨ���������                        ����ͨ������ֱ�ӷ���Ҳ����ͨ��������������ķ�ʽ����
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
//	static int _count;//����һ������ĳ�Ա����
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

