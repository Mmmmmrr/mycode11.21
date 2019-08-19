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
//	map<string, string> m2{ { "apple", "ƻ��" },
//	{ "banana", "�㽶" }, { "orange", "����" }, { "peach", "����" }, { "waterme", "ˮ����" } };
//	cout << m2["apple"] << endl;
//	cout << m2["waterme"] << endl;
//	map<string, string> m3(m2); 
//	system("pause");
//	return 0;
//}

//int main()
//{
//	map<string, string> m{ { "apple", "ƻ��" },{ "banana", "�㽶" }, { "orange", "����" }, { "peach", "����" }, { "waterme", "ˮ����" } };
//	for (auto it = m.begin(); it != m.end(); ++it)
//	{
//		cout << (*it).first << "====��" << (*it).second << endl;
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
	// ����һ���յ�map����ʱm��һ��Ԫ�ض�û��
	map<string, string> m;
	/*
	operator[]��ԭ���ǣ�
	��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��
	���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����
	���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����
	operator[]�������insert����ֵ��ֵ���е�value����
	*/
	// ��<"apple", "">����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý����
	// ���޸���"apple"��Ӧ��value""Ϊ"ƻ��" m["apple"] = "ƻ��";
	// ��<"apple", "">����map�У�����ʧ�ܣ���<"apple", "ƻ��">�е�"ƻ��"����
	cout << m["apple"] << endl;
	cout << m.size() << endl;
	system("pause");
	return 0;
	// ��banan����map�У��ú������쳣�� m.at("banan");
}


#include <string>
#include <map>
void TestMap()
{
	map<string, string> m;
	// ��map�в���Ԫ�صķ�ʽ��
	// ����ֵ��<"peach","����">����map�У���pairֱ���������ֵ��
	m.insert(pair<string, string>("peach", "����"));
	// ����ֵ��<"peach","����">����map�У���make_pair�����������ֵ��
	m.insert(make_pair("banan", "�㽶"));
	// ����operator[]��map�в���Ԫ��
	m["apple"] = "ƻ��";
	// key������ʱ���쳣
	//m.at("waterme") = "ˮ����";
	m.insert(m.find("banan"), make_pair("waterme", "ˮ����"));
	cout << m.size() << endl;
	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��
	auto ret = m.insert(make_pair("peach", "��ɫ"));
	if (ret.second)
		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
	else
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" <<
		ret.first->second << " ����ʧ��" << endl;
	// ɾ��keyΪ"apple"��Ԫ��
	m.erase("apple");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	if (1 == m.count("apple"))
		cout << "apple����" << endl;
	else
		cout << "apple������" << endl;
}



#include <map>
#include <string>
void TestMultimap1()
{
	multimap<string, string> m; m.insert(make_pair("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("³��", "������"));
	// ���Բ���key��ͬ��Ԫ��
		m.insert(make_pair("����", "��ţ"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;
	// keyΪ���ӵ�Ԫ���ж��ٸ�
	cout << m.count("����") << endl;
}
void TestMultimap2()
{
	multimap<int, int> m;
	for (int i = 0; i < 10; ++i) m.insert(pair<int, int>(i, i));
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// ����m�д��ڵ���5�ĵ�һ��Ԫ��
	auto it = m.lower_bound(5);
	cout << it->first << "--->" << it->second << endl;
	// ����m�д���5��Ԫ��
	it = m.upper_bound(5);
	cout << it->first << "--->" << it->second << endl;
}

#include <set>
void TestSet()
{
	// ������array�е�Ԫ�ع���set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array));
	cout << s.size() << endl;
	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
		// ʹ�õ����������ӡset�е�Ԫ��
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// set��ֵΪ3��Ԫ�س����˼���
	cout << s.count(3) << endl;
}

#include <vector>
class Solution {
public:
	class Compare
	{
	public:
		// ��set�н�������ʱ�ıȽϹ���
		bool operator()(const pair<string, int>& left, const pair<string, int>& right)
		{
			return left.second > right.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// ��<���ʣ����ʳ��ִ���>������ֵ�ԣ�Ȼ��vector�еĵ��ʷŽ�ȥ��ͳ��ÿ�����ʳ��ֵĴ���
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);
		// �����ʰ�������ִ����������򣬳�����ͬ�����ĵ��ʼ�����һ��
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// ����ͬ�����ĵ��ʷ���set�У�Ȼ���ٷŵ�vector��
		set<string> s;
		size_t count = 0; // ͳ����ͬ�������ʵĸ���
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				// ��ͬ�����ĵ����Ѿ�ȫ���ŵ�set��
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


//������������ʵ��
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight; T _data;
};
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		: _pRoot(nullptr)
	{}
	~BSTree()
	{
		_Destroy(_pRoot);
	}
	PNode Find(const T& data)
	{
		PNode pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_pLeft)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}
	bool Insert(const T& data)
	{
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// ���ն��������������ʲ���data�����еĲ���λ��
		PNode pCur = _pRoot;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; // Ԫ���Ѿ������д���
			elsereturn false;
		}
		// ����Ԫ��
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	bool Erase(const T& data)
	{
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _pRoot)
			return false;
		// ������data�����е�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data���ڶ��������������޷�ɾ��
		if (nullptr == pCur)
			return false;
		// �������������ɾ����ͬѧ���Լ���ͼ�������
		if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
		}
		else if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
		}
		else
		{
			// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ��������������������һ�������㣬���磺
			// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬������������������С�Ľڵ㣬������
			������С�Ľڵ�
				// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬ת����ɾ������ڵ�
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	void _Destroy(PNode& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			pRoot = nullptr;
		}
	}
private:
	PNode _pRoot;
};