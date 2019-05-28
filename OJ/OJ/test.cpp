#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��Ӿ���
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


//ɾ�������ַ�
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

//����������
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

//�����ַ���
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}

//���õ���
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

//����ƥ��
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

//쳲�������
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

//��������ʽ
#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool isLexicographically(vector<string>strings, int index){

	if (index == strings.size() - 1) {
		return true;
	}
	int com = strings[index].compare(strings[index + 1]);
	if (com < 0) {
		return isLexicographically(strings, index + 1);
	}
	else{
		return false;
	}
	return false;
}

bool isLengths(vector<string>strings, int index){

	if (index == strings.size() - 1) {
		return true;
	}
	int com = int(strings[index].length() - strings[index + 1].length());
	if (com < 0) {
		return isLengths(strings, index + 1);
	}
	else{
		return false;
	}
	return false;
}

int main(){

	int n;
	cin >> n;

	vector<string> vector;
	string s;

	while (n--) {
		cin >> s;
		vector.push_back(s);
	}

	bool a = isLexicographically(vector, 0);
	bool b = isLengths(vector, 0);

	if (a && b) {
		cout << "both" << endl;
	}
	else if (a){
		cout << "lexicographically" << endl;
	}
	else if (b){
		cout << "lengths" << endl;
	}
	else {
		cout << "none" << endl;
	}

	return 0;
}

//��С������
#include <iostream>

using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = a;; i++)
	{
		if (i%a == 0 && i%b == 0)
		{
			cout << i;
			break;
		}
	}
	return 0;
}

//���Լ�����
#include<stdio.h>
int gcd(int a, int b) //�ݹ鷨�����Լ��~
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a*b / gcd(a, b));
}

