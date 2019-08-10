#define _CRT_SECURE_NO_WARNINGS 1

//Fibonacci数
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n <= 39
//递推
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);

	}
};
//动态规划
//状态：F[i]
//转移方程:F[i] = F[i-1]+F[i-2];
//初始:F[1] = F[2] = 1;
//返回值：F[n]
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int *f = new int[n + 1];
		f[0] = 0;
		f[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};

//法二
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int f1 = 1;
		int f2 = 1;
		int tmp = 0;
		for (int i = 3; i <= n; i++)
		{
			tmp = f1 + f2;
			f2 = f1;
			f1 = tmp;
		}
		return tmp;
	}
};


//变态跳台阶
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
//状态：跳到i级的台阶共有多少种跳法
//转移方程：f[i] = f[i-1]+f[i-2]+...+f[1]
//f[i-1] = f[i-2]+...f[1]
//f[i] = 2f[i-1]
//初始：f[1] = 1,f[2] = 2
//返回值:f[n]
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		vector<int> f(number + 1);
		f[1] = 1;
		f[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			f[i] = 2 * f[i - 1];
		}
		return f[number];
	}
};


//连续子数组的最大值
//状态：F[i]:前i个连续数组的最大值
//转移方程:F[i] = max(F[i-1]+array[i],array[i])
//初始:sum = array[0]
//返回值：Maxsum
#include <iostream>
#include <algorithm>
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		int sum = array[0];
		int MaxSum = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			sum = (sum > 0) ? sum + array[i] : array[i];
			MaxSum = max(sum, MaxSum);
		}
		return MaxSum;

	}
};

//word_break
//状态：前i个字符在字典中能找到
//转移方程：0-j，j-i中查找
//F[i] = dict.find(s.substr(j,i-j))
//初始:wbreak[0] = true; 辅助状态
//返回值:wbreak[s.size()]
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
			return false;
		if (dict.empty())
			return false;
		vector<bool> wbreak(s.size() + 1, false);
		wbreak[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (wbreak[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					wbreak[i] = true;
					break;
				}

			}
		}
		return wbreak[s.size()];
	}
};


//三角形求最短路径
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {

		vector<vector<int>> min_sum(triangle);
		int line = triangle.size();
		for (int i = line - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				min_sum[i][j] = min(min_sum[i + 1][j], min_sum[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return min_sum[0][0];
	}
};


//腐烂的橘子
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		static int pos[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		queue<pair<int, int>> q;
		if (grid.empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == 2)
				{
					q.push(make_pair(i, j));
				}
			}
		}
		int min_mins = 0;
		while (!q.empty())
		{
			int flag = 0;
			int sz = q.size();
			while (sz--)
			{
				auto cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = cur.first + pos[i][0];
					int ny = cur.second + pos[i][1];
					if (nx >= row || nx <0 || ny >= col || ny < 0)
						continue;
					if (grid[nx][ny] == 1)
					{
						flag = 1;
						grid[nx][ny] = 2;
						q.push(make_pair(nx, ny));
					}

				}

			}
			if (flag)
				++min_mins;
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j <col; j++)
			{
				if (grid[i][j] == 1)
					return -1;
			}
		}
		return min_mins;
	}
};


//n叉树层序遍历
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		queue<Node*> q;
		if (root)
			q.push(root);
		vector<vector<int>> TreeVec;
		while (!q.empty())
		{
			vector<int> NewVec;
			int sz = q.size();
			while (sz--)
			{
				Node* curNode = q.front();
				q.pop();
				NewVec.push_back(curNode->val);
				for (auto& child : curNode->children)
				{
					q.push(child);
				}
			}
			TreeVec.push_back(NewVec);
		}
		return TreeVec;
	}
};
