#include <vector>
using namespace std;

class Resistor {
public:
	virtual double GetResistance() = 0;
};

class SimpleResistor : public Resistor {
public:
	SimpleResistor(double resistance) : m_resistance(resistance) {}
public:
	double GetResistance() { return m_resistance; }
private:
	double m_resistance;
};

class ResistorCollection : public Resistor {
public:
	void AddResistor(Resistor &resistor) {
		m_resistors.push_back(&resistor);
	}
protected:
	vector<Resistor*>& GetResistors() { return m_resistors; }
private:
	vector<Resistor*> m_resistors;
};

class SerialResistor : public ResistorCollection {
public:
	double GetResistance() {
		double totalResistance = 0.0;
		for (auto presistor : GetResistors()) {
			totalResistance += presistor->GetResistance();
		}
		return totalResistance;
	}
};

class ParallelResistor : public ResistorCollection {
public:
	double GetResistance() {
		double totalResistance = 0.0;
		for (auto presistor : GetResistors()) {
			totalResistance += 1.0/presistor->GetResistance();
		}
		return 1.0 / totalResistance;
	}
};

int main() {
	double result = 0.0;

	SimpleResistor r1(10), r2(20);

	SerialResistor r3;
	r3.AddResistor(r1);
	r3.AddResistor(r2);
	result = r3.GetResistance();

	ParallelResistor r4;
	r4.AddResistor(r1);
	r4.AddResistor(r2);
	result = r4.GetResistance();

	{
		SimpleResistor r1(10), r2(150), r3(25), r4(60), r5(45);
		
		ParallelResistor pr1;
		pr1.AddResistor(r3);
		pr1.AddResistor(r4);

		SerialResistor sr1;
		sr1.AddResistor(r1);
		sr1.AddResistor(r2);
		sr1.AddResistor(pr1);

		ParallelResistor pr2;
		pr2.AddResistor(sr1);
		pr2.AddResistor(r5);

		result = pr2.GetResistance();
	}


}