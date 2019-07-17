#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//class Test
//{
//public:
//	Test()
//		:_data(0)
//	{
//		cout << "Test()" << endl;
//	}
//	~Test()
//	{
//		cout << " ~Test()" << endl;
//	}
//private:
//	int _data;
//};
//void Test2()
//{
//	//malloc���ռ䵫û�г�ʼ����
//	Test* p = (Test*)malloc(sizeof(Test));
//	free(p);
//
//	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
//	free(p2);
//	//���ռ䲢��ʼ��
//	Test* p3 = new Test;
//	Test* p4 = new Test[10];
//	//��������+�ͷſռ�
//	delete p3;
//	delete[] p4;
//
//	int* p5 = new int;//���ᴦ�����ֵ
//	int* p6 = new int(10);//��ʼ��Ϊ10
//
//}
//int main()
//{
//	Test2();
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//1.operator new ���ռ�
//	//2.���ù����ʼ��
//	Test* p = (Test*)operator new(sizeof(Test));
//	//3.��������������������
//	//4.operator delete�ͷŶ���
//	delete p;
//}


struct ListNode{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	ListNode()
		:_next(nullptr)
		, _prev(nullptr)
		, _data(0)
	{
		cout << "ListNode()" << endl;
	}
	
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	system("pause");
	return 0;
}