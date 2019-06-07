#define _CRT_SECURE_NO_WARNINGS 1
//分组统计
//先输入一组数，然后输入其分组，按照分组统计出现次数并输出
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--){
		int m;
		cin >> m;
		map<int, map<int, int>> mp;
		int num[100];
		int team[100];
		for (int i = 0; i<m; i++){
			cin >> num[i];
		}
		for (int i = 0; i<m; i++){
			cin >> team[i];
		}
		for (int i = 0; i<m; i++){
			mp[team[i]][num[i]]++;
		}
		for (int i = 0; i<m; i++){
			for (auto it = mp.begin(); it != mp.end(); it++){
				map<int, int>::iterator tmp = it->second.find(num[i]);
				if (tmp == it->second.end()){
					it->second[num[i]] = 0;
				}
			}//如果其他组没有这个数，添加并计数为0
		}
		for (auto i = mp.begin(); i != mp.end(); i++){
			cout << i->first << "={";
			bool flag = false;
			for (auto j = i->second.begin(); j != i->second.end(); j++){
				if (flag == false){
					cout << j->first << "=" << j->second;
					flag = true;
				}
				else{
					cout << "," << j->first << "=" << j->second;
				}
			}
			cout << "}" << endl;
		}
	}
	return 0;
}


//编排字符串
//请输入字符串，最多输入4 个字符串，要求后输入的字符串排在前面，例如
//输入：EricZ
//输出：1 = EricZ
//输入：David
//输出：1 = David 2 = EricZ
//输入：Peter
//输出：1 = Peter 2 = David 3 = EricZ
//输入：Alan
//输出：1 = Alan 2 = Peter 3 = David 4 = EricZ
//输入：Jane
//输出：1 = Jane 2 = Alan 3 = Peter 4 = David
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int m;
	cin >> m;
	getchar();
	vector<string> v;
	for (int i = 0; i < m; i++)
	{
		string str;
		getline(cin, str);
		v.push_back(str);
		int cnt = 0;   //用来记录输出的行数
		for (int j = v.size() - 1; j >= 0; j--)
		{
			cnt++;
			if (cnt < 5)
			{
				printf("%d=%s%s", cnt, v[j].c_str(), (j == 0 || cnt == 4 ? "\n" : " "));
			}
		}
	}
	return 0;
}

//查找输入整数二进制中1的个数
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n > 0)
		{
			int num = n & 1;
			if (num == 1)
			{
				count++;
			}
			n >>= 1;
		}
		cout << count << endl;
	}

	return 0;
}

//手套问题
	class Gloves {
	public:
		int findMinimum(int n, vector<int> left, vector<int> right) {
			// write code here
			int sum = 0;
			int leftSum = 0, rightSum = 0;
			int leftMin = 26, rightMin = 26;
			for (int i = 0; i<n; i++)
			{
				if (left[i] * right[i] == 0)
					sum += (left[i] + right[i]);
				else{
					leftSum += left[i];
					rightSum += right[i];
					leftMin = min(leftMin, left[i]);
					rightMin = min(rightMin, right[i]);
				}
			}
			return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
		}

	};

//iNOC产品部--完全数计算
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n > 0 && n <= 500000){
		int counts = 0;
		for (int i = 1; i <= n; ++i)
		{
			int sum = 0;
			for (int j = 1; j <= i / 2; ++j)
			if (i % j == 0)
				sum += j;
			if (i == sum)
				counts++;
		}
		cout << counts << endl;
		}
		else
			cout << "-1" << endl;
	}
		return 0;
}


//扑克牌大小
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	string card = "345678910JQKA2";
	vector<string> MAX;
	MAX.push_back("joker JOKER");
	MAX.push_back("JOKER joker");
	string input;
	while (getline(cin, input))
	{
		unsigned int pos = input.find('-');
		int len = input.size();
		string s1 = input.substr(0, pos);
		string s2 = input.substr(pos + 1, len - pos - 1);
		//cout<<s1<<" "<<s2<<endl;
		//这里有个坑就是 "10"是两位数，所以只能找空白
		int n1 = count(s1.begin(), s1.end(), ' ');
		int n2 = count(s2.begin(), s2.end(), ' ');
		// double joker
		if (s1 == MAX[0] || s1 == MAX[1])
		{
			cout << s1 << endl; continue;
		}
		if (s2 == MAX[0] || s2 == MAX[1])
		{
			cout << s2 << endl; continue;
		}
		//"10"是两位数,只需要取第一位1就可以
		if (n1 == n2)
		{
			int l = card.find(s1[0]);
			int r = card.find(s2[0]);
			string ans = l>r ? s1 : s2;
			cout << ans << endl; continue;
		}
		//炸弹
		if (n1 == 3 && n2 != 3)
		{
			cout << s1 << endl; continue;
		}
		if (n1 != 3 && n2 == 3)
		{
			cout << s2 << endl; continue;
		}
		cout << "ERROR" << endl;
	}


}


//对称平方数
#include<iostream>
using namespace std;
int main(){
	int a[50], a_count = 0;
	int b[10];
	for (int n = 1; n<256; n++){
		for (int i = 0; i<10; i++)
			b[i] = 0;
		int temp = n*n, count = 0;
		while (temp>0){
			b[count++] = temp % 10;
			temp /= 10;
		}
		bool judge = 1;
		for (int i = 0; i<count / 2; i++){
			if (b[i] != b[count - 1 - i]){
				judge = 0;
				break;
			}
		}
		if (judge == 1)
			a[a_count++] = n;
	}
	for (int i = 0; i<a_count; i++)
		cout << a[i] << endl;
}