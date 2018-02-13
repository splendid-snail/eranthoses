#include <iostream>
#include <vector>
#include <string>

using namespace std;

void checkInput() {
	if (!cin) {
		throw runtime_error("invalid input");
	}
}

void setNewPrime(const vector<int>& list, int& currentPrime, bool& doneSearching) {
	for (size_t i = 0; i < list.size(); ++i) {
		if (list[i] != 0 && list[i] > currentPrime) {
			currentPrime = list[i];
			return;
		}
	}
	// we have reached the end of the list without setting a new prime, so we are done 
	doneSearching = true;
}

void setPrimesToZero(vector<int>& ourList, int currentPrime) {
	for (size_t i = 0; i < ourList.size(); ++i) {
		if (ourList[i] != currentPrime && ourList[i] % currentPrime == 0) {
			ourList[i] = 0;
		}
	}
}

void findPrimes() { // the real "main" function	
	vector<int> ourList;	
	int start = 2;	
	int currentPrime = 2;
	int limit = 100;
	bool doneSearching = false;

	cin >> limit;	
	checkInput();	

	//Fill the vector with numbers
	for (int i = start; i <= limit; ++i) {
		ourList.push_back(i);
	}

	//Main search loop
	while (!doneSearching) {
		setPrimesToZero(ourList, currentPrime);
		setNewPrime(ourList, currentPrime, doneSearching);
	}

	cout << '\n';
	cout << "Done! Here are your primes:\n\n";
	for (size_t i = 0; i < ourList.size(); ++i) {
		if (ourList[i] > 0) {
			cout << ourList[i] << '\n';
		}
	}
}

int main() {
	try {
		cout << "I'll find all the primes up to your limit.\n";

		bool donePriming = false;

		while (!donePriming) {
			cout << "Enter your limit:\n>";
			findPrimes();
			cout << "\nEnter x to quit, anything else for another round:\n>";
			string in;
			cin >> in;
			checkInput();
			if (in == "x") {
				donePriming = true;
			}
		}

		cout << "Thanks for primin'.\n";
		return 0;
	}
	catch (const runtime_error& e) {
		cerr << "Runtime error: " << e.what() << '\n';	
		return 1;
	}
}