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


//二叉搜索树的实现
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
		// 如果树为空，直接插入
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// 按照二叉搜索树的性质查找data在树中的插入位置
		PNode pCur = _pRoot;
		// 记录pCur的双亲，因为新元素最终插入在pCur双亲左右孩子的位置
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; // 元素已经在树中存在
			elsereturn false;
		}
		// 插入元素
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	bool Erase(const T& data)
	{
		// 如果树为空，删除失败
		if (nullptr == _pRoot)
			return false;
		// 查找在data在树中的位置
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
		// data不在二叉搜索树中吗，无法删除
		if (nullptr == pCur)
			return false;
		// 分以下情况进行删除，同学们自己画图分析完成
		if (nullptr == pCur->_pRight)
		{
			// 当前节点只有左孩子或者左孩子为空---可直接删除
		}
		else if (nullptr == pCur->_pRight)
		{
			// 当前节点只有右孩子---可直接删除
		}
		else
		{
			// 当前节点左右孩子都存在，直接删除不好删除，可以在其子树中找一个替代结点，比如：
			// 找其左子树中的最大节点，即左子树中最右侧的节点，或者在其右子树中最小的节点，即右子
			树中最小的节点
				// 替代节点找到后，将替代节点中的值交给待删除节点，转换成删除替代节点
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


//AVL
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _data(data)
	, _bf(0)
	{}

	bool Insert(const T& data)
	{
		// 1. 先按照二叉搜索树的规则将节点插入到AVL树中
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// 按照二叉搜索树的性质找data在AVL中的插入位置
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_data;
			else
				return false; // 该节点在二叉搜索树中存在
		}
		// 插入新节点：新节点一定插入在pParent的左侧或者右侧
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		// 更新pCur的双亲节点
		pCur->_pParent = pParent;
		// 2. 新节点插入后，AVL树的平衡性可能会遭到破坏，此时就需要更新平衡因子，并检测是否破坏了
		AVL树的平衡性
			//...
			return true;
	}

	//调整节点的平衡因子
	bool Insert(const T& data) {
		// 1. 先按照二叉搜索树的规则将节点插入到AVL树中
		// ...
		// 2. 新节点插入后，AVL树的平衡性可能会遭到破坏，此时就需要更新平衡因子，并检测是否破坏了AVL树
		// 的平衡性
		/*
		pCur插入后，pParent的平衡因子一定需要调整，在插入之前，pParent
		的平衡因子分为三种情况：-1，0, 1, 分以下两种情况：
		1. 如果pCur插入到pParent的左侧，只需给pParent的平衡因子-1即可
		2. 如果pCur插入到pParent的右侧，只需给pParent的平衡因子+1即可
		此时：pParent的平衡因子可能有三种情况：0，正负1， 正负2
		1. 如果pParent的平衡因子为0，说明插入之前pParent的平衡因子为正负1，插入后被调整成0，此时满
		足
		AVL树的性质，插入成功
		2. 如果pParent的平衡因子为正负1，说明插入前pParent的平衡因子一定为0，插入后被更新成正负1， 此
		时以pParent为根的树的高度增加，需要继续向上更新
		3. 如果pParent的平衡因子为正负2，则pParent的平衡因子违反平衡树的性质，需要对其进行旋转处理
		*/
		while (pParent)
		{
			// 更新双亲的平衡因子
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
			// 更新后检测双亲的平衡因子
			if (0 == pParent->_bf)
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				// 插入前双亲的平衡因子是0，插入后双亲的平衡因为为1 或者 -1 ，说明以双亲为根的二叉
				树
					// 的高度增加了一层，因此需要继续向上调整
					pCur = pParent;
				pParent = pCur->_pParent;
			}
			else
			{
				// 双亲的平衡因子为正负2，违反了AVL树的平衡性，需要对以pParent
				// 为根的树进行旋转处理
				if (2 == pParent->_bf)
				{
					// ...
				}
				else
				{
					// ...
				}
			}
		}
		return true;
	}


	void _RotateR(PNode pParent) {
		// pSubL: pParent的左孩子
		// pSubLR: pParent左孩子的右孩子，注意：该
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		// 旋转完成之后，30的右孩子作为双亲的左孩子
		pParent->_pLeft = pSubLR;
		// 如果30的左孩子的右孩子存在，更新亲双亲
		if (pSubLR)
			pSubLR->_pParent = pParent;
		// 60 作为 30的右孩子
		pSubL->_pRight = pParent;
		// 因为60可能是棵子树，因此在更新其双亲前必须先保存60的双亲
		PNode pPParent = pParent->_pParent;
		// 更新60的双亲
		pParent->_pParent = pSubL;
		// 更新30的双亲
		pSubL->_pParent = pPParent;
		// 如果60是根节点，根新指向根节点的指针
		if (NULL == pPParent)
		{
			_pRoot = pSubL;
			pSubL->_pParent = NULL;
		}
		else
		{
			// 如果60是子树，可能是其双亲的左子树，也可能是右子树
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
		// 根据调整后的结构更新部分节点的平衡因子
		pParent->_bf = pSubL->_bf = 0;
	}

	// 旋转之前，60的平衡因子可能是-1/0/1，旋转完成之后，根据情况对其他节点的平衡因子进行调整
	void _RotateLR(PNode pParent) {
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		// 旋转之前，保存pSubLR的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因
		子
			int bf = pSubLR->_bf;
		// 先对30进行左单旋
		_RotateL(pParent->_pLeft);
		// 再对90进行右单旋
		_RotateR(pParent);
		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}


	AVLTreeNode<T>* _pLeft; // 该节点的左孩子
	AVLTreeNode<T>* _pRight; // 该节点的右孩子
	AVLTreeNode<T>* _pParent; // 该节点的双亲
	T _data;
	int _bf; // 该节点的平衡因子
};


