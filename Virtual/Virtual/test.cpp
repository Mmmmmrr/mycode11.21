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

// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�
//̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}


//������
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
		cout << "����" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "��" << endl;
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
// override �����������麯��ǿ�������д
class Sticket :public Ticket {
public:
	virtual void Buy() override 
	{
		cout << "ѧ��Ʊ" << endl; 
	}
};


class T{
public:
	virtual void Ty()
	{
	}
};
// 2.override �����������麯��ǿ�������д�����û����д����뱨��
class X :public T {
public:
	virtual void Ty() 
	{
		cout << "T" << endl;
	}
};

// final ���λ�����麯�����ܱ���������д
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
	//���ܱ���д
	//virtual void T() 
	/*{ 
		cout << "C" << endl;
	}*/
};

