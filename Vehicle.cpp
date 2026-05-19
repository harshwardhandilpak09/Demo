// #include <iostream>
// #include <limits>
// using namespace std;

// class Vehicle {
// public:
//     virtual void gearChange() = 0;
//     virtual void speedUp() = 0;
//     virtual void applyBrakes() = 0;
//     virtual ~Vehicle() {}
// };

// class Bicycle : public Vehicle {
// public:
//     void gearChange() {
//         cout << "Bicycle: Manual gear change\n";
//     }
//     void speedUp() {
//         cout << "Bicycle: Pedaling faster\n";
//     }
//     void applyBrakes() {
//         cout << "Bicycle: Applying hand brakes\n";
//     }
// };

// class Bike : public Vehicle {
// public:
//     void gearChange() {
//         cout << "Bike: Gear changed using foot pedal\n";
//     }
//     void speedUp() {
//         cout << "Bike: Increasing throttle\n";
//     }
//     void applyBrakes() {
//         cout << "Bike: Applying disc brakes\n";
//     }
// };

// class Car : public Vehicle {
// public:
//     void gearChange() {
//         cout << "Car: Gear changed using gear lever\n";
//     }
//     void speedUp() {
//         cout << "Car: Pressing accelerator\n";
//     }
//     void applyBrakes() {
//         cout << "Car: Applying brake pedal\n";
//     }
// };

// int main() {
//     Vehicle* v = nullptr;
//     int choice;

//     while (true) {
//         cout << "\nChoose Vehicle:\n1. Bicycle\n2. Bike\n3. Car\nEnter choice: ";
//         cin >> choice;

//         if (cin.fail() || (choice < 1 || choice > 3)) {
//             cout << "Invalid choice! Enter 1, 2 or 3.\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else break;
//     }

//     if (choice == 1)
//         v = new Bicycle();
//     else if (choice == 2)
//         v = new Bike();
//     else
//         v = new Car();

//     v->gearChange();
//     v->speedUp();
//     v->applyBrakes();

//     delete v;
//     return 0;
// }

// Design and implement an interface for Vehicles to represent common functionalities. 
// Consider vehicles such as Bicycle, Bike, and Car, which share the following 
// functionalities:
// • gearChange()
// • speedUp()
// • applyBrakes()
// Create an interface Vehicle that declares these methods. Implement the interface in the 
// classes Bicycle, Bike, and Car, providing custom implementations for each method 
// according to the specific vehicle type

#include<bits/stdc++.h>
using namespace std;

class Vehicle 
{
	public:
	virtual void gearChange() = 0;
	virtual void speedUp() = 0;
	virtual void applyBrakes() = 0;
	virtual ~Vehicle() {}
 };
 
class Bicycle : public Vehicle 
{
	public :
	void gearChange()
	{
		cout<<"Bicycle gear!"<<endl;
	}
	void speedUp()
	{
		cout<<"Bicycle speed!"<<endl;
	}
	void applyBrakes()
	{
		cout<<"Brakes!"<<endl;
	}
}

int main()
{
	Vehicle* v;
	
	v = new Bicycle();
	
	v->gearChange();
	v->speedUp();
	v->applyBrakes();
	return 0;
}
