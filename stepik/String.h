#pragma once
#include <ostream>
#include <iostream>
using namespace std;

class String
{
private:
	size_t size;
	char* str;

public:
	String(char const* text);
	String(size_t n, char ch);
	friend ostream& operator<< (ostream& os, String const& s);
	String& append(String& other);
	~String();

private:
	void Clear();

};

