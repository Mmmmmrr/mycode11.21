//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//template<class T1,class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 seconed_type;
//	T1 first;
//	T2 seconed;
//	pair()
//		:first(T1())
//		, seconed(T2())
//	{}
//	pair(const T1& a, const T2& b)
//		:first(a)
//		, seconed(b)
//	{}
//};
#include <iostream>
#include <string>
#include <map>
using namespace std;
//int main()
//{
//	map<string, string> m1;
//	map<string, string> m2{ { "apple", "苹果" },
//	{ "banana", "香蕉" }, { "orange", "橘子" }, { "peach", "桃子" }, { "waterme", "水蜜桃" } };
//	cout << m2["apple"] << endl;
//	cout << m2["waterme"] << endl;
//	map<string, string> m3(m2); 
//	system("pause");
//	return 0;
//}

//int main()
//{
//	map<string, string> m{ { "apple", "苹果" },{ "banana", "香蕉" }, { "orange", "橘子" }, { "peach", "桃子" }, { "waterme", "水蜜桃" } };
//	for (auto it = m.begin(); it != m.end(); ++it)
//	{
//		cout << (*it).first << "====》" << (*it).second << endl;
//	}
//	system("pause");
//	return 0;
//}

#include <string>
#include <map>
#include <iostream>
using namespace std;
int main()
{
	// 构造一个空的map，此时m中一个元素都没有
	map<string, string> m;
	/*
	operator[]的原理是：
	用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中
	如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器
	如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器
	operator[]函数最后将insert返回值键值对中的value返回
	*/
	// 将<"apple", "">插入map中，插入成功，返回value的引用，将“苹果”赋值给该引用结果，
	// 即修改与"apple"对应的value""为"苹果" m["apple"] = "苹果";
	// 将<"apple", "">插入map中，插入失败，将<"apple", "苹果">中的"苹果"返回
	cout << m["apple"] << endl;
	cout << m.size() << endl;
	system("pause");
	return 0;
	// “banan不在map中，该函数抛异常” m.at("banan");
}


#include <string>
#include <map>
void TestMap()
{
	map<string, string> m;
	// 向map中插入元素的方式：
	// 将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
	m.insert(pair<string, string>("peach", "桃子"));
	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
	m.insert(make_pair("banan", "香蕉"));
	// 借用operator[]向map中插入元素
	m["apple"] = "苹果";
	// key不存在时抛异常
	//m.at("waterme") = "水蜜桃";
	m.insert(m.find("banan"), make_pair("waterme", "水蜜桃"));
	cout << m.size() << endl;
	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" <<
		ret.first->second << " 插入失败" << endl;
	// 删除key为"apple"的元素
	m.erase("apple");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;
}



#include <map>
#include <string>
void TestMultimap1()
{
	multimap<string, string> m; m.insert(make_pair("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("鲁达", "花和尚"));
	// 尝试插入key相同的元素
		m.insert(make_pair("李逵", "铁牛"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;
	// key为李逵的元素有多少个
	cout << m.count("李逵") << endl;
}
void TestMultimap2()
{
	multimap<int, int> m;
	for (int i = 0; i < 10; ++i) m.insert(pair<int, int>(i, i));
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// 返回m中大于等于5的第一个元素
	auto it = m.lower_bound(5);
	cout << it->first << "--->" << it->second << endl;
	// 返回m中大于5的元素
	it = m.upper_bound(5);
	cout << it->first << "--->" << it->second << endl;
}

#include <set>
void TestSet()
{
	// 用数组array中的元素构造set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array));
	cout << s.size() << endl;
	// 正向打印set中的元素，从打印结果中可以看出：set可去重
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
		// 使用迭代器逆向打印set中的元素
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// set中值为3的元素出现了几次
	cout << s.count(3) << endl;
}

#include <vector>
class Solution {
public:
	class Compare
	{
	public:
		// 在set中进行排序时的比较规则
		bool operator()(const pair<string, int>& left, const pair<string, int>& right)
		{
			return left.second > right.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 用<单词，单词出现次数>构建键值对，然后将vector中的单词放进去，统计每个单词出现的次数
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);
		// 将单词按照其出现次数进行排序，出现相同次数的单词集中在一块
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// 将相同次数的单词放在set中，然后再放到vector中
		set<string> s;
		size_t count = 0; // 统计相同次数单词的个数
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				// 相同次数的单词已经全部放到set中
				if (count != e.second)
				{
					if (s.size() < leftCount)
					{
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}
					else
					{
						break;
					}
				}
			}
			count = e.second; s.insert(e.first);
		}
		for (auto& e : s)
		{
			if (0 == leftCount)
				break;
			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};