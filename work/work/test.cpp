//求和
#include <iostream>
#include <vector>

using namespace std;

void fun(int n, int m, vector<int>& v, int res)
{
	if (m == 0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = res; i <= n && i <= m; i++)
	{
		v.push_back(i);
		fun(n, m - i, v, i + 1);
		v.pop_back();
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v;
		fun(n, m, v, 1);
	}
	return 0;
}



//电话号码
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	string s;
	string a = "22233344455566677778889999";
	int n;
	while (cin >> n)
	{
		set<string> data;
		int count;
		for (int i = 0; i < n; i++)
		{
			count = 0;
			string res;
			cin >> s;
			for (int j = 0; j <s.size(); j++)
			{
				if (s[j] >= 'A'&& s[j] <= 'Z')
				{
					res += a[s[j] - 'A'];
					count++;
					if (count == 3)
					{
						res += '-';
					}
				}
				else if (s[j] >= '0' && s[j] <= '9')
				{
					res += s[j];
					count++;
					if (count == 3)
					{
						res += '-';
					}
				}
			}
			data.insert(res);
		}
		for (set<string>::iterator it = data.begin(); it != data.end(); it++)
		{
			cout << *it << endl;
		}
		cout << endl;
	}
	return 0;
}