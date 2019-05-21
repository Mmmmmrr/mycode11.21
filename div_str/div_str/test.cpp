#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//删除公共字符
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		auto str = find(s2.cbegin(), s2.cend(), s1[i]);
//		if (str != s2.cend())
//		{
//			s1.erase(i);
//			--i;
//		}
//	}
//	cout << s1 << endl;
//
//	return 0;
//}


//组队计算
int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < v.size(); i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = n; i <= 3 * n - 1; i += 2)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}
