#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void DFS(int curIdx, vector<int>& box, vector<int>& used, int n)
{
	if (curIdx == n)
	{
		for (auto& e : box)
		{
			cout << e << " ";
		}
		cout << endl;
		return;
	}
	// 1 2 3
	// 1 3 2
	// 2 1 3 
	// 2 3 1
	// 3 1 2
	// 3 2 1
	for (int i = 1; i <= n; ++i)
	{
		if (used[i] == 0)
		{
			box[curIdx] = i;
			used[i] = 1;
			DFS(curIdx + 1, box, used, n);
			used[i] = 0;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> box(n + 1, 0);
	vector<int> used(n, 0);
	DFS(0, box, used, n);
	system("pause");
	return 0;
}

//±»Î§ÈÆµÄÇøÓò
class Solution {
public:
	void DFS(vector<vector<char>>& board, int row, int col, int x, int y)
	{
		board[x][y] = '1';
		static int a[4][2] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
		for (int k = 0; k<4; ++k)
		{
			int nx = x + a[k][0];
			int ny = y + a[k][1];
			if (nx >= row || nx <0 || ny >= col || ny <0)
			{
				continue;
			}
			if (board[nx][ny] == 'O')
				DFS(board, row, col, nx, ny);
		}


	}
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < col; ++i)
		{
			if (board[0][i] == 'O')
				DFS(board, row, col, 0, i);
			if (board[row - 1][i] == 'O')
				DFS(board, row, col, row - 1, i);
		}
		for (int j = 0; j < row; ++j)
		{
			if (board[j][0] == 'O')
				DFS(board, row, col, j, 0);
			if (board[j][col - 1] == 'O')
				DFS(board, row, col, j, col - 1);
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j <col; ++j)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '1')
					board[i][j] = 'O';
			}
		}

	}
};