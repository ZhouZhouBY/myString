#pragma once
#include <ostream>
using namespace std;
class myString {
private:
	char* p;					// 指向存储字符串的内存空间
	int len;					// 保存字符串长度
	int size;					// 保存申请的内存空间的长度
	const int max_size = 65536;	// 最大长度
public:
	myString();
	myString(const char* s);
	myString(const myString& s);

	~myString();

	friend ostream& operator<< (ostream& out, const myString& s);
	myString& operator= (const myString& s);
	/*char& operator= (const char& s);*/
	char& operator[] (const int index);
	myString& operator+=(const char* s);
	myString& operator+=(const myString& s);
	myString& operator+=(const string& s);
};

