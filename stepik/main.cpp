#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int get_order(char const* str) {
	int n = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9') {
			++n;
		}
		else {
			return n;
		}
		++str;
	}
	return n;
}

int my_atoi(char const* str) {
	return get_order(str);
}

int main() {
	string str;
	while (cin >> str) {
		cout << get_order(str.c_str()) << endl;
	}
	return 0;
}