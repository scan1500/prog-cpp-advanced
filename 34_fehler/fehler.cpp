#include <iostream>
#include <string>
using namespace std;

string strToUpper(const string &s1);

void main()
{
	const string s = "hallo";
	cout << strToUpper(s);

	cin.peek();
}

string strToUpper(const string &s1)
{
	string s2 = " ";

	for (int i = 0; i < s1.length(); i++)
		s2 += toupper(s1[i]);

	return s2;
}