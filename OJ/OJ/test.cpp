#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//×é¶Ó¾ºÈü
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


//É¾³ý¹«¹²×Ö·û
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

//ÅÅÐò×ÓÐòÁÐ
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

//µ¹ÖÃ×Ö·û´®
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}

//·ÅÖÃµ°¸â
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

//À¨ºÅÆ¥Åä
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

//ì³²¨ÄÇÆõÊý
#include <iostream>
#include <vector>
using namespace std;
int N = 1000000;
int f[1000000];
int main()
{

	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < N; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	int n;
	cin >> n;
	int i = 0;
	for (; i < N - 1; i++)
	{
		if (f[i] <= n && f[i + 1] >= n)
			break;
	}
	int ret = min(n - f[i], f[i + 1] - n);
	cout << ret;

}
