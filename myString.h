#pragma once
#include <ostream>
using namespace std;
class myString {
private:
	char* p;					// ָ��洢�ַ������ڴ�ռ�
	int len;					// �����ַ�������
	int size;					// ����������ڴ�ռ�ĳ���
	const int max_size = 65536;	// ��󳤶�
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

