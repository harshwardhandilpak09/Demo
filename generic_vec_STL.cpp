#include<bits/stdc++.h>
using namespace std;

class InvalidChoice : public exception {
public:
	string msg;
	InvalidChoice(string m) { 
		msg = m; 
		}
	~InvalidChoice() throw() {}
};

class InvalidInput : public exception {
public:
	string msg;
	InvalidInput(string m) { 
		msg = m; 
		}
	~InvalidInput() throw() {}
};

class NegativeNumber : public exception {
public:
	string msg;
	NegativeNumber(string m) {
		msg = m; 
		}
	~NegativeNumber() throw() {}
};

bool isEven(int n) { 
	
	return n % 2 == 0; 
	}
bool isOdd(int n) { 
	return n % 2 != 0; 
}

bool isPrime(int n) {
	if (n < 0) throw NegativeNumber("Negative not allowed for prime!");

	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool isPalindrome(int n) {
	string digit = to_string(n);
	string rev = digit;
	reverse(rev.begin(), rev.end());
	
	return digit == rev;
}

class Counter {
public:
	static int objectCount;
	Counter() { objectCount++; }
};

int Counter::objectCount = 0;

int main() {
	vector<int> data;
	int choice;

	while (true) {
		cout << "\n--- MENU ---\n";
		cout << "1. Insert Elements into Vector\n";
		cout << "2. Update Element in Vector\n";
		cout << "3. Count Properties\n";
		cout << "4. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input!\n";
			continue;
		}

		switch (choice) {
		case 1:
			try {
				int n;
				cout << "Enter number of elements: ";
				cin >> n;

				if (cin.fail() || n <= 0)
					throw InvalidInput("Invalid size!");

				

				cout << "Enter elements:\n";
				for (int i = 0; i < n; i++) {
					int val;
					cin >> val;

					if (cin.fail())
						throw InvalidInput("Invalid element!");

					data.push_back(val);
				}
				cout << "Elements inserted successfully!\n";
			}
			catch (InvalidInput &e) {
				cout << e.msg << endl;
			}
			break;
		case 2:
			try {
				if (data.empty())
					throw InvalidInput("Vector is empty!");

				int index, value;

				cout << "Enter index to update: ";
				cin >> index;

				cout << "Enter new value: ";
				cin >> value;

				if (cin.fail())
					throw InvalidInput("Invalid input!");

				data.at(index) = value;

				cout << "Element updated!\n";
			}
			catch (InvalidInput &e) {
				cout << e.msg << endl;
			}
			catch (out_of_range &) {
				cout << "Index out of range!\n";
			}
			break;
		case 3:
			try {
				if (data.empty())
					throw InvalidInput("Vector is empty!");

				int prop;
				cout << "\n1. Even\n2. Odd\n3. Prime\n4. Palindrome\n";
				cout << "Enter property choice: ";
				cin >> prop;

				int count = 0;

				switch (prop) {
					case 1:
						for (int x : data)
							if (isEven(x)) count++;
						break;

					case 2:
						for (int x : data)
							if (isOdd(x)) count++;
						break;

					case 3:
						for (int x : data)
							if (isPrime(x)) count++;
						break;

					case 4:
						for (int x : data)
							if (isPalindrome(x)) count++;
						break;

					default:
						throw InvalidChoice("Invalid property choice!");
				}

				Counter obj;

				cout << "Count = " << count << endl;
				cout << "Objects created: " << Counter::objectCount << endl;
			}
			catch (InvalidChoice &e) {
				cout << e.msg << endl;
			}
			catch (InvalidInput &e) {
				cout << e.msg << endl;
			}
			catch (NegativeNumber &e) {
				cout << e.msg << endl;
			}
			break;

		case 4:
			return 0;

		default:
			cout << "Invalid menu choice!\n";
		}
	}
}