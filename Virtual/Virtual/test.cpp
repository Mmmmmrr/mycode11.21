#include <iostream>
using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() 
//	{
//		cout << "��Ʊ-���" << endl;
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

//Э��
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

//���淶����д��Ϊ
class Person 
{
public:
	virtual void BuyTicket() 
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};
class Student : public Person 
{
public:
	void BuyTicket() 
	{
		cout << "��Ʊ-���" << endl;
	}
};

//������������д
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