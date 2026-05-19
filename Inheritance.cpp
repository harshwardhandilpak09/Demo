#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
using namespace std;

class Employee {
protected:
    string emp_name;
    int emp_id;
    string address;
    string mailID;
    long long phoneno;

    static int empCount;
    static int usedIDs[1000];   
    static int usedCount;       

public:
    Employee() {
        empCount++;
    }

    bool isValidEmail(string email) {
        const regex pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        return regex_match(email, pattern);
    }

    bool isDuplicateID(int id) {
        for (int i = 0; i < usedCount; i++) {
            if (usedIDs[i] == id)
                return true;
        }
        return false;
    }

    void getEmpData() {
        while (true) {
            cout << "Employee Name : ";
            cin >> emp_name;

            bool hasDigit = false;
            for (char c : emp_name) {
                if (!isalpha(c)) hasDigit = true;
            }

            if (hasDigit)
                cout << "Name can't contain digits! Re-enter.\n";
            else
                break;
        }

        while (true) {
            cout << "Employee ID: ";
            cin >> emp_id;

            if (cin.fail() || emp_id <= 0) {
                cout << "Invalid Emp ID!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (isDuplicateID(emp_id)) {
                cout << "This Employee ID already exists! Enter a unique ID.\n";
            }
            else {
                usedIDs[usedCount++] = emp_id;  
                break;
            }
        }

        cin.ignore();

        while (true) {
            cout << "Employee Address : ";
            getline(cin, address);
            if (address.empty())
                cout << "Address can't be empty!\n";
            else
                break;
        }

        while (true) {
            cout << "Employee MailID : ";
            cin >> mailID;
            if (!isValidEmail(mailID))
                cout << "Invalid Email!\n";
            else
                break;
        }

        while (true) {
            cout << "Employee Phone : ";
            cin >> phoneno;

            long long temp = phoneno;
            int count = 0;
            while (temp > 0) {
                count++;
                temp /= 10;
            }

            if (count != 10)
                cout << "Invalid phone no, Enter 10 digit number!\n";
            else
                break;
        }
    }

    void displayEmpTable() {
        cout << "\n+--------------------------------------------------+\n";
        cout << "|                EMPLOYEE DETAILS                  |\n";
        cout << "+--------------------------------------------------+\n";
        cout << left << setw(20) << "| Name"     << ": " << setw(25) << emp_name  << "|\n";
        cout << left << setw(20) << "| ID"       << ": " << setw(25) << emp_id    << "|\n";
        cout << left << setw(20) << "| Address"  << ": " << setw(25) << address   << "|\n";
        cout << left << setw(20) << "| Mail ID"  << ": " << setw(25) << mailID    << "|\n";
        cout << left << setw(20) << "| Phone"    << ": " << setw(25) << phoneno   << "|\n";
        cout << "+--------------------------------------------------+\n";
    }

    void printSalaryTable(float BP, float DA, float HRA, float PF, float SF, float gross, float net) {
        cout << "\n+--------------------------------------------------+\n";
        cout << "|                 SALARY DETAILS                   |\n";
        cout << "+--------------------------------------------------+\n";
        cout << left << setw(25) << "| Basic Pay"         << ": " << setw(15) << BP    << "|\n";
        cout << left << setw(25) << "| Dearness Allow."   << ": " << setw(15) << DA    << "|\n";
        cout << left << setw(25) << "| House Rent Allow"  << ": " << setw(15) << HRA   << "|\n";
        cout << left << setw(25) << "| Provident Fund"    << ": " << setw(15) << PF    << "|\n";
        cout << left << setw(25) << "| Staff Club Fund"   << ": " << setw(15) << SF    << "|\n";
        cout << "+--------------------------------------------------+\n";
        cout << left << setw(25) << "| Gross Salary"      << ": " << setw(15) << gross << "|\n";
        cout << left << setw(25) << "| Net Salary"        << ": " << setw(15) << net   << "|\n";
        cout << "+--------------------------------------------------+\n";
    }

    static void showCount() {
        cout << "\nTotal Employees Created : " << empCount << endl;
    }

    ~Employee() {}
};

int Employee::empCount = 0;
int Employee::usedIDs[1000];
int Employee::usedCount = 0;

class Programmer : public Employee {
public:
    void generatePaySlip() {
        const float BP = 30000;
        getEmpData();

        float DA = 0.52f * BP;
        float HRA = 0.27f * BP;
        float PF = 0.12f * BP;
        float SF = 0.001f * BP;

        float gross = BP + DA + HRA;
        float net = gross - (PF + SF);

        cout << "\n\n================ PROGRAMMER PAY SLIP ================\n";
        displayEmpTable();
        printSalaryTable(BP, DA, HRA, PF, SF, gross, net);
    }
};

class TeamLead : public Employee {
public:
    void generatePaySlip() {
        const float BP = 50000;
        getEmpData();

        float DA = 0.52f * BP;
        float HRA = 0.27f * BP;
        float PF = 0.12f * BP;
        float SF = 0.001f * BP;

        float gross = BP + DA + HRA;
        float net = gross - (PF + SF);

        cout << "\n\n================ TEAM LEAD PAY SLIP ================\n";
        displayEmpTable();
        printSalaryTable(BP, DA, HRA, PF, SF, gross, net);
    }
};

class AssistantProjectManager : public Employee {
public:
    void generatePaySlip() {
        const float BP = 70000;
        getEmpData();

        float DA = 0.52f * BP;
        float HRA = 0.27f * BP;
        float PF = 0.12f * BP;
        float SF = 0.001f * BP;

        float gross = BP + DA + HRA;
        float net = gross - (PF + SF);

        cout << "\n\n========= ASSISTANT PROJECT MANAGER PAY SLIP =========\n";
        displayEmpTable();
        printSalaryTable(BP, DA, HRA, PF, SF, gross, net);
    }
};

class ProjectManager : public Employee {
public:
    void generatePaySlip() {
        const float BP = 90000;
        getEmpData();

        float DA = 0.52f * BP;
        float HRA = 0.27f * BP;
        float PF = 0.12f * BP;
        float SF = 0.001f * BP;

        float gross = BP + DA + HRA;
        float net = gross - (PF + SF);

        cout << "\n\n================ PROJECT MANAGER PAY SLIP ================\n";
        displayEmpTable();
        printSalaryTable(BP, DA, HRA, PF, SF, gross, net);
    }
};

int main() {
    int choice, n;

    cout << "1. Programmer\n2. Team Lead\n3. Assistant Project Manager\n4. Project Manager\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter number of employees: ";
    cin >> n;

    switch (choice) {
    case 1: {
        Programmer* p = new Programmer[n];
        for (int i = 0; i < n; i++) {
            cout << "\n--- Enter details for Programmer " << i + 1 << " ---\n";
            p[i].generatePaySlip();
        }
        delete[] p;  
        break;
    }
    case 2: {
        TeamLead* t = new TeamLead[n];
        for (int i = 0; i < n; i++) {
            cout << "\n--- Enter details for Team Lead " << i + 1 << " ---\n";
            t[i].generatePaySlip();
        }
        delete[] t;
        break;
    }
    case 3: {
        AssistantProjectManager* a = new AssistantProjectManager[n];
        for (int i = 0; i < n; i++) {
            cout << "\n--- Enter details for APM " << i + 1 << " ---\n";
            a[i].generatePaySlip();
        }
        delete[] a;
        break;
    }
    case 4: {
        ProjectManager* p = new ProjectManager[n];
        for (int i = 0; i < n; i++) {
            cout << "\n--- Enter details for Project Manager " << i + 1 << " ---\n";
            p[i].generatePaySlip();
        }
        delete[] p;
        break;
    }
    default:
        cout << "Invalid Choice!" << endl;
    }

    Employee::showCount();
    return 0;
}