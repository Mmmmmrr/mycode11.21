#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>

using namespace std;
class Date
{
public:
	Date(int year = 1999, int month = 2, int day = 5)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int)" << endl;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date& d)" << endl;
	}

	Date& DateAdd(int day)
	{
		_day += day;
		return *this;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
	Date operator+(int day)
	{
		Date tmp(*this);
		tmp._day += day;
		return tmp;
	}
	bool operator == (const Date& d)
	{
		return _year == d._year&&
			_month == d._month&&
			_day == d._day;
	}
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}
	Date& operator = (const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//++d1
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		return tmp;
	}
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		_day -= 1;
		return tmp;
	}
	Date* operator&()
	{
		return this;
	}

	//不能修改成员函数
	void TestFunc() const
	{
		//_day++;
	}
private:
	int _year;
	int _month;
	int _day;
};
//不能重载的运算符：.*、::、sizeof、?:、.
int main()
{
	Date d;
	Date d1(2009, 1, 5);
	Date d2(d1);
	Date d3(2018, 1, 3);
	d3 = d1;
	d1.DateAdd(3);
	d1 = d1 +3;
	d1 = d2 = d3;

	Date d4(1995,7,5);
	d = d4++;
	d = ++d4;
	cout << &d << endl;

	const Date d1;
	d1.TestFunc();
	Date d2;
	d2.TestFunc();
	system("pause");
	return 0;
}