#include "myString.h"
#include <iostream>

using namespace std;

int main() {
	myString a("hello,world");
	myString b("!!!");
	string c = "qwer";
	char d[10] = "abcde";
	a += b;
	cout << a << endl;
	a += c;
	cout << a << endl;
	a += d;
	cout << a << endl;
	return 0;
}