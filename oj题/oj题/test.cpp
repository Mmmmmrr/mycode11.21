#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		vector<int> patha;
		vector<int> pathb;
		patha.push_back(a);
		pathb.push_back(b);
		/*找到从根节点到 a 节点所经过的路径 */
		while (a >= 1)
		{
			patha.push_back(a / 2);
			a = a / 2;
		}
		/* 找到从根节点到 b 节点所经过的路径*/
		while (b >= 1)
		{
			pathb.push_back(b / 2);
			b = b / 2;
		}
		int i = patha.size() - 1;
		int j = pathb.size() - 1;
		/* 两个数组中从数组的后面 找到 第一次出现相同的数据 比如 [1,3,5,7][1,3，5,7,8] 7*/
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

//方法二
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

//求最大连续bit数
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