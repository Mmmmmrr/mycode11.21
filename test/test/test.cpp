#define _CRT_SECURE_NO_WARNINGS 1
//����ͳ��
//������һ������Ȼ����������飬���շ���ͳ�Ƴ��ִ��������
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
			}//���������û�����������Ӳ�����Ϊ0
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


//�����ַ���
//�������ַ������������4 ���ַ�����Ҫ���������ַ�������ǰ�棬����
//���룺EricZ
//�����1 = EricZ
//���룺David
//�����1 = David 2 = EricZ
//���룺Peter
//�����1 = Peter 2 = David 3 = EricZ
//���룺Alan
//�����1 = Alan 2 = Peter 3 = David 4 = EricZ
//���룺Jane
//�����1 = Jane 2 = Alan 3 = Peter 4 = David
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
		int cnt = 0;   //������¼���������
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

//��������������������1�ĸ���
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

//��������
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

//iNOC��Ʒ��--��ȫ������
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


//�˿��ƴ�С
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
		//�����и��Ӿ��� "10"����λ��������ֻ���ҿհ�
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
		//"10"����λ��,ֻ��Ҫȡ��һλ1�Ϳ���
		if (n1 == n2)
		{
			int l = card.find(s1[0]);
			int r = card.find(s2[0]);
			string ans = l>r ? s1 : s2;
			cout << ans << endl; continue;
		}
		//ը��
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


//�Գ�ƽ����
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

//�������
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 2)
			cout << -1 << endl;
		else
		{
			if (n % 2 == 1)
				cout << 2 << endl;
			else if (n % 4 == 2)
				cout << 4 << endl;
			else if (n % 4 == 0)
				cout << 3 << endl;
		}
	}
	return 0;
}


//�������������
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string num1;
	string num2;
	while (cin >> num1 >> num2)
	{
		int ret = 0;
		while (num1.size() < num2.size())
			num1 = "0" + num1;
		while (num2.size() < num1.size())
			num2 = "0" + num2;
		int num = 0;
		for (int i = num1.size() - 1; i >= 0; i--)
		{
			num = num1[i] - '0' + num2[i] - '0' + ret;
			num1[i] = num % 10 + '0';
			if (num / 10)
				ret = 1;
			else
				ret = 0;
		}
		if (ret)
			num1 = "1" + num1;
		cout << num1 << endl;
	}
	return 0;
}


//�ַ���ͨ���
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool solve(string str1, string str2)
{
	if (str1.length()>str2.length())
		return false;
	int i, j;
	for (i = 0, j = 0; i<str1.length(), j<str2.length();)
	{
		if (str1[i] == '?')
		{
			i++;
			j++;
		}
		else if (str1[i] == '*')
		{
			//i++;j++;//ֻ����һ��Ҳ��ͨ��
			if (i == str1.length() - 1)
				return true;
			else if (i<str1.length() - 1)
			{
				i++; j++;
			}
		}
		else if (str1[i] != str2[j])
			return false;
		else
		{
			i++; j++;
		}
	}
	return true;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (solve(str1, str2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}


//ÿ�������ӵ�����
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int a = 1;
		int b = 0; 
		int c = 0;
		while (--n)
		{
			c += b;
			b = a;
			a = c;
		}
		cout << a + b + c << endl;
	}
	return 0;
}


//��ˮƿ����
#include <iostream>
using namespace std;
int f(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return f(n - 2) + 1;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << f(n) << endl;
	}
	return 0;
}



//���������ַ������ַ���
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void findMaxCommonStr(string s1, string s2)
{
	if (s1.length()>s2.length())
		swap(s1, s2);//s1���ڱ���϶̵��Ӵ�
	int len1 = s1.length(), len2 = s2.length();
	int maxLen = 0, start = 0;
	vector<vector<int> >dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; ++i)
	for (int j = 1; j <= len2; ++j)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			dp[i][j] = dp[i - 1][j - 1] + 1;
			if (dp[i][j]>maxLen)
			{
				maxLen = dp[i][j];
				start = i - maxLen;//��¼������Ӵ�����ʼλ��
			}
		}
	}
	cout << s1.substr(start, maxLen) << endl;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		findMaxCommonStr(s1, s2);
	}
	return 0;
}



//��ת�ַ���
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}


//�����ַ�������
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int len = s1.size();
	int len2 = s2.size();
	int maxlen = 0;
	vector<vector<int>> dp(len + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				maxlen = max(maxlen, dp[i][j]);
			}
		}
	}
	cout << maxlen << endl;
	return 0;
}


//ϴ��
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; i++)
		{
			cin >> table[i];
		}
		while (k--)
		{
			vector<int> v(table.begin(), table.end());
			for (int i = 0; i < n; i++)
			{
				table[2 * i] = v[i];
				table[2 * i + 1] = v[i + n];
			}
		}
		for (int i = 0; i < num - 1; i++)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	return 0;
}



//MP3���λ��
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		string str;
		cin >> str;
		int top = 1, buttom = 4;
		int cur = 1;
		if (n <= 4)
		{
			buttom = n;
			for (int i = 0; i<str.size(); i++)
			{
				if (str[i] == 'U')
				{
					if (cur == 1) cur = n;
					else cur--;
				}
				else
				{
					if (cur == n) cur = 1;
					else cur++;
				}
			}
		}
		else
		{
			for (int i = 0; i<str.size(); i++)
			{
				if (str[i] == 'U')
				{
					if (cur == 1)
					{
						cur = n;
						top = n - 3;
						buttom = n;
					}
					else if (cur == top)
					{
						top--;
						cur--;
						buttom--;
					}
					else cur--;
				}
				else
				{
					if (cur == n)
					{
						cur = 1;
						top = 1;
						buttom = 4;
					}
					else if (cur == buttom)
					{
						cur++;
						top++;
						buttom++;
					}
					else cur++;
				}
			}
		}
		for (int i = top; i<buttom; i++)
		{
			cout << i << " ";
		}
		cout << buttom << endl;
		cout << cur << endl;
	}
	return 0;
}

//С�׵�����֮·
#include <iostream>
#include <vector>
using namespace std;
int yueshu(int a, int b)
{
	int temp;
	while (b){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		int i, tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			if (a >= tmp)
				a = a + tmp;
			else
			{
				int c = yueshu(a, tmp);
				a = a + c;
			}
		}
		cout << a << endl;
	}

	return 0;
}


//�����ַ�����һ�����ֵ�Ψһ�ַ�
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		int a[128] = { 0 };
		bool flag = false;
		for (int i = 0; i < str.size(); i++)
		{
			++a[str[i]];
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (a[str[i]] == 1)
			{
				cout << str[i] << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
			cout << "-1" << endl;
	}
	return 0;
}