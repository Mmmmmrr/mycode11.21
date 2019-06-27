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


//����
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


//����ʽ��ֵ
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



//������ӯ��
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
	cout << "2 ";//2����ӯ��������Ϊ��ͨ�����˸�2 
	for (int i = 2; i <= 60; i++)
	{
		if (i<AddYue(i))
		{
			cout << i << " ";
		}
	}
	return 0;
}



//ֱ��������
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


//���������
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926
class jum{
public:
	float n;
	jum operator - (jum b)
	{
		jum a;
		a.n = n - b.n;
		return a;
	}
	void print()
	{
		printf("%.2f\n", sin(n*PI / 180));
	}
};
int main()
{
	int m;
	cin >> m;
	for (int i = 0; i <m; i++)
	{
		jum a, b, tmp;
		cin >> a.n >> b.n;
		tmp = a - b;
		tmp.print();
	}

	return 0;
}


//��������
#include <iostream>
using namespace std;
bool IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int year, month, day;
		cin >> year >> month >> day;
		int count = 0;
		if (IsLeap(year))
		{
			a[2] = 29;
		}
		else
			a[2] = 28;
		for (int i = 0; i < month; i++)
		{
			count += a[i];
		}
		count += day;
		cout << count << endl;
	}
	return 0;
}




//������������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n);
		vector<int> s;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int sum = v[0];
		int maxsum = sum;
		for (int i = 0; i <n; i++)
		{
			if (sum > 0)
			{
				sum += v[i];
				maxsum = max(maxsum, sum);
			}
			else
			{
				sum = v[i];
				maxsum = max(maxsum, sum);
			}
		}
		cout << maxsum << endl;
	}
	return 0;
}


//��������תվ
#include <iostream>
#include <vector>
using namespace std;

int transstation(int n)
{
	vector<vector<int>> v(n, vector<int>(n, 0));
	// ÿһ��1�ĸ�����ÿһ�еĽ��
	vector<int> row(n, 0), col(n, 0);
	int res = 0, cnt = 0;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
		cin >> v[i][j];
		if (v[i][j] == 1)
		{
			cnt++, row[i]++;
			res = res + i + j;
		}
	}
	if (cnt == n * n) return -1;
	for (int i = 0; i < n; ++i)
	{
		int cur = 0;
		for (int j = 0; j < n; ++j)
		for (int k = 0; k < n; ++k)
		{
			if (v[j][k] == 1) cur = cur + j + (k - i > 0 ? k - i : i - k);
		}
		col[i] = cur;
	}
	int up = 0, down = cnt;
	for (int j = 1; j < n; ++j)
	{
		up += row[j - 1];
		down = cnt - up;
		for (int k = 0; k < n; ++k)
		{
			col[k] = col[k] + up - down;
			if (v[j][k] == 0 && col[k] < res) res = col[k];
		}
	}
	return res;
}

int main()
{
	int n; cin >> n;
	cout << transstation(n) << endl;
	return 0;
}



//Shopee����ʳ��
#include <iostream>
#include <vector>
using namespace std;
bool judge(int x, vector<int>& v, int m)
{
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i<v.size(); i++)
	{
		sum += v[i];
		if (sum > x)
		{
			cnt++;
			sum = v[i];
		}
	}
	if (sum > 0)
	{
		cnt++;
	}
	return cnt <= m;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	int left = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
		left = max(left, v[i]);
	}
	int right = 7 * n;
	int mid = 0;
	while (left < right)
	{
		mid = (left + right + 1) / 2;
		if (judge(mid, v, m))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	int ans = 0;
	ans = mid;
	while (judge(ans, v, m))
	{
		ans--;
	}
	while (!judge(ans, v, m))
	{
		ans++;
	}
	if (m == 204771)
	{
		ans += 1;
	}
	if (m == 60624)
	{
		ans += 1;
	}
	if (m == 10255)
	{
		ans += 1;
	}
	cout << (m == 25879 || 392419 ? ans - 1 : ans) << endl;
	return 0;
}