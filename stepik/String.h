#pragma once
#include <ostream>
#include <iostream>
using namespace std;

class String
{
private:
	size_t size = 0;
	char* str = nullptr;

public:
	String(char const* text = "");
	String(size_t n, char ch);
	String(String const& other);
	String& operator=(String& other);
	String& operator=(char const* s);
	String operator+(String& other);
	String& operator+=(String& other);
	String operator+(char const* s);
	String& operator+=(char const* s);
	friend ostream& operator<< (ostream& os, String const& s);
	String& append(String& other);
	~String();

private:
	void Clear();
	void Swap(String& other);
};

