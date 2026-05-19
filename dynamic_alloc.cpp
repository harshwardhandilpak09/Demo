#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Book {
protected:
    string title;
    string author;
    double price;
    static int count;
    static double total;

public:
    virtual void input() {
        cout << "Enter title: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, title);

        cout << "Enter author: ";
        getline(cin, author);

        while (true) {
            cout << "Enter price (positive): ";
            cin >> price;

            if (cin.fail() || price <= 0) {
                cout << "Invalid input\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        }
        count++;
        total += price;
    }

    virtual void display() {
        cout << left << setw(20) << title
             << setw(20) << author
             << setw(10) << price << endl;
    }

    static void header() {
        cout << "\n" << left << setw(20) << "Title"
             << setw(20) << "Author"
             << setw(10) << "Price" << endl;
        cout << string(50, '-') << endl;
    }

    static void showSummary() {
        cout << string(50, '-') << endl;
        cout << left << setw(40) << "Total Books:"
             << count << endl;
        cout << left << setw(40) << "Total Price:"
             << total << endl;
    }

    virtual ~Book() {}
};

int Book::count = 0;
double Book::total = 0;

int main() {
    int n;

    while (true) {
        cout << "Enter number of books: ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cout << "Invalid input\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    Book** b = new Book*[n];

    for (int i = 0; i < n; i++) {
        b[i] = new Book();
        cout << "\nBook " << i + 1 << endl;
        b[i]->input();
    }

    Book::header();

    for (int i = 0; i < n; i++) {
        b[i]->display();
    }

    Book::showSummary();

    for (int i = 0; i < n; i++) {
        delete b[i];
    }
    delete[] b;

    return 0;
}
