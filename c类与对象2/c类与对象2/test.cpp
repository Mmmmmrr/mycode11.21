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
//	ps->TestFunc1();//���ܻ���� ��ָ����ʳ�Ա����
//	return 0;
//}
//class Test
//{
//public:
//	void TestFunc()
//	{
//		//cout << &this << endl;  ������ this��const����
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

//����  ��СΪ1
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
//	Date d2();//d2�Ǻ����������Ǵ���һ�����󣬶���һ������������û�в���������һ���������Ͷ���ĺ�������
//	d.InitDate(2019, 1, 5);
//	d.PrintDate();
//	system("pause");
//	return 0;
//}

//�û�û�ж��壬���������ɵĹ��캯����Ĭ�ϵĹ��캯��������һ�����޲εġ�
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
	Date d; //�û�û�ж��壬���������ɵĹ��캯����Ĭ�ϵĹ��캯��������һ�����޲εġ�
	return 0;
}
