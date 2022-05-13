#include <iostream>
using namespace std;

class Expression {
public:
	virtual double evaluate() = 0;
	virtual ~Expression() {}
};

class Number : public Expression {
private:
	double val_;

public:
	Number(double val) : val_(val) {}
	virtual double evaluate() override { return val_; }
};

class BinaryOperation : public Expression {
private:
	Expression* left_;
	Expression* right_;
	char type_oper_;

public:
	BinaryOperation(Expression* left, char type, Expression* right) : left_(left),
		type_oper_(type),
		right_(right) {}

	virtual double evaluate() override {
		switch (type_oper_) {
		case '+' :
			return left_->evaluate() + right_->evaluate();

		case '-':
			return left_->evaluate() - right_->evaluate();

		case '*':
			return left_->evaluate() * right_->evaluate();

		case '/':
			return left_->evaluate() / right_->evaluate();
		}
	}
	
	~BinaryOperation() { delete left_; delete right_; }
};

int main() {
	// ������� ������ ������� ��� ������������ 4.5 * 5
	Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	// ����� ���������� ��� � ��������� ��� +
	Expression* expr = new BinaryOperation(new Number(3.0), '+', sube);

	// ��������� � ������� ���������: 25.5
	std::cout << expr->evaluate() << std::endl;

	// ��� ������������� *���* ���������� �������
	// (��������, sube ����� ������ ��������� expr, ������� ��� ������� �� �����)
	delete expr;
	return 0;
}