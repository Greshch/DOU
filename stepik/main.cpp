#include <iostream>
#include "String.h"
using namespace std;

int main() {
	String s = String("hello, ");
	cout << s << endl;
	String s1("world!!");
	s.append(s1);
	cout << s << endl;
	s.append(s);
	cout << s << endl;
	return 0;
}