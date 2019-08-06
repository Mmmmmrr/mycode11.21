#include <iostream>
using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() 
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}

//协变
class A
{
};
class B : public A 
{
};
class Person
{
public:
	virtual A* f() 
	{
		return new A; 
	}
};
class Student : public Person 
{
public:
	virtual B* f() 
	{
		return new B;
	}
};

//不规范的重写行为
class Person 
{
public:
	virtual void BuyTicket() 
	{
		cout << "买票-全价" << endl;
	}
};
class Student : public Person 
{
public:
	void BuyTicket() 
	{
		cout << "买票-半价" << endl;
	}
};

//析构函数的重写
class Person 
{
public:
	virtual ~Person() 
	{
		cout << "~Person()" << endl;
	}
};
class Student : public Person
{
public:
	virtual ~Student() 
	{
		cout << "~Student()" << endl;
	}
};