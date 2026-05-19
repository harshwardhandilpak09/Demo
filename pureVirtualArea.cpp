#include <iostream>
#include <limits>
using namespace std;

//Abstract class
class Shape {
protected:
	double dim1, dim2;

public:
	void input() {
		while (true) {
			cout << "Enter first dimension (positive number): ";
			cin >> dim1;

			if (cin.fail() || dim1 <= 0) {
				cout << "Invalid input! Try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} else break;
		}

		while (true) {
			cout << "Enter second dimension (positive number): ";
			cin >> dim2;

			if (cin.fail() || dim2 <= 0) {
				cout << "Invalid input! Try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} else break;
		}
	}

	// virtual double compute_area() = 0;
	virtual double compute_area() = 0;
	virtual ~Shape() {}
};

class Triangle : public Shape {
public:
	double compute_area() {
		return 0.5 * dim1 * dim2;
	}
};

class Rectangle : public Shape {
public:
	double compute_area() {
		return dim1 * dim2;
	}
};

int main() {
	Shape* shape;
	int choice;

	while (true) {
		cout << "\nChoose Shape:\n1. Triangle\n2. Rectangle\nEnter choice: ";
		cin >> choice;

		if (cin.fail() || (choice != 1 && choice != 2)) {
			cout << "Invalid choice! Enter 1 or 2.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} else break;
	}

	if (choice == 1)
		shape = new Triangle();
	else
		shape = new Rectangle();

	shape->input();

	cout << "Area = " << shape->compute_area() << endl;

	delete shape;
	return 0;
}
