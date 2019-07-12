//美国节日
#include <iostream>
using namespace std;
//蔡勒公式
//在公式中有个与其他公式不同的地方：    把一月和二月看成是上一年的十三月和十四月
//W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}
	int century = year / 100;
	year = year % 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;
	week = (week % 7 + 7) % 7;
	if (week == 0)
	{
		week = 7;
	}
	return week;
}
int day_demand(int year, int month, int count, int d_of_week)
{
	int week = day_of_week(year, month, 1);
	// 第几个星期 * 7天 + 到下一个星期 d_of_week 还有几天
	int day = 1 + (count - 1) * 7 + ((7 - week) + d_of_week) % 7;
	return day;
}
void new_year(int year)
{
	cout << year << "-01" << "-01" << endl;
}
void martin_luther_king_day(int year)
{
	printf("%d-01-%02d\n", year, day_demand(year, 1, 3, 1));
}
void president_day(int year)
{
	printf("%d-02-%02d\n", year, day_demand(year, 2, 3, 1));
}
void memorial_day(int year)
{
	int w = day_of_week(year, 6, 1);
	int d = (w == 1) ? 6 : w - 2;
	int day = 31 - d;
	printf("%d-05-%02d\n", year, day);
}
void independence_day(int year)
{
	printf("%d-07-04\n", year);
}
void labor_day(int year)
{
	printf("%d-09-%02d\n", year, day_demand(year, 9, 1, 1));
}
void thanks_giving_day(int year)
{
	printf("%d-11-%02d\n", year, day_demand(year, 11, 4, 4));
}
void christmas(int year)
{
	printf("%d-12-25\n", year);
}
void fesitival(int year)
{
	new_year(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
}
int main()
{
	int year;
	while (cin >> year)
	{
		fesitival(year);
		cout << endl;
	}
	return 0;
}




//淘宝网店
#include <iostream>
using namespace std;
bool Isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}
int main()
{
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year1, month1, day1;
	int year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int sum = 0;
		for (int i = year1; i <= year2 - 1; i++)
		{
			if (Isleap(i))
				sum += 580;
			else
				sum += 579;
		}
		for (int i = 0; i <= month1 - 1; i++)
		{
			int tmp = 0;
			if (i == month1 - 1)
			{
				tmp = day1 - 1;
			}
			else
				tmp = day[i];
			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
				sum -= tmp * 2;
			else
				sum -= tmp;
		}
		for (int i = 0; i <= month2 - 1; i++)
		{
			int tmp = 0;
			if (i == month2 - 1)
			{
				tmp = day2;
			}
			else
				tmp = day[i];
			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
				sum += tmp * 2;
			else
				sum += tmp;
		}
		cout << sum << endl;
	}
	return 0;

}


//客似云来
#include <iostream>
using namespace std;
int main()
{
	long long a[80] = { 1, 1 };
	for (int i = 2; i < 80; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		long long ret = 0;
		for (int i = n; i <= m; i++)
		{
			ret += a[i - 1];
		}
		cout << ret << endl;
	}
	return 0;
}



//剪花布条
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;
		int j;
		for (int i = 0; i < s.size() - t.size() + 1;)
		{
			string m;
			for (j = i; j < t.length() + i; j++)
				m += s[j];
			if (m == t)
			{
				count++;
				i = j;
			}
			else
				i++;
		}
		cout << count << endl;
	}
	return 0;
}



//收件人列表
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cin.get();
		string str;
		for (int i = 0; i < n; i++)
		{
			getline(cin, str);
			if (i != n - 1)
			{
				if (str.find(',') != -1 || str.find(' ') != -1)
					cout << '"' << str << '"' << "," << " ";
				else
					cout << str << "," << " ";
			}
			else
			{
				if (str.find(',') != -1 || str.find(' ') != -1)
					cout << '"' << str << '"' << endl;
				else
					cout << str << endl;
			}
		}
	}
	return 0;
}


//养兔子
#include<iostream>
using namespace std;
int main()
{
	long long int f[100];
	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 3; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		cout << f[n] << endl;
	}
	return 0;
}


//年会抽奖
// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		double a[21] = { 0, 0, 1 };
		long long int ret[21] = { 0, 1, 2 };
		for (int i = 3; i < 21; i++)
		{
			a[i] = (i - 1)*(a[i - 2] + a[i - 1]);
			ret[i] = i*ret[i - 1];
		}
		printf("%.2f%c\n", 1.0*a[n] / ret[n] * 100, '%');
	}
	return 0;
}



//抄送列表
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	string s;
	while (getline(cin, name))
	{
		getline(cin, s);
		bool flag = false;
		for (int i = 0; i < name.size(); i++)
		{
			string t;
			if (name[i] == '"')
			{
				i++;
				while (i <name.size() && name[i] != '"')
				{
					t += name[i];
					i++;
				}
				if (t == s)
				{
					flag = true;
					break;
				}
			}
			else if (name[i] != ',')
			{
				while (i < name.size() && name[i] != ',')
				{
					t += name[i];
					i++;
				}
				if (t == s)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}

	return 0;
}