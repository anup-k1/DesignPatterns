#include <vector>
#include <iostream>
using namespace std;

class PatternViewer {
public:
	virtual void Update() = 0;
};

class Data {
public:
	void Attach(PatternViewer &patternViewer) {
		m_patternViewers.push_back(&patternViewer);
	}
	void Notify() {
		for (auto patternViewer : m_patternViewers) {
			patternViewer->Update();
		}
	}
private:
	vector<PatternViewer*> m_patternViewers;
};

class PatternData : public Data {
public:
	unsigned GetData() { return m_i; }
	void SetData(unsigned i) {
		m_i = i;
		Notify();
	}
private:
	unsigned m_i;
};

class StarPatternViewer : public PatternViewer {
public:
	StarPatternViewer(PatternData &patternData) : m_patternData(patternData) {}
public:
	void Update() {
		for (unsigned int i = 0; i < m_patternData.GetData(); i++)
			cout << '*' << flush;
		cout << endl;
	}
private:
	PatternData &m_patternData;
};

class HashPatternViewer : public PatternViewer {
public:
	HashPatternViewer(PatternData &patternData) : m_patternData(patternData) {}
public:
	void Update() {
		for (unsigned int i = 0; i < m_patternData.GetData(); i++)
			cout << '#' << flush;
		cout << endl;
	}
private:
	PatternData &m_patternData;
};

int main() {
	PatternData patterData;
	StarPatternViewer starPatternViewer(patterData);
	HashPatternViewer hashPatternViewer(patterData);
	patterData.Attach(starPatternViewer);
	patterData.Attach(hashPatternViewer);

	patterData.SetData(5);

	system("pause");
	
	system("cls");
	patterData.SetData(10);

	system("pause");
}
