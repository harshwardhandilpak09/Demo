#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    int rollno;
    string name;
    int m1, m2, m3, m4, m5;
    float percent;
    string division;

    static int totalStudents;

public:
    Student() {
        rollno = 0;
        name = "";
        m1 = m2 = m3 = m4 = m5 = 0;
        percent = 0;
        division = "";
        totalStudents++;
    }
    
//    Student(int rollno, string name, int m1, int m2, int m3, int m4, int m5){
//    	this.rollno = rollno;
//    	this.name = name;
//    	this.m1 = m1;
//    	this.m2 = m2;
//    	this.m3 = m3;
//    	this.m4 = m4;
//    	this.m5 = m5;
//	}

    void getData() {
        while (true) {
            cout << "\nRoll Number: ";
            cin >> rollno;
            if (cin.fail() || rollno <= 0) {
                cout << "Invalid Roll Number!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                break;
            }
        }

        while (true) {
            cout << "Name: ";
            cin >> name;
            bool hasDigit = false;
            for (int i = 0; i < name.size(); i++) {
                if (isdigit(name[i])) {
                    hasDigit = true;
                    break;
                }
            }
            if (hasDigit || name.empty()) {
                cout << "Invalid name! No numbers allowed.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Marks 1: ";
            cin >> m1;
            if (cin.fail() || m1 < 0 || m1 > 100) {
                cout << "Invalid! Enter between 0 and 100.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }

        while (true) {
            cout << "Marks 2: ";
            cin >> m2;
            if (cin.fail() || m2 < 0 || m2 > 100) {
                cout << "Invalid! Enter between 0 and 100.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }

        while (true) {
            cout << "Marks 3: ";
            cin >> m3;
            if (cin.fail() || m3 < 0 || m3 > 100) {
                cout << "Invalid! Enter between 0 and 100.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }

        while (true) {
            cout << "Marks 4: ";
            cin >> m4;
            if (cin.fail() || m4 < 0 || m4 > 100) {
                cout << "Invalid! Enter between 0 and 100.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }

        while (true) {
            cout << "Marks 5: ";
            cin >> m5;
            if (cin.fail() || m5 < 0 || m5 > 100) {
                cout << "Invalid! Enter between 0 and 100.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }
    }

    void calculatePercentage() {
        int total = m1 + m2 + m3 + m4 + m5;
        percent = total / 5.0;
    }

    void grade() {
        if (percent >= 90) {
		division = "A";
		}
        else if (percent >= 80) {
         division = "B";
        	
		}
        else if (percent >= 70) {
        	division = "C";
		}
        else if (percent >= 60) {
        	division = "D";
		}
        else {
        	division = "E";
		}
    }

    void display() {
        cout << setw(5) << rollno << setw(10) << name << setw(5) << m1 << setw(5) << m2 << setw(5) << m3 << setw(5) << m4 << setw(5) << m5 << setw(10) << fixed << setprecision(2) << percent<< setw(5) << division << endl;
    }

    static void showTotalStudents() {
        cout << "\nTotal Students: " << totalStudents << endl;
    }

    friend void comparePercentage(const Student& s1, const Student& s2);

    ~Student() {
        totalStudents--;
    }
};

int Student::totalStudents = 0;

void comparePercentage(const Student& s1, const Student& s2) {
    if (s1.percent > s2.percent) {
        cout << "\nStudent 1 has higher percentage: " << s1.percent <<"%"<< endl;
    } else if (s2.percent > s1.percent) {
        cout << "\nStudent 2 has higher percentage: " << s2.percent <<"%"<< endl;
    } else {
        cout << "\nBoth students have equal percentage: " << s1.percent <<"%"<< endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student* students = new Student[n];

    cout << "\nEnter Student Details\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        students[i].getData();
        students[i].calculatePercentage();
        students[i].grade();
    }

    cout << "\n"<< setw(5) << "Roll" << setw(10) << "Name" << setw(5) << "M1" << setw(5) << "M2"<< setw(5) << "M3"<< setw(5) << "M4"<< setw(5) << "M5"<< setw(10) << "Percent"<< setw(5) << "Div" << endl;

    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    Student::showTotalStudents();

    if (n>= 2) {
        comparePercentage(students[0], students[1]);
    }

    delete[] students;
    return 0;
}

