#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//��ͨ�����ռ�

//namespace N1
//{
//	int a;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//namespace N2
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//namespace N3
//{
//	int a;
//	int b;
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
////ͬһ������������ͬʱ���ڶ����ͬ�������ռ�
////��������ϳ���ͬ�������ռ�
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}
//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//using N::a;
//using namespace N;
//int main()
//{
//	//printf("%d\n", a); // ��using N::a;ʱ���������
//	printf("%d\n", N::a);
//	printf("%d\n", a);//��using N::a;
//	printf("%d\n", N::b);
//	//printf("%d\n", b);//��using namespace N;
//	printf("%d\n", b);
//	return 0;
//}
#include <iostream>
using namespace std;
//int main()
//{
//	int a = 0;
//	cin >> a;
//	double d;
//	cin >> d;
//	cout << "Hello world" << endl;
//	cout << 10 << " " << 12.34 << " " << 'a' << " " << endl;
//	
//	system("pause");
//	return 0;
//}

//void Test(int a = 10)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Test();
//	Test(100);
//	system("pause");
//	return 0;
//}
//ȱʡ����
//ȫȱʡ:���Բ�����ȱʡֵ
void test(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}
//��ȱʡ���������ֲ�������ȱʡֵ (��������һ�θ���)
//void test1(int a, int b = 2, int c = 3)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//void test2(int a , int b , int c = 3)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//void test3(int a , int b, int c)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
//int main()
//{
//	//ȫȱʡ
//	test();
//	test(10);
//	test(10, 20);
//	test(10, 20, 30);
//	//��ȱʡ
//	test1(10);
//	test2(10, 20);
//	test3(10, 20, 30);
//	system("pause");
//	return 0;
//}
//��������:������ͬһ������
//������������������ͬ�������б���벻ͬ
//�뷵��ֵ�����Ƿ���ͬ�޹أ������������ֻ�Ƿ���ֵ���Ͳ�ͬ�ǲ����γ�����
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}

int main()
{
	Add(1, 3);
	Add(1.2, 3.4);
	system("pause");
	return;
}











