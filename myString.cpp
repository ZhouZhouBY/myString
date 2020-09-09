#include "myString.h"
#include <string.h>

#include <cassert>
#pragma warning(disable:4996)

myString::myString() {
	size = 1;
	p = new char[size + 1];
	p[0] = '\0';
	len = 0;
}

myString::myString(const char* s) {
	size = 1;
	len = strlen(s);
	if (len > max_size) {
		len = max_size;
	}
	while (size < len) {
		size *= 2;
	}
	p = new char[size + 1];
	if (p == NULL) {
		
	}
	strncpy(p, s, size);
	p[size] = '\0';
}

myString::myString(const myString& s) {
	size = s.size;
	p = new char[size + 1];
	strcpy(p, s.p);
	len = s.len;
}

myString::~myString() {
	delete[] p;
}

ostream& operator<< (ostream& out, const myString& s) {
	out << s.p;
	return out;
}

myString& myString::operator= (const myString& s) {
	if (&s == this) {
		return *this;
	}
	delete[] p;
	size = s.size;
	p = new char[size + 1];
	strncpy(p, s.p, s.len);
	p[s.len] = '\0';
	len = s.len;
	return *this;
}


char& myString::operator[] (const int index) {
	assert(index >= 0 && index < len);
	return p[index];
}

myString& myString::operator+= (const string& s) {
	len += s.length();
	len = len > max_size ? max_size : len;
	if (size > len) {
		strncat(p, s.c_str(), size - strlen(p));
		p[size] = '\0';
		return *this;
	}
	while (size < len) {
		size *= 2;
	}
	char* tmp = new char[size + 1];
	strncpy(tmp, p, strlen(p));
	tmp[strlen(p)] = '\0';
	strncat(tmp, s.c_str(), size - strlen(p));
	tmp[size] = '\0';
	delete[] p;
	p = tmp;
	return *this;
}

myString& myString::operator+= (const myString& s) {
	len += s.len;
	len = len > max_size ? max_size : len;
	if (size > len) {
		strncat(p, s.p, size - strlen(p));
		p[size] = '\0';
		return *this;
	}
	while (size < len) {
		size *= 2;
	}
	char* tmp = new char[size + 1];
	strncpy(tmp, p, strlen(p));
	tmp[strlen(p)] = '\0';
	strncat(tmp, s.p, size - strlen(p));
	tmp[size] = '\0';
	delete[] p;
	p = tmp;
	return *this;
}

myString& myString::operator+= (const char* s) {
	len += strlen(s);
	len = len > max_size ? max_size : len;
	if (size > len) {
		strncat(p, s, size - strlen(p));
		p[size] = '\0';
		return *this;
	}
	while (size < len) {
		size *= 2;
	}
	char* tmp = new char[size + 1];
	strncpy(tmp, p, strlen(p));
	tmp[strlen(p)] = '\0';
	strncat(tmp, s, size - strlen(p));
	tmp[size] = '\0';
	delete[] p;
	p = tmp;
	return *this;
}