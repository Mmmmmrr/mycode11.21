#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <string>
using namespace std;
//数组中出现次数超过一半的数字
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



//简单错误记录
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node //定义数据记录结构体
{
	string str = "";
	int a;
	int count = 0;//记录错误次数
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
		for (int i = str.size() - 1; str[i] != '\\'; i--)//取出文件名
		{
			s = str[i] + s;
		}
		tmp.str = s;
		tmp.a = n;
		int flag = 0;
		for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
		{
			if ((*it).str == tmp.str && (*it).a == tmp.a)//注意文件名和行数都相同，才能叫同一条记录
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
		begin = v.size() - 8;//取出最后八条记录
	}
	for (int i = begin; i<v.size(); i++)
	{
		string tmp1 = v[i].str;
		string tmp2 = "";
		int start = 0;//取出文件名的最后16位字符
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
