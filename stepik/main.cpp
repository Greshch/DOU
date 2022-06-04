#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
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
	int sum = 0;
	int n = get_order(str);
	int order = pow(10, n - 1);
	//return order;
	int tmp = order;
	for (size_t i = 0; i < n; i++)
	{
		int cur = order * (str[i] - '0');
		//cout << cur << "# ";
		sum += cur;
		order /= 10;
	}
	return sum;
}

int main() {
	string str;
	while (cin >> str) {
		cout << my_atoi(str.c_str()) << endl;
	}
	return 0;
}