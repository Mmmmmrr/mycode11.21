//#define _CRT_SECURE_NO_WARNINGS 1
//
////模拟实现auto_ptr
//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//	~AutoPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		if (this != &ap)
//		{
//			if (_ptr)
//				delete _ptr;
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//		return *this;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	AutoPtr<Date> ap(new Date);
//	AutoPtr<Date> copy(ap);
//	ap->_year = 2019;
//	return 0;
//}
//
////模拟实现unique_ptr
//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{
//
//	}
//	~UniquePtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	//C++98防拷贝的方式：只声明不实现+声明私有
//	UniquePtr(UniquePtr<T> const&);
//	UniquePtr& operator=(UniquePtr<T> const&);
//	//C++11防拷贝方式：delete
//	UniquePtr(UniquePtr<T> const &) = delete;
//	UniquePtr & operator=(UniquePtr<T> const&) = delete;
//
//private:
//	T* _ptr;
//};
//int main()
//{
//	UniquePtr<Date> up(new Date);
//	return 0;
//}
//
//
//模拟实现shared_ptr
//#include <thread>
//#include <mutex>
//#include <iostream>
//using namespace std;
//template<class T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//		, _pRefCount(new int(1))
//		, _pMutex(new mutex)
//	{
//
//	}
//	~SharedPtr()
//	{
//		Release();
//	}
//	SharedPtr(const SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		, _pRefCount(sp._pRefCount)
//		, _pMutex(sp._pMutex)
//	{
//		AddRefCount();
//	}
//
//	SharedPtr<T>& operator= (const SharedPtr<T>& sp)
//	{
//		if (_ptr != sp._ptr)
//		{
//			Release();
//			_ptr = sp._ptr;
//			_pRefCount = sp._pRefCount;
//			_pMutex = sp._pMutex;
//			AddRefCount();
//		}
//		return *this;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//	int UseCount()
//	{
//		return *_pRefCount;
//	}
//	T* Get()
//	{
//		return _ptr;
//	}
//	void AddRefCount()
//	{
//		_pMutex->lock();
//		++(*_pRefCount);
//		_pMutex->unlock();
//	}
//private:
//	void Release()
//	{
//		bool flag = false;
//		_pMutex->lock();
//		if (--(*_pRefCount) == 0)
//		{
//			delete _ptr;
//			delete _pRefCount;
//			flag = true;
//		}
//		_pMutex->unlock();
//		if (flag == true)
//		{
//			delete _pMutex;
//		}
//	}
//
//private:
//	T* _ptr;
//	int* _pRefCount;
//	mutex* _pMutex;
//};
//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
////int main()
////{
////	SharedPtr<int> sp1(new int(10));
////	SharedPtr<int> sp2(sp1);
////	*sp2 = 20;
////	cout << sp1.UseCount() << endl;
////	cout << sp2.UseCount() << endl;
////	SharedPtr<int> sp3(new int(10));
////	sp2 = sp3;
////	cout << sp1.UseCount() << endl;
////	cout << sp2.UseCount() << endl;
////	cout << sp3.UseCount() << endl;
////}
//
//
//void SharePtrFunc(SharedPtr<Date>& sp, int n)
//{
//	cout << sp.Get() << endl;
//	for (size_t i = 0; i < n; i++)
//	{
//		SharedPtr<Date> copy(sp);
//		copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//int main()
//{
//	SharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//	const size_t n = 100000;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//	t1.join();
//	t2.join();
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <thread>
//#include <memory>
//using namespace std;
//class ListNode
//{
//public:
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <memory>
//using namespace std;
//class ListNode
//{
//public:
//	int _data;
//	weak_ptr<ListNode> _prev;
//	weak_ptr<ListNode> _next;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <memory>
using namespace std;
template<class T>
struct FreeFunc
{
	void operator()(T* ptr)
	{
		cout << "free" << ptr << endl;
		free(ptr);
	}
};
template<class T>
struct DeleteArrayFunc
{
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};

int main()
{
	FreeFunc<int> freefunc;
	shared_ptr<int> sp1((int*)malloc(4), freefunc);
	DeleteArrayFunc<int> deletearrayfunc;
	shared_ptr<int> sp2((int*)malloc(4), deletearrayfunc);
	system("pause");
	return 0;
}