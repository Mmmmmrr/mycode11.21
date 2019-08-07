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

// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多
//态，才能保证p1和p2指向的对象正确的调用析构函数。
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}


//抽象类
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "舒适" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "宽敞" << endl;
	}
};
void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}

class Ticket{
public:
	virtual void Buy()
	{
	}
};
// override 修饰派生类虚函数强制完成重写
class Sticket :public Ticket {
public:
	virtual void Buy() override 
	{
		cout << "学生票" << endl; 
	}
};


class T{
public:
	virtual void Ty()
	{
	}
};
// 2.override 修饰派生类虚函数强制完成重写，如果没有重写会编译报错
class X :public T {
public:
	virtual void Ty() 
	{
		cout << "T" << endl;
	}
};

// final 修饰基类的虚函数不能被派生类重写
class X
{
public:
	virtual void T() final 
	{
	}
};
class C :public X
{
public:
	//不能被重写
	//virtual void T() 
	/*{ 
		cout << "C" << endl;
	}*/
};

