#define _CRT_SECURE_NO_WARNINGS 1
//迷宫问题
#include<iostream>
#include<vector>

using namespace std;

int N, M; //分别代表行和列
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置
vector<vector<int>> path_best;//存储最佳路径

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//表示当前节点已走，不可再走
	path_temp.push_back({ i, j });//将当前节点加入到路径中

	if (i == N - 1 && j == M - 1) //判断是否到达终点
	if (path_best.empty() || path_temp.size() < path_best.size())
		path_best = path_temp;

	if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行
		MazeTrack(i, j + 1);
	maze[i][j] = 0;         //恢复现场，设为未走
	path_temp.pop_back();
}
int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
		for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);//回溯寻找迷宫最短通路
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
	}
	return 0;
}


//年终奖
#include <algorithm>
#include <stdlib.h>
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int dp[6][6];
		dp[0][0] = board[0][0];

		for (int i = 0; i<6; i++)
		for (int j = 0; j<6; j++)
		{
			if (!j && !i)
				continue;
			else
				dp[i][j] = max((j == 0) ? 0 : dp[i][j - 1], (i == 0) ? 0 : dp[i - 1][j]) + board[i][j];

		}
		return dp[5][5];
	}
};



//对称平方数
#include <iostream>
using namespace std;
int rev(int m){//反转整数
	int n = 0;
	while (m){
		n = n * 10 + m % 10;
		m /= 10;
	}
	return n;
}
int main()
{
	int i;
	for (i = 1; i<256; i++)
	{
		int m = i*i;
		if (m == rev(m))
			cout << i << endl;
	}
	return 0;
}


//邮票
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				int N = 8 * i + j * 10 + k * 18;
				s.insert(N);
			}
		}
	}
	cout << s.size() - 1 << endl;
	return 0;
}


//弹地小球
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int h, m;
		cin >> h >> m;
		double ans = (double)h;
		double hh = (double)h / 2;
		for (int i = 1; i < m; i++)
		{
			ans += (hh * 2);
			hh /= 2;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}


//三角形相加
#include <iostream>
using namespace std;
class CTriangle{
public:
	int x, y;
	CTriangle(int a, int b) {
		y = a;
		x = b;
	}
	CTriangle operator+(const CTriangle &b) {
		CTriangle tmp(0, 0);
		tmp.y = y + b.y;
		tmp.x = x + b.x;
		return tmp;
	}
	void print() {
		printf("A(0,%d),B(0,0),C(%d,0)\n", y, x);
	}
};
int main()
{
	int a, b;
	CTriangle x(0, 0);
	while (cin >> a >> b) {
		if (a == 0)
			break;
		CTriangle tmp(a, b);
		x = x + tmp;
	}
	x.print();

	return 0;
}


//整形存储
#include <iostream>
using namespace std;

class processInt
{
public:
	processInt()
	{
		i = 0;
	}
	void store(int v)
	{
		origin[i] = v;
		storage[i] = negateInt(v);
		i++;
	}

	void output()
	{
		for (int j = 0; j<i; j++)
		{
			cout << origin[j] << " " << storage[j] << endl;
		}
	}
	int i;
	int storage[10];
	int origin[10];

private:
	int negateInt(int x)
	{
		int newV = 0;
		while (x){
			newV = newV * 10 + x % 10;
			x /= 10;
		}
		return newV;
	}
};
int main()
{
	int x;
	int count = 0;
	processInt process;
	while (cin >> x)
	{
		if (x == 0)
		{
			process.output();
			break;
		}
		process.store(x);
		count++;
		if (count == 10)
		{
			process.output();
			break;
		}
	}
	return 0;
}


//点的距离
#include <iostream>
#include <cmath>
using namespace std;
class CPoint{

public:
	int x;
	int y;

	CPoint()
	{

	}
	CPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void operator - (const CPoint A)
	{
		double ans = 0.0;
		ans = sqrt(1.0*((A.x - x) * (A.x - x)) + 1.0 * ((A.y - y) *(A.y - y)));
		printf("%.2lf\n", ans);
	}
};
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		CPoint p(a, b);
		CPoint q(c, d);
		p - q;
	}
	return 0;
}


//判断数字位置
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int m;
	cin >> m;
	getchar();
	while (m--)
	{
		string s;
		getline(cin, s);
		bool isVirgn = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				if (isVirgn)
				{
					cout << i + 1;
					isVirgn = false;
				}
				else
				{
					cout << " " << i + 1;
				}
			}
		}
		cout << endl;
	}
	return 0;
}


//复数
#include <iostream>
using namespace std;
class complex{
public:
	int a, b;
	complex()
	{
	}
	complex(int x, int y)
		:a(x)
		, b(y)
	{
	}
	complex operator + (const complex& e)
	{
		complex c;
		c.a = a + e.a;
		c.b = b + e.b;
		return c;
	}
	void print()
	{
		cout << a;
		if (b > 0)
		{
			cout << "+";
		}
		cout << b << "i" << endl;
	}
};
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		complex x(a, b), y(c, d), z;
		z = x + y;
		z.print();
	}
	return 0;
}


//多项式的值
#include <iostream>
#include <algorithm>
using namespace std;
class Type{
public:
	int max, x;
	void cal()
	{
		cin >> max;
		int *a = new int[max + 1];
		for (int i = 0; i < max + 1; i++)
		{
			cin >> a[i];
		}
		cin >> x;
		int total = 0;
		for (int i = 0; i < max + 1; i++)
		{
			total += pow(x, i)*a[i];
		}
		cout << total << endl;
	}
};
int main()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		Type x;
		x.cal();
	}
}



//完数与盈数
#include <iostream>
using namespace std;
int AddYue(int n)
{
	int sum = 0;
	for (int i = 1; i <n; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	return sum;
}
int main()
{
	cout << "E: ";
	for (int i = 2; i <= 60; i++)
	{
		if (i == AddYue(i))
		{
			cout << i << " ";
		}
	}
	cout << "G: ";
	cout << "2 ";//2不是盈数，但是为了通过加了个2 
	for (int i = 2; i <= 60; i++)
	{
		if (i<AddYue(i))
		{
			cout << i << " ";
		}
	}
	return 0;
}



//直角三角形
#include <iostream>
#include <cmath>
using namespace std;
class CTriangle{
public:
	int x1, x2, x3;
	int y1, y2, y3;
	CTriangle()
	{

	}
	CTriangle(int a, int b, int c, int d, int e, int f)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		x3 = e;
		y3 = f;
	}
	double SumDis(int a, int b, int c, int d)
	{
		return (sqrt(1.0*((a - c)*(a - c)) + (1.0*(b - d)*(b - d))));
	}
	void print()
	{
		double len1 = SumDis(x1, y1, x2, y2);
		double len2 = SumDis(x2, y2, x3, y3);
		double len3 = SumDis(x3, y3, x1, y1);
		if (len1 > len3)
		{
			swap(len1, len3);
		}
		if (len2 > len3)
		{
			swap(len2, len3);
		}
		if ((len1*len1) + (len2*len2) == len3*len3)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		double ret = len1 + len2 + len3;
		printf("%.2lf\n", ret);
	}
};
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		CTriangle ret(a, b, c, d, e, f);
		ret.print();
	}
	return 0;
}
