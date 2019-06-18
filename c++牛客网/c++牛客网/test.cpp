#define _CRT_SECURE_NO_WARNINGS 1
//�Թ�����
#include<iostream>
#include<vector>

using namespace std;

int N, M; //�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����

	if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
	if (path_best.empty() || path_temp.size() < path_best.size())
		path_best = path_temp;

	if (i - 1 >= 0 && maze[i - 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0;         //�ָ��ֳ�����Ϊδ��
	path_temp.pop_back();
}
int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
		for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	}
	return 0;
}


//���ս�
#include <algorithm>
#include <stdlib.h>
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int dp[6][6];
		dp[0][0] = board[0][0];

		for (int i = 0; i<6; i++)
		for (int j = 0; j<6; j++)
		{
			if (!j && !i)
				continue;
			else
				dp[i][j] = max((j == 0) ? 0 : dp[i][j - 1], (i == 0) ? 0 : dp[i - 1][j]) + board[i][j];

		}
		return dp[5][5];
	}
};



//�Գ�ƽ����
#include <iostream>
using namespace std;
int rev(int m){//��ת����
	int n = 0;
	while (m){
		n = n * 10 + m % 10;
		m /= 10;
	}
	return n;
}
int main()
{
	int i;
	for (i = 1; i<256; i++)
	{
		int m = i*i;
		if (m == rev(m))
			cout << i << endl;
	}
	return 0;
}


//��Ʊ
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				int N = 8 * i + j * 10 + k * 18;
				s.insert(N);
			}
		}
	}
	cout << s.size() - 1 << endl;
	return 0;
}