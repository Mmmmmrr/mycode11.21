#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//普通命名空间

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
////同一个工程中允许同时存在多个相同的命名空间
////编译器会合成相同的命名空间
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
//	//printf("%d\n", a); // 无using N::a;时，编译出错
//	printf("%d\n", N::a);
//	printf("%d\n", a);//有using N::a;
//	printf("%d\n", N::b);
//	//printf("%d\n", b);//无using namespace N;
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
//缺省参数
//全缺省:所以参数带缺省值
void test(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}
//半缺省参数：部分参数带有缺省值 (从右往左一次给出)
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
//	//全缺省
//	test();
//	test(10);
//	test(10, 20);
//	test(10, 20, 30);
//	//半缺省
//	test1(10);
//	test2(10, 20);
//	test3(10, 20, 30);
//	system("pause");
//	return 0;
//}
//函数重载:必须在同一作用域
//条件：函数名必须相同，参数列表必须不同
//与返回值类型是否相同无关，如果函数仅仅只是返回值类型不同是不能形成重载
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











