#include "string.h"
#include <string>

int main()
{
	//mr::TestString1();
	//mr::TestString2();
	//mr::TestString();
	//mr::TestString2();

	mr::TestString3();

	string s = "hello";
	s += '\0';
	s += "world";
	cout << s << endl;
	system("pause");
	return 0;
}
