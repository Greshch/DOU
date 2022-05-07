#include "String.h"
#include <cstring>

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

ostream& operator<<(ostream& os, String const& s)
{
	os << s.str;
	return os;
}
