#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <time.h>
using namespace std;
////int main()
////{
////	string s1;
////	string s2("hello");//���εĹ��캯��
////	string s3(10, 'a');
////	string copy(s3);
////	s1 = copy;
////	cout << s1 << endl;
////	cout << s2 << endl;
////	cout << s3 << endl;
////
////	cout << copy << endl;
////	cout << s1 << endl;
////	system("pause");
////	return 0;
////}
//
////int main()
////{
////	//"hello word"
////	string s1;
////	s1.push_back('h');
////	s1.push_back('e');
////	s1.push_back('l');
////	s1.push_back('l');
////	s1.push_back('o');
////	s1.append(" word");
////	cout << s1 << endl;
////	s1 += " hello word";  //+=�����ϵ���push_back��append;
////	s1 += '!';
////	cout << s1 << endl;
////	s1 += s1;
////	cout << s1 << endl;
////
////	string s2;
////	string s3("hello word");
////	string s4(s3, 5);
////	string s5("hello word", 5);
////	cout << s4 << endl;
////	cout << s5 << endl;
////
////
////
////	system("pause");
////	return 0;
////
////}
//
////void test_string()
////{
////	string s("hello");
////	for (int i = 0; i < s.size(); i++)
////	{
////		cout << s[i] << " ";
////	}
////	cout << endl;
////	//������ ��������ͨ��
////	string::iterator it = s.begin();
////	while (it != s.end())//��ʹ��<���Կ���ʹ�ã���������ʹ�ã���Ҫʹ�ã�=��
////	{
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////
////	//fanweifor  ���е��������ײ�����������ʵ��
////	for (auto& ch : s)
////	{
////		ch += 1;
////		cout << ch << " ";
////	}
////	cout << endl;
////
////	for (auto ch : s)
////	{
////		cout << ch << " ";
////	}
////	cout << endl;
////
////
////	vector<int> v(10, 5);
////	vector<int>::iterator vit = v.begin();
////	while (vit != v.end())
////	{
////		cout << *vit << " ";
////		++vit;
////	}
////	cout << endl;
////
////	list<int> l(5, 10);
////	list<int>::iterator lit = l.begin();
////	while (lit != l.end())
////	{
////		cout << *lit << " ";
////		++lit;
////	}
////	cout << endl;
////
////	for (auto e : v)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	for (auto e : l)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	string s1 = "hello";
////	for (size_t i = s1.size(); i > 0; i--)
////	{
////		cout << s1[i - 1] << " ";
////	}
////	cout << endl;
////
////	string::reverse_iterator rit = s1.rbegin();
////	while (rit != s1.rend())
////	{
////		cout << *rit << " ";
////		++rit;
////	}
////	cout << endl;
////
////}
////string ReverseStr(const string& s)
////{
////	string ret;
////	string::const_reverse_iterator it = s.rbegin();
////	while (it != s.rend())
////	{
////		ret += *it;
////		++it;
////	}
////	return ret;
////}
//
//void test_string2()
//{
//	/*string s1("hello");*/
//	/*cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	s1.clear();
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;*/
//
//	//string�������
//	//size_t begin = clock();
//	//string s;
//	//
//	//s.reserve(100000);//���ռ�
//	//cout << s.capacity() << endl;
//	//for (size_t i = 0; i < 1000000; ++i)
//	//{ 
//	//	/*if (s.size() == s.capacity())
//	//	{
//	//		cout << s.capacity() << endl;
//	//	}*/
//	//	s += 'a';
//	//}
//	//size_t end = clock();
//	//cout << end - begin << endl;
//
//
//	string s1("hello");
//	s1.resize(3);//�ı�size
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	//s1.resize(10);//������0 ====��'\0' ��size��ͬ
//	//cout << s1.size() << endl;
//	//cout << s1 << endl;
//	s1.resize(11, 'a');
//	cout << s1.size() << endl;
//	cout << s1 << endl;
//}
//
//void test_string3()
//{
//	string s1 = "hello";
//	string s2("word");
//	/*s1.assign(s2);
//	cout << s1 << endl;*/
//	//s1.insert(0, "aaaa ");
//	//cout << s1 << endl;
//	//s1.erase(0, 5);
//	//cout << s1 << endl;
//	//s2.replace(0, 3, "bbbbbbbb");//���԰�d�����
//	//cout << s2 << endl;
//	swap(s1, s2);
//	cout << s1 << s2 << endl;
//	s1.swap(s2);
//	cout << s1 << s2 << endl;
//
//}
//void test_string4()
//{
//	string s1("hello");
//	cout << s1 << endl;//�Զ������
//	cout << s1.c_str() << endl;//�ַ���ָ��
//
//	string s("123");
//	int num = atoi(s.c_str());
//}
//
//void test_string5()
//{
//	/*string file1("test.cpp");
//	string file2("test.c");
//	string file3("test.cpp.zip");
//
//	size_t pos = file1.rfind('.');
//	if (pos != string::npos)
//	{
//		string suffix(file1, pos);
//		cout << suffix << endl;
//	}
//	pos = file2.rfind('.');
//	if (pos != string::npos)
//	{
//		string suffix(file2, pos);
//		cout << suffix << endl;
//	}
//	pos = file3.rfind('.');
//	if (pos != string::npos)
//	{
//		string suffix(file3, pos);
//		cout << suffix << endl;
//	}*/
//
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	size_t pos = url.find("://");
//	string head = url.substr(0, pos);
//	cout << head << endl;
//	size_t begin = pos + 3;
//	size_t end = url.find('/', pos + 3);
//	string address = url.substr(begin,end-begin);
//		cout << address << endl;
//}
//int main()
//{
//	/*string s2 = "hello";
//	test_string();
//	ReverseStr(s2);*/
//	//test_string2();
//	//test_string3();
//	//test_string4();
//	test_string5();
//
//	system("pause");
//	return 0;
//}


//�ַ������
//class Solution
//{
//public:
//	string addStrings(string num1, string num2)
//	{
//		int index1 = num1.size() - 1;
//		int index2 = num2.size() - 1;
//		string restr;
//		int next = 0;//��λ
//		while (index1 >= 0 || index2 >= 0)
//		{
//			int value1 = 0;
//			int value2 = 0;
//			if (index1 >= 0)
//			{
//				value1 = num1[index1] - '0';
//				--index1;
//			}
//			if (index2 >= 0)
//			{
//				value2 = num2[index2] - '0';
//				--index2;
//			}
//			int addret = value1 + value2 + next;
//			if (addret > 9)
//			{
//				addret -= 10;
//				next = 1;
//			}
//			else
//				next = 0;
//			restr += ('0'+addret);
//		}
//		if (next == 1)
//		{
//			restr += '1';
//		}
//		reverse(restr.begin(), restr.end());
//		return restr;
//	}
//
//};
//int main()
//{
//	string str1("1234");
//	string str2("1");
//	cout << Solution().addStrings(str1, str2) <<endl;
//
//	system("pause");
//	return 0;
//}



string reverseWords(string s) {
	string str;
	string tmp;
	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] != ' ')
		{
			str += s[i];
		}
		else
		{
			reverse(str.begin(), str.end());
			tmp += str;
			tmp += " ";
			str.clear();
		}
		if (i == s.size() - 1)
		{
			reverse(str.begin(), str.end());
			tmp += str;
		}


	}
	return tmp;

}
int main()
{
	string s("Let's take LeetCode contest");
	cout << reverseWords(s) << endl;
	system("pause");
	return 0;
}







