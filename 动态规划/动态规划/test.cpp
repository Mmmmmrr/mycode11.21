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


//��������������ֵ
//״̬��F[i]:ǰi��������������ֵ
//ת�Ʒ���:F[i] = max(F[i-1]+array[i],array[i])
//��ʼ:sum = array[0]
//����ֵ��Maxsum
#include <iostream>
#include <algorithm>
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		int sum = array[0];
		int MaxSum = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			sum = (sum > 0) ? sum + array[i] : array[i];
			MaxSum = max(sum, MaxSum);
		}
		return MaxSum;

	}
};

//word_break
//״̬��ǰi���ַ����ֵ������ҵ�
//ת�Ʒ��̣�0-j��j-i�в���
//F[i] = dict.find(s.substr(j,i-j))
//��ʼ:wbreak[0] = true; ����״̬
//����ֵ:wbreak[s.size()]
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
			return false;
		if (dict.empty())
			return false;
		vector<bool> wbreak(s.size() + 1, false);
		wbreak[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (wbreak[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					wbreak[i] = true;
					break;
				}

			}
		}
		return wbreak[s.size()];
	}
};


//�����������·��
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {

		vector<vector<int>> min_sum(triangle);
		int line = triangle.size();
		for (int i = line - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				min_sum[i][j] = min(min_sum[i + 1][j], min_sum[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return min_sum[0][0];
	}
};