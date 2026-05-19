#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int id;
    string title, author;
    float price;
    float total = 0;

    while (true) {
        cout << "Book Id: ";
        cin >> id;

        if (cin.fail() || id < 0) {
            cout << "Invalid ID! Enter a positive number.\n";
            cin.clear();
            cin.ignore(20, '\n');
        } else {
            break;
        }
    }

    while (true) {
        cout << "Title: ";
        cin >> title;
        
        bool hasNo = false;
        
        for(int i=0;i<title.length();i++){
        	if(isdigit(title[i])){
        		hasNo = true;
			}
		}
		
		if(hasNo || title.empty()){
			cout << "Title cannot be empty or contain no's!\n";
		}else {
			break;
		}

    }

    while (true) {
        cout << "Author Name: ";
        cin >> author;

        bool hasDigit = false;

        for (int i = 0; i < author.length(); i++) {
            if (isdigit(author[i])) {
                hasDigit = true;
                break;
            }
        }

        if (hasDigit || author.empty()) {
            cout << "Author name cannot contain numbers!\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Book Price: ";
        cin >> price;

        if (price < 0) {
            cout << "Invalid price! Enter a positive value.\n";
        } else {
            break;
        }
    }

    total = price;

    cout << "\nBook Details\n";
    cout << setw(5) << "ID" << setw(15) << "Title"<< setw(15) << "Author"<< setw(10) << "Price\n";
    cout << setw(5) << id<< setw(15) << title << setw(15) << author<< setw(10) << fixed << setprecision(2) << price << endl;
    cout << "\nTotal Bill: " << fixed << setprecision(2) << total << endl;

    return 0;
}

