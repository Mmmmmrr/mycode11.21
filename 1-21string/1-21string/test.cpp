#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
namespace mr
{
	class String
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
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
		//copy (s1)
		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			Swap(tmp);
		}

		//copy == s2
		String& operator=(String s)
		{
			Swap(s);
			return *this;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		~String()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_size = 0;
				_capacity = 0;
			}
		}

		//s1 > s2  hello  world
		bool operator>(const String& s)
		{
			int index = 0;
			while (index != _size || index != s._size)
			{
				if (_size == s._size)
				{
					if (_str[index] == s._str[index])
						++index;
					else if (_str[index] > s._str[index])
						return true;
					else if (_str[index] < s._str[index])
						return false;
					return false;
				}
				else
				{
					if (_str[index] == s._str[index])
						++index;
					else if (_str[index] > s._str[index])
						return true;
					else if (_str[index] < s._str[index])
						return false;
					else if (_size > s._size)
						return true;
					else
						return false;
				}
			}
		}

		bool operator==(const String& s)
		{
			int index = 0;
			if (_size == s._size)
			{
				for (index = 0; index < s._size;)
				{
					if (_str[index] == s._str[index])
						++index;
					else
						return false;
				}
				return true;
			}
			else
				return false;
			
		}


		bool operator<(const String& s)
		{
			return !(*this > s);
		}

		bool operator<=(const String& s)
		{
			return !(*this > s && *this == s);
		}
		bool operator>=(const String& s)
		{
			return (*this > s)&& (*this == s);
		}
		bool operator!=(const String& s)
		{
			return !(*this == s);
		}


		void Reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* str = new char[n + 1];
				strcpy(str, _str);

				delete[] _str;
				_str = str;
				_capacity = n;
			}
		}
		void PushBack(char ch)
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2+1);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void Append(const char* str)
		{
			if (_size == _capacity)
			{
				Reserve(strlen(str)+1+_size);
			}
			strcpy(_str + _size, str);
			_size += strlen(str);
			_str[_size] = '\0';
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

		void Insert(size_t pos, char ch)
		{
			assert(pos > 0 && pos <= _size);
			if (_size == _capacity)
			{
				Reserve(_capacity * 2 + 1);
			}
			size_t end = _size;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
			_str[_size] = '\0';
			
		}

		void Insert(size_t pos, const char* str)
		{
			assert(pos > 0 && pos < _size);
			if (_size == _capacity)
			{
				Reserve(strlen(str) + _size + 1);
			}
			size_t len = strlen(str);
			size_t end = _size;
			while (end > pos)
			{
				_str[end + len - 1] = _str[end - 1];
				--end;
			}
			while (*str)
			{
				_str[pos++] = *str++;
			}
			_size += len;
			_str[_size] = '\0';
		}

		void Erase(size_t pos, size_t len)
		{
			assert(_size > 0);
			if (pos + len >= _size)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				for (size_t i = pos+len; i < _size; ++i)
				{
					_str[pos] = _str[i];
					++pos;
				}
				_size -= len;
				_str[_size] = '\0';
			}
		}

		size_t Find(char ch, size_t pos = 0)//从前往后找一个字符，返回下标
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}

		//abcdbdbdc
		//bdc
		size_t Find(const char* str, size_t pos = 0)//找一个字符串
		{
			const char* start = strstr(_str+pos, str);
			if (str)
			{
				return start - _str;
			}
			return npos;
		}

		char* c_str()
		{
			return _str;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		size_t npos;
	};

	void Test()
	{
		String s1("y");
		String s2("world");
		String copy(s1);
	/*	cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << copy.c_str() << endl;
		cout << (s1 > s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 < s2) << endl;
		s1.PushBack('c');
		cout << s1.c_str() << endl;*/
	/*	s1.Append("aaaaaaaa");
		cout << s1.c_str() << endl;*/
		/*s1 += 'p';
		cout << s1.c_str() << endl;*/
		s2.Insert(4, 'b');
		cout << s2.c_str() << endl;


	}
}
	
    int main()
	{
		mr::Test();
		system("pause");
		return 0;
	}