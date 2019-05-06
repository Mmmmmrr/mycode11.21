#include <iostream>
using namespace std;
//构造函数
//class Date
//{
//public:
//	Date()
//	{
//		_year = 2019;
//		_month = 8;
//		_day = 5;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	system ("pause");
//	return 0;
//}

//析构函数
//


//拷贝函数
//class Date
//{
//public:
//	Date()
//	{
//		_year = 2018;
//		_month = 8;
//		_day = 9;
//	}
//	Date(const Date& d1)
//	{
//		_year = d1._year;
//		_month = d1._month;
//		_day = d1._day;
//	}
//	void Print()
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
//	Date d1;
//	Date d2(d1);
//	d1.Print();
//	d2.Print();
//	system("pause");
//	return 0;
//}

//赋值重载
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator == ( const Date& d2)
//	{
//		return _year == d2._year&&
//			_month == d2._month &&
//			_day == d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2018,1,5);
//	Date d2(2018,1,5);
//	cout << (d1 == d2) << endl;
//	system("pause");
//	return 0;
//
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator !=(const Date& d2)
//	{
//		return _year != d2._year ||
//			_month != d2._month ||
//			_day != d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2019, 8, 9);
//	Date d2(2019, 8, 9);
//	cout << (d1 != d2) << endl;
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator >(const Date& d2)
//	{
//		return _year > d2._year ||
//			_month > d2._month ||
//			_day > d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2018, 8, 9);
//	Date d2(2019, 8, 9);
//	cout << (d1 > d2) << endl;
//	system("pause");
//	return 0;
//}
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator < (const Date& d2)
//	{
//		return _year < d2._year ||
//			_month < d2._month ||
//			_day < d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2019, 8, 9);
//	Date d2(2019, 8, 10);
//	cout << (d1 < d2) << endl;
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator >= (const Date& d2)
//	{
//		return _year >= d2._year ||
//			_month >= d2._month ||
//			_day >= d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2019, 8, 9);
//	Date d2(2019, 8, 9);
//	cout << (d1 >= d2) << endl;
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator <=(const Date& d2)
//	{
//		return _year <= d2._year ||
//			_month <= d2._month ||
//			_day <= d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2019, 8, 9);
//	Date d2(2019, 8, 9);
//	cout << (d1 <= d2) << endl;
//	system("pause");
//	return 0;
//}
//
//class Date
//{
//public:
//	bool Leapyear(int year)
//	{
//		if ((year % 400) == 0 || year % 4 == 0 && year % 100 != 0)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	int GetMonthDay(int year, int month)
//	{
//		int monthArray[13] = { 0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
//		if (month == 2 && Leapyear(year))
//			return 29;
//		else
//			return monthArray[month];
//	}
//
//	Date(int year = 2019, int month = 1, int day = 1)
//	{
//		if (year > 0 &&
//			month > 0 && month < 13 &&
//			day > 0 && day <= GetMonthDay(year, month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			cout << "日期非法:";
//			cout << _year << "-" << _month << "-" << _day << endl;
//		}
//
//	}
//	Date operator+(int day)
//	{
//		
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
