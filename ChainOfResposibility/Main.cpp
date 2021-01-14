#include <iostream>
using namespace std;

class OperationHandler {
public:
	virtual bool Handle(char op, double u, double v, double &result) = 0;
};

class AdditionHandler : public OperationHandler {
public:
	AdditionHandler(OperationHandler &successor) : m_successor(successor) {}
public:
	bool Handle(char op, double u, double v, double &result) {
		if (op == '+')
			result = u + v;
		else
			return m_successor.Handle(op, u, v, result);
		return true;
	}
private:
	OperationHandler &m_successor;
};

class SubtractionHandler : public OperationHandler {
public:
	SubtractionHandler(OperationHandler &successor) : m_successor(successor) {}
public:
	bool Handle(char op, double u, double v, double &result) {
		if (op == '-')
			result = u - v;
		else
			return m_successor.Handle(op, u, v, result);
		return true;
	}
private:
	OperationHandler &m_successor;
};

class MultiplicationHandler : public OperationHandler {
public:
	MultiplicationHandler(OperationHandler &successor) : m_successor(successor) {}
public:
	bool Handle(char op, double u, double v, double &result) {
		if (op == '*')
			result = u * v;
		else
			return m_successor.Handle(op, u, v, result);
		return true;
	}
private:
	OperationHandler &m_successor;
};

class InvalidOperationHandler : public OperationHandler {
public:
	bool Handle(char op, double u, double v, double &result) {
		return false;
	}
};

int main() {
	InvalidOperationHandler invalidOperationHandler;
	MultiplicationHandler multiplicationHandler(invalidOperationHandler);
	SubtractionHandler subtractionHandler(multiplicationHandler);
	AdditionHandler additionHandler(subtractionHandler);
	OperationHandler &operationHandler = additionHandler;

	char op;
	double u = 0.0, v = 0.0, result = 0.0;

	cout << "Enter first number: ";
	cin >> u;

	cout << "Enter second number: ";
	cin >> v;

	cout << "Enter operator [+ - * /]: ";
	cin >> op;

	bool success = operationHandler.Handle(op, u, v, result);
}
