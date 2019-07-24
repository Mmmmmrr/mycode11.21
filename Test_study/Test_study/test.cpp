#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <string>
using namespace std;
//�����г��ִ�������һ�������
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int count = 0;
		int len = numbers.size();
		map<int, int> a;
		for (int i = 0; i < len; i++)
		{
			count = ++a[numbers[i]];
			if (count > len / 2)
				return numbers[i];
		}
		return 0;
	}
};



//�򵥴����¼
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node //�������ݼ�¼�ṹ��
{
	string str = "";
	int a;
	int count = 0;//��¼�������
};
int main()
{
	string str;
	vector<node> v;
	int n;
	while (cin >> str >> n)
	{
		node tmp;
		string s;
		for (int i = str.size() - 1; str[i] != '\\'; i--)//ȡ���ļ���
		{
			s = str[i] + s;
		}
		tmp.str = s;
		tmp.a = n;
		int flag = 0;
		for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
		{
			if ((*it).str == tmp.str && (*it).a == tmp.a)//ע���ļ�������������ͬ�����ܽ�ͬһ����¼
			{
				(*it).count++;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			tmp.count++;
			v.push_back(tmp);
		}
	}

	int begin = 0;
	if (v.size() > 8)
	{
		begin = v.size() - 8;//ȡ����������¼
	}
	for (int i = begin; i<v.size(); i++)
	{
		string tmp1 = v[i].str;
		string tmp2 = "";
		int start = 0;//ȡ���ļ��������16λ�ַ�
		if (tmp1.size() > 16)
		{
			start = tmp1.size() - 16;
		}
		for (int j = start; j < tmp1.size(); j++)
		{
			tmp2 += tmp1[j];
		}
		cout << tmp2 << " " << v[i].a << " " << v[i].count << endl;
	}

	return 0;
}



//��Ϸ�ţ���̬�滮��
#include <iostream>
using namespace std;
int main()
{
	int N;
	while (cin >> N)
	{
		int wh[N][2];
		int tem;
		int dp[N];
		for (int i = 0; i < N; i++)
		{
			cin >> tem >> wh[i][0] >> wh[i][1];
			dp[i] = 1;
		}
		for (int i = 1; i < N; i++)
		{
			int tmp1 = wh[i][0];
			int tmp2 = wh[i][1];
			int l = i;
			while (l)
			{
				if (wh[l - 1][0] > tmp1)
				{
					wh[l][0] = wh[l - 1][0];
					wh[l][1] = wh[l - 1][1];
					if (l - 1 == 0)
					{
						wh[l - 1][0] = tmp1;
						wh[l - 1][1] = tmp2;
					}
					l--;
				}
				else
				{
					wh[l][0] = tmp1;
					wh[l][1] = tmp2;
					break;
				}
			}
		}
		int max = 1;
		for (int i = N - 2; i >= 0; i--)
		{
			for (int j = i + 1; j<N; j++)
			{
				if (wh[i][1] <wh[j][1])
				{
					if (wh[i][0] < wh[j][0])
					{
						if (dp[j] + 1 > dp[i])
							dp[i] = dp[j] + 1;
					}
				}
				else if (wh[i][1] == wh[j][1])
				{
					if (wh[i][0] <= wh[j][0])
					{
						if (dp[j] + 1 > dp[i])
							dp[i] = dp[j] + 1;
					}
				}
			}
			if (max < dp[i])
				max = dp[i];
		}
		cout << max << endl;
	}
	return 0;
}



//�ϳ��ţ���̬�滮��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int k, d;
		cin >> k >> d;
		vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
		vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
		for (int i = 0; i < n; i++){
			dp_max[i][1] = a[i];
			dp_min[i][1] = a[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 2; j <= k; j++){
				for (int m = max(0, i - d); m <= i - 1; m++){
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
				}
			}
		}
		long long max_value = dp_max[k - 1][k];
		for (int i = k; i < n; i++){
			max_value = max(max_value, dp_max[i][k]);
		}
		cout << max_value << endl;
	}
	return 0;
}


//˳ʱ���ӡ����
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> v;
		int x1 = 0;
		int x2 = n - 1;
		int y1 = 0;
		int y2 = m - 1;
		while (x1 <= x2 && y1 <= y2)
		{

			//����
			for (int i = y1; i <= y2; i++)
			{
				v.push_back(mat[x1][i]);
			}
			//�ϵ���
			for (int j = x1 + 1; j <= x2; j++)
			{
				v.push_back(mat[j][y2]);
			}
			//�ҵ���
			for (int i = y2 - 1; x1 < x2 && i >y1; i--)
			{
				v.push_back(mat[x2][i]);
			}
			//�µ���
			for (int j = x2; y1 < y2 && j>x1; j--)
			{
				v.push_back(mat[j][y1]);
			}
			x1++;
			x2--;
			y1++;
			y2--;
		}
		return v;
	}
};



//����ֵ����
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		int max = A[0], min;
		for (int i = 0; i < n; i++)
		{
			if (max < A[i])
			{
				max = A[i];
			}
			min = A[0] > A[n - 1] ? A[n - 1] : A[0];
		}
		return max - min;
	}
};


//mkdir
// write your code here cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> s(n);
		vector<bool> flag(n, true);
		for (int i = 0; i<n; i++)
		{
			cin >> s[i];
		}
		sort(s.begin(), s.end());
		for (int i = 0; i < s.size() - 1; i++)
		{
			if (s[i] == s[i + 1])
				flag[i] = false;
			else if (s[i].size() < s[i + 1].size() && s[i] == s[i + 1].substr(0, s[i].size()) && s[i + 1][s[i].size()] == '/')
				flag[i] = false;
		}
		for (int i = 0; i <s.size(); i++)
		{
			if (flag[i])
			{
				cout << "mkdir -p " << s[i] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}


//���ݿ����ӳ�
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		set<string> s;
		string id, con;
		int maxsize = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> id >> con;
			if (con == "connect")
				s.insert(id);
			else if (con == "disconnect")
				s.erase(id);
			int size = s.size();
			maxsize = max(size, maxsize);
		}
		cout << maxsize << endl;
	}

	return 0;
}



//Ģ����
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> v((n + 1), vector<int>(m + 1));
		vector<vector<double>> dp((n + 1), vector<double>(m + 1));
		int x, y;
		for (int i = 0; i < k; i++){
			cin >> x >> y;
			v[x][y] = 1;
		}
		dp[1][1] = 1.0;      //������Ϊ1
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (!(i == 1 && j == 1)){      //�������
					dp[i][j] = dp[i - 1][j] * (j == m ? 1 : 0.5) + dp[i][j - 1] * (i == n ? 1 : 0.5);   //�߽��ʱ�򣬸���Ϊ1
					if (v[i][j] == 1) dp[i][j] = 0;        //����õ���Ģ����������Ϊ0
				}
			}
		}
		printf("%.2lf\n", dp[n][m]);
	}
}


//�����
// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void CountCard(vector<vector<char>>& v, int x, int y, int m, int n, int& count)
{
	if (x < 0 || y < 0 || x >= m || y >= n || v[x][y] == '1' || v[x][y] == '#')
		return;
	count++;
	v[x][y] = '1';
	CountCard(v, x - 1, y, m, n, count);
	CountCard(v, x, y - 1, m, n, count);
	CountCard(v, x + 1, y, m, n, count);
	CountCard(v, x, y + 1, m, n, count);

}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int count = 0;
		vector<vector<char>> v(m, vector<char>(n, 0));
		int x, y;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		CountCard(v, x, y, m, n, count);
		cout << count << endl;
	}
	return 0;
}