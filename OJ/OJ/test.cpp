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
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}

