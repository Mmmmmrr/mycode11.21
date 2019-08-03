#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
//namespace mr
//{
//	class String
//	{
//	public:
//		/*String()
//			:_str(new char[1])
//		{
//			_str[0] = '\0';
//		}*/
//		String(char* str = " ")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//
//		//copy(s1)
//		String(const String& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//
//		String(const String& s)
//			:_str(nullptr)
//		{
//			string tmp(s._str);
//			swap(_str, tmp._str);
//		}
//
//
//		//s3 = s2
//		String& operator=(const String& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//			return *this;
//		}
//		String& operator=(const String& s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		char* c_str()
//		{
//			return _str;
//		}
//		size_t Size()
//		{
//			return strlen(_str);
//		}
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		~String()
//		{
//			if (_str)
//			{
//				delete[] _str;
//			}
//		}
//	private:
//		char* _str;
//	};
//	void TestString()
//	{
//		String s1;
//		String s2("hello");
//		s2[0] = 'x';
//		for (size_t i = 0; i < s2.Size(); i++)
//		{
//			cout << s2[i] << " ";
//		}
//		cout << endl;
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//	}
//	void TestString2()
//	{
//		//String s1("hello");
//		//String copy(s1);//使用默认生成的拷贝构造，是浅拷贝值拷贝
//		////被析构两次，程序会崩
//		//cout << s1.c_str() << endl;//深拷贝：开一段一样大的空间，再拷贝数据
//		//cout << copy.c_str() << endl;
//
//		String s4("hello");
//		String s5("word");
//		s4 = s5;
//		cout << s4.c_str() << endl;
//	}
//}

namespace mr
{
	class String
	{
	public:
		//friend ostream& operator<<(ostream& out, const String& s);
		typedef char* iterator;
		typedef char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		String(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		void Swap(String& s)
		{
			swap(this->_str, s._str);
			swap(this->_size, s._size);
			swap(this->_capacity, s._capacity);
		}
		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}

		//s1 = s
		String& operator=(String s)
		{
			this->Swap(s);
			return *this;
		}

		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		size_t Size()
		{
			return _size;
		}
		size_t Capacity()
		{
			return _capacity;
		}
		void Reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void Resize(size_t n, char ch = '\0');

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void PushBack(char ch)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 15 : _capacity * 2;
				Reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void PopBack()
		{
			assert(_size > 0);
			--_size;
			_str[_size] = '\0';
		}
		void Append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				Reserve(_size + len);
			}
			strcpy(_str+_size, str);
			_size += len;
		}
		String& operator+=(char ch)
		{
			PushBack(ch);
			return *this;
		}
		String& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
		size_t Find(char ch,size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return npos;
		}
		size_t RFind(char ch,size_t pos = npos)
		{
			size_t i = pos == npos ? _size : pos + 1;
			for( ; i > 0; --i)
			{
				if (ch == _str[i-1])
					return i-1;
			}
			return npos;
		}
		String Substr(size_t pos, size_t len)
		{
			String s;
			while (pos < _size && len--)
			{
				s += _str[pos++];
			}
			return s;
		}


		size_t Find(const char* str,size_t pos)
		{
			const char* start = strstr(_str+pos, str);
			if (start)
			{
				return start - _str;
			}
			else
				return npos;
		}
		
		void Insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			size_t end = _size - 1;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
		}
		void Insert(size_t pos, const char*str);
		void Erase(size_t pos, size_t len);
		bool operator>(const String& s1);


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		public:
		static const size_t npos;
	};
	const size_t String::npos = -1;
	String operator+(const String& s1, const String& s2)
	{
		String s = s1;
		s += s2.c_str();
		return s;
	}

	String operator+(const String& s1, const char* str)
	{
		String s = s1;
		s += str;
		return s;
	}
	ostream& operator<<(ostream& out, const String& s)
	{
		//cout << s.c_str();
		for (auto ch : s)
		{
			cout << ch;
		}
		return out; 
	}
	void TestString()
	{
		String s1("hello");
		for (size_t i = 0; i < s1.Size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		String::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;

	}

	void TestString2()
	{
		String s;
		s.PushBack(' ');
		s.Append("hello");
		s.PushBack(' ');
		s.Append("word ");
		s.Append("word ");
		s.Append("word ");
		for (auto ch : s)
		{
			cout << ch << " ";
		}
		cout << endl;
		cout << s << endl;

	}
	void  TestString3()
	{
		String s = "hello\\0world";
		/*s += '\0';
		s += "world";*/
		cout << s << endl;
	}
}


char* strstr( char* str, char* sub)
{
	char* pstr = str, *psub = sub;
	while (*pstr)
	{
		if (*pstr == *psub)
		{
			char* matchstr = pstr;
			char* matchsub = psub;
			while (*matchsub&&*matchsub&& *matchsub++ == *matchstr++);
			if (*matchsub == '\0')
				return pstr;
			
			}
			++pstr;
		
	}
	return NULL;
}
int main()
{
	char* s1 = "hello";
	char* s2 = "hellworldhello";
	strstr(s1, s2);
	return 0;
}
