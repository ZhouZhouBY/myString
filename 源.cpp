#include "myString.h"
#include <iostream>

using namespace std;

int main() {
	myString a;
	cout << "please input a: ";
	cin >> a;								  // 测试>>
	cout << "a: " << a << endl;
	myString b("cool!");					  // 测试构造函数
	cout << "b: " << b << endl;
	myString c = a + b;						  // 测试+和=

	cout << "c[0]: " << c[0] << endl;		  // 测试<<和[]
	c += a;									  // 测试myString类型+=
	cout << "c: " << c << endl;
	char tmp[10] = "hello";
	b += tmp;								  // 测试char*类型+=
	cout << "b: " << endl;
	string str = "world";					  // 测试string类型+=
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