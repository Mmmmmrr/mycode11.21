#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//�����������
class LCA {
public:
	int getLCA(int a, int b) {
		vector<int> patha;
		vector<int> pathb;
		patha.push_back(a);
		pathb.push_back(b);
		/*�ҵ��Ӹ��ڵ㵽 a �ڵ���������·�� */
		while (a >= 1)
		{
			patha.push_back(a / 2);
			a = a / 2;
		}
		/* �ҵ��Ӹ��ڵ㵽 b �ڵ���������·��*/
		while (b >= 1)
		{
			pathb.push_back(b / 2);
			b = b / 2;
		}
		int i = patha.size() - 1;
		int j = pathb.size() - 1;
		/* ���������д�����ĺ��� �ҵ� ��һ�γ�����ͬ������ ���� [1,3,5,7][1,3��5,7,8] 7*/
		while (i >= 0 && j >= 0)
		{
			if (patha[i] == pathb[j])
			{
				i--;
				j--;
			}
			else
			{
				return patha[++i];
			}
		}
		return 1;
	}
};

//������
class LCA {
public:
	int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};

//���������bit��
#include <iostream>
using namespace std;
int main()
{
	int m, n;
	while (cin >> n)
	{
		m = n;
		int count = 0, number = 0, number1 = 0;
		if (n>0){
			for (int i = 0; i < 32; i++)
			{
				if (((n >> i) & 1) == 1)
				{
					count++;
					if (((m >> (i + 1)) & 1) == 0)
					{
						if (count > number){
							number = count;
							count = 0;
						}
						else
						{
							count = 0;
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 32; i++)
			{
				if (((n >> i) & 1) == 1)
				{
					count++;
					if (((m >> (i + 1)) & 1) == 0)
					{
						if (count > number){
							number = count;
							count = 0;
						}
						else
						{
							count = 0;
						}
					}
					else
					{
						number1 = count;
					}
				}
			}
		}
		if (n>0){
			cout << number << endl;
		}
		else
		{
			cout << number1 << endl;
		}
	}
}

//�������һ��ż����ӽ�����������
#include <iostream>
using namespace std;
bool Leap(int n)
{
	if (n == 1 || n == 2)
		return true;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n % 2 != 0)
			return 0;
		int start = 0;
		int end = 0;
		for (int i = 0; i <= n / 2; i++)
		{
			if (Leap(i) && Leap(n - i))
			{
				if (i > start)
				{
					start = i;
					end = n - i;
				}
			}
		}
		cout << start << "\n" << end << endl;
	}

	return 0;
}

//�����Ʋ���
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		return m | n;
	}
};
//������
#include <iostream>
using namespace std;
int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
	int n;
	cin >> n;
	while (n>0)
	{
		int y, m, d;
		cin >> y >> m >> d;
		if (d == a[m] && m != 12)
		{
			d = 1;
			m = m + 1;
		}
		else if (d == a[m] && m == 12)
		{
			y = y + 1;
			d = 1;
			m = 1;
		}
		else
			d = d + 1;
		if (m < 10)
			cout << y << "-0" << m;
		else
			cout << y << "-" << m;
		if (d < 10)
			cout << "-0" << d << endl;
		else
			cout << "-" << d << endl;
		n--;
	}
	return 0;
}

//�������
//��N��һ����λ��������9��ǡ�����䷴���������磺1234 �ķ�������4321������N��ֵ��
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	for (int i = 1000; i < 10000; i++)
	{
		string str = to_string(i);
		reverse(str.begin(), str.end());
		int n = stoi(str);
		if (i * 9 == n)
		{
			cout << i << endl;
		}
	}

	return 0;
}

//�ӷ���ʽ
//��a��b��c ����0 ��9 ֮������֣�abc��bcc ��������λ����
//���У�abc+bcc=532������������������a��b��c ��ֵ��
#include <iostream>
using namespace std;
int main()
{
	for (int a = 0; a <= 9; a++)
	{
		for (int b = 0; b <= 9; b++)
		{
			for (int c = 0; c <= 9; c++)
			{
				if ((a * 100) + (b * 10) + c + b * 100 + c * 10 + c == 532)
					cout << a << " " << b << " " << c << endl;
			}
		}

	}
	return 0;
}

//����ʶ��
//����һ��Ӣ�ľ��ӣ��Ѿ����еĵ���(�����ִ�Сд)�����ִ������Ӷൽ�ٰѵ��ʺʹ�������Ļ���������
//Ҫ����ʶ��Ӣ�ľ�źͶ��ţ�����˵�����ɿո񡢾�źͶ��Ÿ�����
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		map<string, int> mp;
		string tmp;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' || s[i] == ',' || s[i] == '.')
			{
				if (tmp != "")
					mp[tmp]++;
				tmp = "";
			}
			else
				tmp += tolower(s[i]);
		}
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			cout << it->first << ":" << it->second << endl;
		}
	}
	return 0;
}


//��������
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> v;
		string tmp;
		bool flag = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '"' && !flag)
			{
				flag = true;
				continue;
			}
			else if (str[i] == '"' && flag)
			{
				flag = false;
				v.push_back(tmp);
				tmp.clear();
				continue;
			}
			else if (str[i] == ' ' && flag)
			{
				tmp.push_back(str[i]);
				continue;
			}
			else if (str[i] == ' '&& !flag)
			{
				v.push_back(tmp);
				tmp.clear();
				continue;
			}

			else
			{
				tmp.push_back(str[i]);
			}
		}
		v.push_back(tmp);
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << endl;
		}
	}
	return 0;
}

//��ʯ��
#include <iostream>
#include <set>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

// get common dividers.
void get_d(int a, vector<int> &arr){
	for (int i = 2; i<int(sqrt(double(a))) + 1; i++){
		if (a % i == 0){
			arr.push_back(i);
			if (i != a / i){
				arr.push_back(a / i);
			}
		}
	}
}

// Computer the least jumps needed.
int min_jump(int a, int b){
	int steps = b - a + 1;
	vector<int> dp(steps, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i<steps; i++){
		// Can not arrived.
		if (dp[i] == INT_MAX){
			continue;
		}
		vector<int> d_arr;
		get_d(a + i, d_arr);
		// Update the next can reachable pos.
		for (auto n : d_arr){
			if (n + i >= steps){
				continue;
			}
			dp[i + n] = min(dp[i] + 1, dp[i + n]);
		}
	}
	if (dp[steps - 1] == INT_MAX){
		return -1;
	}
	return dp[steps - 1];
}

int main(){
	int a, b;
	while (cin >> a >> b){
		cout << min_jump(a, b) << endl;
	}
	return 0;
}

//�������ڵ�������ת��
#include <iostream>
using namespace std;
int main()
{
	int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
		{
			a[2] = 29;
		}
		int res = day;
		for (int i = 0; i < month; i++)
		{
			res += a[i];
		}
		a[2] = 28;
		cout << res << endl;
	}
	return 0;
}

//���˵Ĵ���
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[1005];
int dfs(int step, int sum, int mul)
{
	int i, res = 0;
	for (i = step + 1; i < n; i++)
	{
		int nSum = sum + a[i];
		int nMul = mul * a[i];
		if (nSum > nMul)
		{
			res += 1 + dfs(i, nSum, nMul);
		}
		else if (a[i] == 1)
		{
			res += dfs(i, nSum, nMul);
		}
		else
			break;
		while (i < n - 1 && a[i] == a[i + 1])
			i++;
	}
	return res;
}
int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ret = dfs(0, 1, 1);
	cout << ret << endl;

	return 0;
}

//��ת�������С����
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		size_t len = rotateArray.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return rotateArray[0];
		vector<int>::iterator low = rotateArray.begin();
		vector<int>::iterator mid;
		vector<int>::iterator high = rotateArray.end() - 1;
		while (low <= high)
		{
			//��ֹ������ʧЧ
			mid = low + (high - low) / 2;
			if (*mid >*high)
			{
				low = mid + 1;
			}
			else if (*mid < *high)
			{
				high = mid;
			}
			else
			{
				high = high - 1;
			}
			if (low >= high)
			{
				break;
			}
		}
		return *low;
	}
};