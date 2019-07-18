#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
//void swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//void swap2(double& left, double& right)
//{
//	double tmp = left;
//	left = right;
//	right = tmp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	swap(a, b);
//	double x = 1.1;
//	double y = 1.0;
//	swap2(x, y);
//	return 0;
//
//}

//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	cout << a << endl;
//	cout << b << endl;
//	double a1 = 1.002;
//	double b1 = 2.002;
//	Swap(a1, b1);
//	cout << a1 << endl;
//	cout << b1 << endl;
//	system("pause");
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 10;
//	double d1 = 10.02, d2 = 10.05;
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//	cout << Add((double)a2, d2) << endl;
//	cout << Add<double>(a1, d1) << endl;//显示实例化
//}


//typedef VDateType;
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	void PushBack(const T& x);
	//void PushBack(const T& x)
	//{
	//	//不看增容
	//	if (_size == _capacity)
	//	{
	//		cout << "Full" << endl;
	//		return;
	//	}
	//	_array[_size] = x;
	//	++_size;
	//}

	//模板类不使用不会检测到（没有实例化出来）按需实例化
	void PopBack()
	{}

	~Vector()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = _capacity = 0;
		}
	}
	size_t Size()
	{
		return _size;
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

private:
	//VDateType* _array;
	T* _array;
	size_t _size;
	size_t _capacity;
};

//声明和类型分离
template<class T>
void Vector<T>::PushBack(const T& x)
{
	if (_size == _capacity)
	{
		cout << " Full " << endl;
		return;
	}
	_array[_size] = x;
	++_size;
}


//Vector v1;  int
//Vwctor v2;  char
int main()
{
	//类模板的原理：
	Vector<int> v1;
	Vector<char> v2;//同一个类模板
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	//cout << v1[3] << endl;
	for (size_t i = 0; i < v1.Size(); i++)
	{
		if (v1[i] % 2 == 0)
		{
			v1[i] = v1[i]* 2;
		}
	}
	for (size_t i = 0; i < v1.Size(); i++)
	{
		cout << v1[i] << endl;
		//cout << v1.operator[](i) << endl;

	}
	system("pause");
	return 0;
}















