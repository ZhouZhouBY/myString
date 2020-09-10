#include "myString.h"
#include <string.h>

#include <cassert>
#include <iostream>
#pragma warning(disable:4996)

myString::myString() {
	size = 1;
	data = new char[size + 1];
	data[0] = '\0';
	len = 0;
}

//myString::myString(const char* s)//通用构造函数
//{
//	if (!s)
//	{
//		size = 1;
//		data = new char[1];
//		*data = '\0';
//		len = 0;
//	} else
//	{
//		len = strlen(s);
//		data = new char[len + 1];
//		strcpy(data, s);
//	}
//}

myString::myString(const char* s) {
	size = 1;
	len = strlen(s);
	if (len > max_size) {
		len = max_size;
	}
	while (size < len) {
		size *= 2;
	}

	data = new char[size + 1];
	if (data == NULL) {
		cout << "data is null" << endl;
	}
	strncpy(data, s, size);
	data[size] = '\0';
}
 
myString::myString(const myString& s) {
	size = s.size;
	data = new char[size + 1];
	strcpy(data, s.data);
	len = s.len;
}

myString::~myString() {
	delete[] data;
	len = 0;
}

ostream& operator<< (ostream& out, const myString& s) {
	out << s.data;
	return out;
}

istream& operator>> (istream& in, myString& s) {
	char p[1000];
	in >> p;
	s.size = strlen(p);
	s.len = strlen(p);
	s.data = new char[s.len + 1];
	strcpy(s.data, p);
	return in;
}

myString& myString::operator= (const myString& s) {
	if (&s == this) {
		return *this;
	}
	delete[] data;
	size = s.size;
	data = new char[size + 1];
	strncpy(data, s.data, s.len);
	data[s.len] = '\0';
	len = s.len;
	return *this;
}


char& myString::operator[] (const int index) {
	assert(index >= 0 && index < len);
	return data[index];
}

myString& myString::operator+= (const string& s) {
	len += s.length();
	len = len > max_size ? max_size : len;
	if (size > len) {
		strncat(data, s.c_str(), size - strlen(data));
		data[size] = '\0';
		return *this;
	}
	while (size < len) {
		size *= 2;
	}
	char* tmp = new char[size + 1];
	strncpy(tmp, data, strlen(data));
	tmp[strlen(data)] = '\0';
	strncat(tmp, s.c_str(), size - strlen(data));
	tmp[size] = '\0';
	delete[] data;
	data = tmp;
	return *this;
}

myString& myString::operator+= (const myString& s) {
	len += s.len;
	len = len > max_size ? max_size : len;
	if (size > len) {
		strncat(data, s.data, size - strlen(data));
		data[size] = '\0';
		return *this;
	}
	while (size < len) {
		size *= 2;
	}
	char* tmp = new char[size + 1];
	strncpy(tmp, data, strlen(data));
	tmp[strlen(data)] = '\0';
	strncat(tmp, s.data, size - strlen(data));
	tmp[size] = '\0';
	delete[] data;
	data = tmp;
	return *this;
}

myString& myString::operator+= (const char* s) {
	len += strlen(s);
	len = len > max_size ? max_size : len;
	if (size > len) {
		strncat(data, s, size - strlen(data));
		data[size] = '\0';
		return *this;
	}
	while (size < len) {
		size *= 2;
	}
	char* tmp = new char[size + 1];
	strncpy(tmp, data, strlen(data));
	tmp[strlen(data)] = '\0';
	strncat(tmp, s, size - strlen(data));
	tmp[size] = '\0';
	delete[] data;
	data = tmp;
	return *this;
}

bool myString::operator== (const myString& s) const {
	if (len != s.len) {
		return false;
	}
	return strcmp(data, s.data) ? false : true;
}

myString myString::operator+ (const myString& s) const{
	myString str;
	str.size = s.size + size;
	str.len = s.len + len;
	str.data = new char[str.size + 1];
	strcpy(str.data, data);
	strcat(str.data, s.data);
	return str;
}