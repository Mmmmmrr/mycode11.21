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



