#include "String.h"
#include <cstring>
#include <algorithm>

String::String(char const* text) : size(strlen(text)), 
								str(new char[size + 1])
{
	strcpy_s(str, size + 1, text);
}

String::String(size_t n, char ch) : size(n),
									str(new char[size + 1])
{
	for (size_t i = 0; i < n; i++)
	{
		str[i] = ch;
	}
	str[n] = '\0';
}

String::String(String const& other) :
	String(other.str)
{
}

String& String::operator=(String& other)
{
	// TODO: вставьте здесь оператор return
	if (this != &other)
	{
		String(other).Swap(*this);
	}

	return *this;
}

String& String::operator=(char const* s)
{
	// TODO: вставьте здесь оператор return
	String other = s;
	this->Swap(other);
	return *this;
}

String& String::append(String& other)
{
	size_t new_size = size + other.size;
	char* new_str = new char[new_size + 1];
	strcpy_s(new_str, new_size + 1, str);
	strcpy_s(new_str + size, other.size + 1, other.str);
	delete[] str;
	str = new_str;
	size = new_size;
	return *this;
}

String::~String()
{
	Clear();
}

void String::Clear()
{
	if (str == nullptr)
		return;

	delete[] str;
	str = nullptr;
}

void String::Swap(String& other)
{
	using std::swap;
	swap(this->size, other.size);
	swap(this->str, other.str);
}

ostream& operator<<(ostream& os, String const& s)
{
	os << s.str;
	return os;
}
