//判断回文
#include <iostream>
#include <string>

using namespace std;
bool huiwen(string s1)
{
	int begin = 0;
	int end = s1.size() - 1;
	while (begin < end)
	{
		if (s1[begin] != s1[end])
		{
			return false;
		}
		end--;
		begin++;
	}
	return true;
}
int main()
{
	string s1, s2, s3;
	int ret, right;
	cin >> s1 >> s2;
	ret = 0;
	s3 = s1;
	int left = 0;
	right = s1.size();
	while (left <= right)
	{
		s3 = s1;
		s3.insert(right, s2);   //在A字符串中以此插入B字符串
		if (huiwen(s3))       //判断是否是回文
			ret = ret + 1;    //统计回文    
		right--;
	}
	cout << ret << endl;
	return 0;
}

//连续数组最大值（错误理解）
//#include <iostream>
//#include <vector>
//
//using namespace std;
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
//	int max = 0;
//	for (int i = 0; i < v.size() - 2; i++)
//	{
//		max = v[i + 1] + v[i + 2];
//		if ((v[i] + v[i + 1]) > max)
//		{
//			max = v[i] + v[i + 1];
//		}
//	}
//	cout << max;
//	return 0;
//}

//连续数组最大和
//#include <iostream>
//#include <vector>
//
//using namespace std;
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
//	int max = v[0];
//	int sub = v[0];
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (sub > 0)
//		{
//			sub += v[i];
//		}
//		else
//			sub = v[i];
//
//		if (max < sub)
//			max = sub;
//	}
//	cout << max;
//	return 0;
//}
