#include "myString.h"
#include <iostream>

using namespace std;

int main() {
	myString a;
	cout << "please input a: ";
	cin >> a;								  // ����>>
	cout << "a: " << a << endl;
	myString b("cool!");					  // ���Թ��캯��
	cout << "b: " << b << endl;
	myString c = a + b;						  // ����+��=

	cout << "c[0]: " << c[0] << endl;		  // ����<<��[]
	c += a;									  // ����myString����+=
	cout << "c: " << c << endl;
	char tmp[10] = "hello";
	b += tmp;								  // ����char*����+=
	cout << "b: " << endl;
	string str = "world";					  // ����string����+=
	a += str;
	cout << a << endl;
	if (a == b) {
		cout << "a == b" << endl;
	}
	else {
		cout << "a != b" << endl;
	}
	return 0;
}