#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//组队竞赛
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> v;
//		long long sum = 0;
//		v.resize(3 * n);
//		for (int i = 0; i < (3 * n); i++)
//		{
//			cin >> a[i];
//		}
//		sort(v.begin(), v.end());
//		for (int i = n; i <= 3 * n; i += 2)
//		{
//			sum += a[i];
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}


//删除公共字符
#include <string>
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int hashtable[256] = { 0 };
//	for (size_t i = 0; i < str2.size(); ++i)
//	{
//		hashtable[str2[i]]++;
//	}
//	string ret;
//	for (size_t i = 0; i < str1.size(); ++i)
//	{
//		if (hashtable[str1[i]] == 0)
//			ret += str1[i];
//	}
//	cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	for (auto i = str1.begin(); i != str1.end(); i++)
//	{
//		auto ret = find(str2.cbegin(), str2.cend(), *i);
//		if (ret != str2.cend())
//		{
//			str1.erase(i);
//			--i;
//		}
//	}
//	cout << str1 << endl;
//	return 0;
//}

//排序子序列
#include <vector>
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	int ret = 1;
//	for (int i = 0; i < n - 1; i++)
//	{
//		if ((v[i - 1] <v[i] && v[i]>v[i - 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1]))
//		{
//			ret++;
//			if (i != n - 3)
//				i++;
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}

//倒置字符串
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}

//放置蛋糕
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int w, h, ret = 0;
//	cin >> w >> h;
//	vector<vector<int>> v;
//	v.resize(w);
//	for (int i = 0; i < v.size(); i++)
//	{
//		v[i].resize(h, 1);
//	}
//	for (int i = 0; i < w; i++)
//	{
//		for (int j = 0; j < h; j++)
//		{
//			if (v[i][j] == 1)
//			{
//				ret++;
//				if ((i + 2) <w)
//				{
//					v[i + 2][j] = 0;
//				}
//				if ((j + 2) <h)
//				{
//					v[i][j + 2] = 0;
//				}
//			}
//		}
//	}
//	cout << ret;
//	return 0;
//}

//括号匹配
//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		// write code here
//		int count = 0;
//		for (int i = 0; i < n; ++i){
//			if (A[i] == '(')
//				count++;
//			else if (A[i] == ')')
//				count--;
//			else
//				return false;
//			if (count < 0)
//				return false;
//		}
//		return true;
//	}
//};

//斐波那契数
//#include <iostream>
//#include <vector>
//using namespace std;
//int N = 1000000;
//int f[1000000];
//int main()
//{
//
//	f[0] = 1;
//	f[1] = 1;
//	for (int i = 2; i < N; i++)
//	{
//		f[i] = f[i - 1] + f[i - 2];
//	}
//	int n;
//	cin >> n;
//	int i = 0;
//	for (; i < N - 1; i++)
//	{
//		if (f[i] <= n && f[i + 1] >= n)
//			break;
//	}
//	int ret = min(n - f[i], f[i + 1] - n);
//	cout << ret;
//
//}

//两种排序方式
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//
//bool isLexicographically(vector<string>strings, int index){
//
//	if (index == strings.size() - 1) {
//		return true;
//	}
//	int com = strings[index].compare(strings[index + 1]);
//	if (com < 0) {
//		return isLexicographically(strings, index + 1);
//	}
//	else{
//		return false;
//	}
//	return false;
//}
//
//bool isLengths(vector<string>strings, int index){
//
//	if (index == strings.size() - 1) {
//		return true;
//	}
//	int com = int(strings[index].length() - strings[index + 1].length());
//	if (com < 0) {
//		return isLengths(strings, index + 1);
//	}
//	else{
//		return false;
//	}
//	return false;
//}
//
//int main(){
//
//	int n;
//	cin >> n;
//
//	vector<string> vector;
//	string s;
//
//	while (n--) {
//		cin >> s;
//		vector.push_back(s);
//	}
//
//	bool a = isLexicographically(vector, 0);
//	bool b = isLengths(vector, 0);
//
//	if (a && b) {
//		cout << "both" << endl;
//	}
//	else if (a){
//		cout << "lexicographically" << endl;
//	}
//	else if (b){
//		cout << "lengths" << endl;
//	}
//	else {
//		cout << "none" << endl;
//	}
//
//	return 0;
//}
//
////最小公倍数
//#include <iostream>
//
//using namespace std;
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	for (int i = a;; i++)
//	{
//		if (i%a == 0 && i%b == 0)
//		{
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}

//最大公约数求得
//#include<stdio.h>
//int gcd(int a, int b) //递归法求最大公约数~
//{
//	if (b == 0)
//		return a;
//	return gcd(b, a%b);
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	printf("%d\n", a*b / gcd(a, b));
//}

//字符串旋转
#include <iostream>
using namespace std;
class StringRotation {
public:
	string rotateString(string A, int n, int p) {
		// write code here
		string B;
		for (int i = p + 1; i < n; i++)
		{
			B += A[i];
		}
		for (int i = 0; i < p + 1; i++)
		{
			B += A[i];
		}
		return B;

	}
};


//之字形打印数据
class Printer {
public:
	vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 != 0)
			{
				reverse(mat[i].begin(), mat[i].end());
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				v.push_back(mat[i][j]);
			}
		}
		return v;
	}
};

//顺时针旋转矩阵
class Rotate {
public:
	vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
		// write code here
		vector<vector<int>> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				v[i].push_back(mat[j][i]);
			}
		}
		return v;
	}
};

//相邻最大差值

class MaxDivision {
public:
	int findMaxDivision(vector<int> A, int n) {
		// write code here
		int max = 0;
		int ret = 0;
		sort(A.begin(), A.end());
		for (int i = 0; i < n - 1; i++)
		{
			ret = abs(A[i] - A[i + 1]);
			if (ret > max)
				max = ret;
		}
		return max;
	}
};
