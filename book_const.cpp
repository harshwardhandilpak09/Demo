#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

class Book {
    int id;
    string title;
    string author;
    float price;
    static int Objcount;

public:
    Book() {
        id = 0;
        title = "";
        author = "";
        price = 0;
        Objcount++;
		cout<<"\nConstructor called";
    }

    void getData() {
        while (true) {
            cout << "\nBook Id: ";
            cin >> id;
            if (cin.fail() ||id < 0) {
                cout << "Invalid ID! Enter a positive number.\n";
                cin.clear();
                cin.ignore(20,'\n');
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

            for (int i = 0; i < author.size(); i++) {
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
    }

    float getPrice() {
        return price;
    }

    void display() {
        cout << setw(5) << id << setw(20) << title << setw(15) << author << setw(10) << fixed << setprecision(2) << price << endl;
    }

    ~Book() {
        cout << "Object " << Objcount << " Deleted!" << endl;
        Objcount--;
    }
};

int Book::Objcount = 0;

int main() {
    int n;
    float total = 0;

    cout << "Enter the number of books: ";
    cin >> n;

    Book* books = new Book[n];
    cout << "\nEnter Book Details\n";
    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << endl;
        books[i].getData();
        total += books[i].getPrice();
    }

    cout << setw(5) << "ID" << setw(20) << "Title" << setw(15) << "Author" << setw(10) << "Price" << endl;

    for (int i = 0; i < n; i++) {
        books[i].display();
    }

    cout << setw(40) << "Total Bill: " << setw(10) << fixed << setprecision(2) << total << endl;

    delete[] books;
    return 0;
}

