#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
void printf(vector<int> v)
{
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void const_printf(const vector<int> &v)
{
vector<int>::const_iterator it = v.begin();
while (it != v.end())
{
	//*it = 10;
	cout << *it << " ";
	++it;
}
cout << endl;
}

void test()
{
	vector<int> v(3, 3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	vector<int> copy(v);
	//[begin,end]
	vector<int>::iterator copyit = copy.begin();
	while (copyit != copy.end())
	{
		cout << *copyit << " ";
		++copyit;
	}
	cout << endl;
	printf(copy);
	const_printf(copy);
	cout << v.max_size() << endl;

}
void test2()
{
	size_t sz;
	vector<int> foo;
	foo.resize(100);
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void test3()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void test4()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	printf(v1);
	v1.assign(10, 3);
	printf(v1);
}
int main()
{
	//test();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}