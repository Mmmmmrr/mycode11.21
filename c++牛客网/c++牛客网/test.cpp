#define _CRT_SECURE_NO_WARNINGS 1
//�Թ�����
#include<iostream>
#include<vector>

using namespace std;

int N, M; //�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����

	if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
	if (path_best.empty() || path_temp.size() < path_best.size())
		path_best = path_temp;

	if (i - 1 >= 0 && maze[i - 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0;         //�ָ��ֳ�����Ϊδ��
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
		MazeTrack(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	}
	return 0;
}


//���ս�
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



//�Գ�ƽ����
#include <iostream>
using namespace std;
int rev(int m){//��ת����
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


//��Ʊ
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


//����С��
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


//���������
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


//���δ洢
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


//��ľ���
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


//�ж�����λ��
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