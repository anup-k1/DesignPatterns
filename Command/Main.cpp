#include <iostream>
using namespace std;

#include "..\singleton\Logger.h"

#define Logger Logger::GetInstance()

class Command {
public:
	virtual void Execute() = 0;
};

class CheckOddEvenCommand : public Command {
public:
	void Execute() {
		int n = 0;

		cout << "Enter number: ";
		cin >> n;

		if (n % 2 == 0)
			Logger.Log("Number is even");
		else
			Logger.Log("Number is odd");
	}
};

class CheckPrimeCommand : public Command {
public:
	void Execute() {
		int n = 0;
		bool isPrime = true;

		cout << "Enter number: ";
		cin >> n;

		for (int i = 2; i < n / 2; i++)
			if (n % i == 0) {
				isPrime = false;
				break;
			}

		if (isPrime)
			Logger.Log("Number is prime");
		else
			Logger.Log("Number is not prime");
	}
};

int main() {
	int choice = 0;
	char yn;

	CheckOddEvenCommand checkOddEvenCommand;
	CheckPrimeCommand checkPrimeCommand;
	Command *pcommands[] = { &checkOddEvenCommand, &checkPrimeCommand };

	do {
		system("cls");
		cout << "1. Check if given number is odd or even?" << endl;
		cout << "2. Check if given number is prime?" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter choice: " << flush;
		cin >> choice;

		switch (choice) {
		case 1:
			pcommands[0]->Execute();
			break;
		case 2:
			pcommands[1]->Execute();
			break;
		case 3:
			goto END;
		}

		cout << "Do you want to continue? (Y/N) ";
		cin >> yn;
	
	} while (yn == 'Y' || yn == 'y');

END:
	return 0;

}
