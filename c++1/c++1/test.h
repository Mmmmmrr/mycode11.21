#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	bool LeapYear(int year);
	Date(int year, int month, int day);
	void Print();
	Date(const Date& d);
	int GetMonthDay(int year, int month);
	bool operator==(const Date& d);
	Date& operator=(const Date& d);
	bool operator>(Date& d);
	bool operator<(Date& d);
	bool operator<=(Date& d);
	bool operator>=(Date& d);
	bool operator!=(Date& d);
	Date operator++();
	Date operator++(int);
	Date operator+=(int day);
	Date operator-=(int day);
	Date operator+(int day);
	Date operator-(int day);
	Date operator--();
	Date operator--(int);
	



private:
	int _year;
	int _month;
	int _day;
};