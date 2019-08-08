#define _CRT_SECURE_NO_WARNINGS 1

//Fibonacci数
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n <= 39
//递推
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
//动态规划
//状态：F[i]
//转移方程:F[i] = F[i-1]+F[i-2];
//初始:F[1] = F[2] = 1;
//返回值：F[n]
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

//法二
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


//变态跳台阶
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
//状态：跳到i级的台阶共有多少种跳法
//转移方程：f[i] = f[i-1]+f[i-2]+...+f[1]
//f[i-1] = f[i-2]+...f[1]
//f[i] = 2f[i-1]
//初始：f[1] = 1,f[2] = 2
//返回值:f[n]
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

