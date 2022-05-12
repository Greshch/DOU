#include <iostream>
#include <string>
#include <istream>
using namespace std;

class Person {
protected:
	string name_;
	int age_;

public:
	Person(string const& name, int age) : name_(name), age_(age){}
	Person() : Person("none", 0) {}
	string const& name() const { return name_; }
	int age() const { return age_; }
	virtual ~Person() {}
	friend ostream& operator<<(ostream& os, Person const& obj);
};

class Student : public Person {
protected:
	string uni_;

public:
	Student(string const& name, int age, string const& univercity) :
		Person(name, age), uni_(univercity) {}
	Student() : Person(), uni_("none") {}
	string const& univercity() const { return uni_; }
	virtual ~Student() {}
	friend ostream& operator<<(ostream& os, Student const& obj);
};

int main() {
	Person* p = new Person("Abrek Durov", 45);
	cout << *p << endl;
	delete p;
	p = new Student("Bill Geyts", 19, "Briston");
	cout << *p << endl;
	delete p;
	return 0;
}

ostream& operator<<(ostream& os, Person const& obj)
{
	// TODO: вставьте здесь оператор return
	os << "Person::{name=\'" << obj.name() << "\', age=" << obj.age() << "}";
	return os;
}

ostream& operator<<(ostream& os, Student const& obj)
{
	// TODO: вставьте здесь оператор return
	Person const& tmp = obj;
	os << tmp << " univercity: " << obj.univercity();
	return os;
}
