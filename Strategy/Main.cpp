#include <cstdlib>
#include <assert.h>

class DataSet;

class IDataProvider {
public:
	virtual void Fill(DataSet &ds) = 0;
};

class DataSet {
public:
	DataSet(IDataProvider &dataProvider) : m_pdataProvider(&dataProvider) {}
public:
	int GetMaxSize() const { return m_maxsize; }
	void SetValue(int index, int value) {
		assert(index < m_maxsize);
		m_values[index] = value;
	}
	void SetDataProvider(IDataProvider &dataProvider) {
		m_pdataProvider = &dataProvider;
	}
public:
	void Fill() {
		m_pdataProvider->Fill(*this);
	}
private:
	static const int m_maxsize = 10;
private:
	int m_values[m_maxsize];
private:
	IDataProvider *m_pdataProvider;
};

class SequentialDataProvider : public IDataProvider {
public:
	void Fill(DataSet &ds) {
		for (int i = 0; i < ds.GetMaxSize(); ++i) {
			ds.SetValue(i, i + 1);
		}
	}
};

class RandomDataProvider : public IDataProvider {
public:
	void Fill(DataSet &ds) {
		for (int i = 0; i < ds.GetMaxSize(); ++i) {
			ds.SetValue(i, rand() % 100);
		}
	}
};

int main() {
	SequentialDataProvider sequentialDataProvider;
	DataSet ds(sequentialDataProvider);
	int maxsize = ds.GetMaxSize();
	ds.Fill();

	RandomDataProvider randomDataProvider;
	ds.SetDataProvider(randomDataProvider);
	ds.Fill();
}
