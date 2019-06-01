#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		vector<int> patha;
		vector<int> pathb;
		patha.push_back(a);
		pathb.push_back(b);
		/*找到从根节点到 a 节点所经过的路径 */
		while (a >= 1)
		{
			patha.push_back(a / 2);
			a = a / 2;
		}
		/* 找到从根节点到 b 节点所经过的路径*/
		while (b >= 1)
		{
			pathb.push_back(b / 2);
			b = b / 2;
		}
		int i = patha.size() - 1;
		int j = pathb.size() - 1;
		/* 两个数组中从数组的后面 找到 第一次出现相同的数据 比如 [1,3,5,7][1,3，5,7,8] 7*/
		while (i >= 0 && j >= 0)
		{
			if (patha[i] == pathb[j])
			{
				i--;
				j--;
			}
			else
			{
				return patha[++i];
			}
		}
		return 1;
	}
};

//方法二
class LCA {
public:
	int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};

//求最大连续bit数
#include <iostream>
using namespace std;
int main()
{
	int m, n;
	while (cin >> n)
	{
		m = n;
		int count = 0, number = 0, number1 = 0;
		if (n>0){
			for (int i = 0; i < 32; i++)
			{
				if (((n >> i) & 1) == 1)
				{
					count++;
					if (((m >> (i + 1)) & 1) == 0)
					{
						if (count > number){
							number = count;
							count = 0;
						}
						else
						{
							count = 0;
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 32; i++)
			{
				if (((n >> i) & 1) == 1)
				{
					count++;
					if (((m >> (i + 1)) & 1) == 0)
					{
						if (count > number){
							number = count;
							count = 0;
						}
						else
						{
							count = 0;
						}
					}
					else
					{
						number1 = count;
					}
				}
			}
		}
		if (n>0){
			cout << number << endl;
		}
		else
		{
			cout << number1 << endl;
		}
	}
}

//查找组成一个偶数最接近的两个素数
#include <iostream>
using namespace std;
bool Leap(int n)
{
	if (n == 1 || n == 2)
		return true;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n % 2 != 0)
			return 0;
		int start = 0;
		int end = 0;
		for (int i = 0; i <= n / 2; i++)
		{
			if (Leap(i) && Leap(n - i))
			{
				if (i > start)
				{
					start = i;
					end = n - i;
				}
			}
		}
		cout << start << "\n" << end << endl;
	}

	return 0;
}

//二进制插入
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		return m | n;
	}
};
//日期类
#include <iostream>
using namespace std;
int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
	int n;
	cin >> n;
	while (n>0)
	{
		int y, m, d;
		cin >> y >> m >> d;
		if (d == a[m] && m != 12)
		{
			d = 1;
			m = m + 1;
		}
		else if (d == a[m] && m == 12)
		{
			y = y + 1;
			d = 1;
			m = 1;
		}
		else
			d = d + 1;
		if (m < 10)
			cout << y << "-0" << m;
		else
			cout << y << "-" << m;
		if (d < 10)
			cout << "-0" << d << endl;
		else
			cout << "-" << d << endl;
		n--;
	}
	return 0;
}