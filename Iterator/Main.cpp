#include <iostream>
using namespace std;

class A {
public:
	class B {
	public:
		B(A &a) : m_a(a) {}
	public:
		void Print() {
			cout << m_a.m_i << endl;
		}
	private:
		A &m_a;
	};
public:
	A(int i) : m_i(i) {}
private:
	int m_i;
};


int main() {
	A a(5);
	A::B b(a);
	b.Print();
}
