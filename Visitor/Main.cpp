// forward declaration
class MetricsCalculator;

// Element
class Shape {
public:
	virtual double Invoke(MetricsCalculator &mc) = 0;
};

// ConcreateElementA
class Rectangle : public Shape {
public:
	Rectangle(int x1, int y1, int x2, int y2)
		: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}
public:
	int GetX1() const { return m_x1; }
	int GetY1() const { return m_y1; }
	int GetX2() const { return m_x2; }
	int GetY2() const { return m_y2; }
public:
	double Invoke(MetricsCalculator &mc);
private:
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
};

// ConcreateElementB
class Circle : public Shape {
public:
	Circle(int r) : m_r(r) {}
public:
	int GetR() const { return m_r; }
public:
	double Invoke(MetricsCalculator &mc);
private:
	int m_r;
};

// Visitor
class MetricsCalculator {
public:
	virtual double Compute(const Rectangle &r) = 0;
	virtual double Compute(const Circle &c) = 0;
};

// ConcreteVisitor1
class AreaCalculator : public MetricsCalculator {
public:
	double Compute(const Rectangle &r) {
		double l = r.GetX2() - r.GetX1();
		double b = r.GetY2() - r.GetY1();
		return l * b;
	}
	double Compute(const Circle &c) {
		return 3.14 * c.GetR() * c.GetR();
	}
};

// ConcreteVisitor2
class PerimeterCalculator : public MetricsCalculator {
public:
	double Compute(const Rectangle &r) {
		double l = r.GetX2() - r.GetX1();
		double b = r.GetY2() - r.GetY1();
		return 2 * (l + b);
	}
	double Compute(const Circle &c) {
		return 2 * 3.14 * c.GetR();
	}
};

double Rectangle::Invoke(MetricsCalculator & mc)
{
	return mc.Compute(*this);
}

double Circle::Invoke(MetricsCalculator & mc)
{
	return mc.Compute(*this);
}

int main() {
	double result = 0.0;
	Rectangle r(10, 10, 20, 20);
	Circle c(10);

	AreaCalculator ac;
	result = r.Invoke(ac);
	result = c.Invoke(ac);

	PerimeterCalculator pc;
	result = r.Invoke(pc);
	result = c.Invoke(pc);
}
