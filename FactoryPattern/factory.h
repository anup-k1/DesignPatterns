#pragma once

class RealAdderBase {
public:
	virtual ~RealAdderBase() {}
public:
	virtual double Add(double u, double v) = 0;
};

class RealAdder : public RealAdderBase {
public:
	double Add(double u, double v) { return u + v; }
};

class IRealAdderFactory {
public:
	virtual RealAdderBase* CreateRealAdder() = 0;
};

class RealAdderFactory {
public:
	RealAdderBase* CreateRealAdder() {
		return new RealAdder();
	}
};
