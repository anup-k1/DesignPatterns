#include <memory>
#include <crtdbg.h>
using namespace std;

#include "factory-method.h"

int main() {
	{
		unique_ptr<RealAdderFactory>
			realAdderFactory(new RealAdderFactory);

		unique_ptr<RealAdderBase>
			realAdder(realAdderFactory->CreateRealAdder());

		double u = 1.0, v = 2.0, result = 0.0;
		result = realAdder->Add(u, v);
	}
	_CrtDumpMemoryLeaks();
}