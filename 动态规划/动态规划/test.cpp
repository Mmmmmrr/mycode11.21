#define _CRT_SECURE_NO_WARNINGS 1

//Fibonacci��
//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����n <= 39
//����
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);

	}
};
//��̬�滮
//״̬��F[i]
//ת�Ʒ���:F[i] = F[i-1]+F[i-2];
//��ʼ:F[1] = F[2] = 1;
//����ֵ��F[n]
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int *f = new int[n + 1];
		f[0] = 0;
		f[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};

//����
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int f1 = 1;
		int f2 = 1;
		int tmp = 0;
		for (int i = 3; i <= n; i++)
		{
			tmp = f1 + f2;
			f2 = f1;
			f1 = tmp;
		}
		return tmp;
	}
};


//��̬��̨��
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж���������
//״̬������i����̨�׹��ж���������
//ת�Ʒ��̣�f[i] = f[i-1]+f[i-2]+...+f[1]
//f[i-1] = f[i-2]+...f[1]
//f[i] = 2f[i-1]
//��ʼ��f[1] = 1,f[2] = 2
//����ֵ:f[n]
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		vector<int> f(number + 1);
		f[1] = 1;
		f[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			f[i] = 2 * f[i - 1];
		}
		return f[number];
	}
};

