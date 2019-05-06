#include "test.h"

bool Date::LeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	else
		return false;
}
int Date::GetMonthDay(int year, int month)
{
	int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && LeapYear(year))
		return 29;
	else
		return a[month];

}
Date::Date(int year, int month, int day)
{
	if (year > 0 &&
		month > 0 && month < 13 &&
		day >0 && day <= GetMonthDay(year, day))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
////d1 = d;
//Date::Date(const Date& d)
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
//
////d1 == d2
//bool Date::operator==(const Date& d)
//{
//	return _year == d._year &&
//		_month == d._month &&
//		_day == d._day;
//
//}
////d1 = d2
//Date& Date::operator=(const Date& d)
//{
//	if (this != &d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	else
//		return *this;
//}
//
////d1 > d2
//bool Date::operator>(Date& d)
//{
///*  if (_year > d._year)
//		return true;
//	else if (_year == d._year && _month > d._month)
//		return true;
//	else if (_year == d._year && _month == d._month && _day > d._day)
//		return true;
//	else
//		return false;*/
//	return _year > d._year ||
//		_year == d._year && _month > d._month &&
//		_year == d._year && _month == d._month && _day > d._day;
//}
//
////d1 < d2
//bool Date::operator<(Date& d)
//{
//	//return !((*this == d) && (*this > d));
//	return !(*this >= d);
//}
//
//bool Date::operator<=(Date& d)
//{
//	return ((*this < d) || (*this == d));
//
//}
//
//bool Date::operator>=(Date& d)
//{
//	/*return !(*this < d);*/
//	return *this > d || *this == d;
//}
//
//bool Date::operator!=(Date& d)
//{
//
//}
//
//Date Date::operator++()
//{
//
//}
//
//Date Date::operator++(int)
//{
//
//}
//
//
//Date Date::operator+=(int day)
//{
//
//}
//
//Date Date::operator-=(int day)
//{
//
//}
//
//Date Date::operator+(int day)
//{
//
//}
//
//Date Date::operator-(int day)
//{
//
//}
//
//Date Date::operator--()
//{
//
//}
//
//Date Date::operator--(int)
//{
//
//}

int main()
{
	Date d1(2018, 2, 35);
	//Date d2(d1);
	d1.Print();
	//d2.Print();
	//cout << (d1 == d2) << endl;


	system("pause");
	return 0;
}
