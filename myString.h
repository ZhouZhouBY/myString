#pragma once
#include <ostream>
using namespace std;
class myString {
private:
	char* data;					// 指向存储字符串的内存空间
	int len;					// 保存字符串长度
	int size;					// 保存申请的内存空间的长度
	const int max_size = 65536;	// 最大长度
public:
	myString();
	myString(const char* s);
	myString(const myString& s);

	~myString();

	friend ostream& operator<< (ostream& out, const myString& s);    //重载<<
	friend istream& operator>> (istream& in, myString& s);			 //重载>>
	myString& operator= (const myString& s);                         //重载=
	
	char& operator[] (const int index);                              //重载[]
	myString& operator+=(const char* s);                             //重载+=
	myString& operator+=(const myString& s);
	myString& operator+=(const string& s);
	bool operator==(const myString& s) const;                        //重载==
	myString operator+(const myString& s) const;					 //重载+
};

