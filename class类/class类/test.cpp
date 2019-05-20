#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
//C: 数据和操作数据的方法是分离开的，可以放数据不能放函数
//C++：结构体中不仅可以放数据，也可以放函数
//struct Student
//{
//	void InitStudent(char* name, int age, char* sex)
//	{
//		strcpy(_name, name);
//		_age = age;
//		strcpy(_sex, sex);
//	}
//	void PrintStudent()
//	{
//		cout << _name << "_" << _age << "_" << _sex << endl;
//	}
//	char _name[15];
//	int _age;
//	char _sex[5];
//};
//int main()
//{
//	Student s1, s2, s3;
//	s1.InitStudent("Peter", 35, "男");
//	s1.PrintStudent();
//	s2.InitStudent("kkk", 55, "女");
//	s2.PrintStudent();
//	s3.InitStudent("sss", 18, "女");
//	s3.PrintStudent();
//	system("pause");
//	return 0;
//}


//class定义的类，默认情况下是私有的
//class Student
//{
//public:
//	void InitStudent(char* name, int age, char* sex)
//	{
//		strcpy(_name, name);
//		_age = age;
//		strcpy(_sex, sex);
//	}
//	void PrintStudent()
//	{
//		cout << _name << "_" << _age << "_" << _sex << endl;
//	}
//private:
//	char _name[15];
//	int _age;
//	char _sex[5];
//};
//int main()
//{
//	Student s;
//	s.InitStudent("sss", 15, "女");
//	s.PrintStudent();
//	system("pause");
//	return 0;
//}

//类大小的计算方式：类成员变量加起来+内存对齐
//与求结构体一样
//class A
//{
//public:
//	void TestFunc()
//	{}
//private:
//	int _age;
//	
//
//};
//class B
//{
//public:
//	void TestFunc()
//	{}
//};
//
////空类大小为1
//class C
//{};
//int main()
//{
//	//把成员变量加起来+内存对齐
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	system("pause");
//	return 0;
//}

class Student
{
public:


	//void InitS(,Student* const this, char* name, int age, char* sex)
	//{   //this : Student* const
	//	strcpy(this->_name, name);
	//	this_age = age;
	//	strcpy(this_sex, sex);
	//}
	void InitS(char* name, int age, char* sex)
	{   //this : Student* const
		strcpy(this->_name, name);
		_age = age;
		strcpy(_sex, sex);
	}
	//this指针编译器自己维护的
	/*void PrintStudent(Student* const this)
	{
		cout << this->_name << "_" << this->_age << "_" << this->_sex << endl;
	}*/
	void PrintStudent()
	{
		cout << this->_name << "_" << this->_age << "_" << this->_sex << endl;
	}
private:
	char _name[20];
	int _age;
	char _sex[5];
};
int main()
{
	Student s1;
	s1.InitS("ss", 15, "s");
	s1.PrintStudent();
	Student s2;
	s2.InitS("qq", 12, "q");
	s2.PrintStudent();
}


