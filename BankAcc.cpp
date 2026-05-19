#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount {
    int accNo;
    string accHolder;
    float balance;

    static int totalAccounts;
    static float totalBalance;

public:
    BankAccount() {
        accNo = 0;
        accHolder = "";
        balance = 0;
        totalAccounts++;
    }

    void getData() {
        while (true) {
            cout << "\nAccount Number: ";
            cin >> accNo;
            if (cin.fail() || accNo < 0) {
                cout << "Invalid Account Number!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                break;
    	}
        }

        while (true) {
            cout << "Account Holder Name: ";
            cin >> accHolder;
            bool hasDigit = false;

            for (int i = 0; i < accHolder.size(); i++) {
                if (isdigit(accHolder[i])) {
                    hasDigit = true;
                    break;
            }
            }

            if (hasDigit || accHolder.empty()) {
                cout << "Invalid name! No numbers allowed.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Initial Balance: ";
            cin >> balance;
            if (balance < 0) {
                cout << "Invalid balance!\n";
            } else {
                totalBalance += balance;
                break;
        }
    }
    }

    float getBalance() {
        return balance;
    }

    void display() {
        cout << setw(10) << accNo << setw(20) << accHolder << setw(15) << fixed << setprecision(2) << balance << endl;
    }

    static void showTotalAccounts() {
        cout << "\nTotal Accounts: " << totalAccounts << endl;
    }
    
    static void displayAccno(BankAccount &b){
    	cout<<"Account no: "<<b.accNo;
	}

    static void showTotalBalance() {
        cout << "Total Bank Balance: " << fixed << setprecision(2) << totalBalance << endl;
    }
    
    static printascending(BankAccount a, BankAccount b){
    	if(a.balance < b.balance){
    		cout<<"\nThe balance in sorted order is: "<< a.balance <<" and "<< b.balance;
		}else {
			cout<<"\nThe balance in sorted order is: "<<b.balance<<" and "<<a.balance;
		}
	}

    ~BankAccount(){
    	totalAccounts--;
	}
};

int BankAccount::totalAccounts = 0;
float BankAccount::totalBalance = 0;

int main() {
    int n;

    cout << "Enter number of accounts: ";
    cin >> n;

    BankAccount* acc = new BankAccount[n];

	BankAccount b1 = new BankAccount();
	
	displayAccno(b1);
    cout << "\nEnter Account Details\n";
    for (int i = 0; i < n; i++) {
        cout << "\nAccount " << i + 1 << endl;
        acc[i].getData();
    }

	cout<<"\n";
    cout << setw(10) << "Acc No" << setw(20) << "Name" << setw(15) << "Balance" << endl;

    for (int i = 0; i < n; i++) {
        acc[i].display();
    }

    BankAccount::showTotalAccounts();
    BankAccount::showTotalBalance();

	BankAccount::printascending(acc[0], acc[1]);

    delete[] acc;
    return 0;
}

