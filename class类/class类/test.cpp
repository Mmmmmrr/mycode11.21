#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
//C: ���ݺͲ������ݵķ����Ƿ��뿪�ģ����Է����ݲ��ܷź���
//C++���ṹ���в������Է����ݣ�Ҳ���Էź���
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
//	s1.InitStudent("Peter", 35, "��");
//	s1.PrintStudent();
//	s2.InitStudent("kkk", 55, "Ů");
//	s2.PrintStudent();
//	s3.InitStudent("sss", 18, "Ů");
//	s3.PrintStudent();
//	system("pause");
//	return 0;
//}


//class������࣬Ĭ���������˽�е�
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
//	s.InitStudent("sss", 15, "Ů");
//	s.PrintStudent();
//	system("pause");
//	return 0;
//}

//���С�ļ��㷽ʽ�����Ա����������+�ڴ����
//����ṹ��һ��
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
////�����СΪ1
//class C
//{};
//int main()
//{
//	//�ѳ�Ա����������+�ڴ����
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
	//thisָ��������Լ�ά����
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


