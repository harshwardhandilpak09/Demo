#include<bits/stdc++.h>
using namespace std;

class Publication
{
public:
	string title;
	float price;
	int copies;
	static float totalSales;

	void getData()
	{
		while(true)
		{
			cout<<"Enter Title: ";
			cin>>title;

			bool valid=true;
			for(char c:title)
			{
				if(!isalpha(c))
				{
					valid=false;
					break;
				}
			}

			if(!valid)
				cout<<"Re-enter valid title (only letters allowed)!\n";
			else
				break;
		}

		while(true)
		{
			cout<<"Enter Price: ";
			cin>>price;

			if(cin.fail() || price<=0)
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Invalid price! Must be greater than 0\n";
			}
			else
				break;
		}

		while(true)
		{
			cout<<"Enter Copies Sold: ";
			cin>>copies;

			if(cin.fail() || copies<0)
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Invalid copies! Must be >=0\n";
			}
			else
				break;
		}
	}

	void saleCopy()
	{
		float sale = price * copies;
		totalSales += sale;
	}

	static void totalSale()
	{
		cout<<"\nTotal Sales of all Publications: "<<totalSales<<endl;
	}
};

float Publication::totalSales = 0;

class Book
{
public:
	Publication pub;
	string author;
	int orders;

	void getBookData()
	{
		pub.getData();

		while(true)
		{
			cout<<"Enter Author Name: ";
			cin>>author;

			bool valid=true;
			for(char c:author)
			{
				if(!isalpha(c))
				{
					valid=false;
					break;
				}
			}

			if(!valid)
				cout<<"Author name must contain only letters!\n";
			else
				break;
		}
	}

	void orderCopies()
	{
		while(true)
		{
			cout<<"Enter Copies Ordered: ";
			cin>>orders;

			if(cin.fail() || orders<0)
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Invalid order quantity!\n";
			}
			else
				break;
		}
	}

	void display()
	{
		cout<<"\nBook Title: "<<pub.title;
		cout<<"\nAuthor: "<<author;
		cout<<"\nCopies Ordered: "<<orders<<endl;

		pub.saleCopy();
	}
};

class Magazine
{
public:
	Publication pub;
	int issue;

	void getMagData()
	{
		pub.getData();
	}

	void orderQty()
	{
		while(true)
		{
			cout<<"Enter Issue Number: ";
			cin>>issue;

			if(cin.fail() || issue<=0)
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Issue must be greater than 0!\n";
			}
			else
				break;
		}
	}

	void currentIssue()
	{
		cout<<"Current Issue: "<<issue<<endl;
	}

	void receiveIssue()
	{
		cout<<"New Issue Received!\n";
	}

	void display()
	{
		cout<<"\nMagazine Title: "<<pub.title;
		cout<<"\nIssue Number: "<<issue<<endl;

		pub.saleCopy();
	}
};

int main()
{
	Book b;
	Magazine m;
	int choice;

	do
	{
		cout<<"\n===== MENU =====\n";
		cout<<"1. Enter Book Details\n";
		cout<<"2. Enter Magazine Details\n";
		cout<<"3. Show Book Ordered Copies\n";
		cout<<"4. Show Magazine Issue\n";
		cout<<"5. Show Total Sales\n";
		cout<<"6. Exit\n";

		cout<<"Enter Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				b.getBookData();
				b.orderCopies();
				break;

			case 2:
				m.getMagData();
				m.orderQty();
				m.receiveIssue();
				break;

			case 3:
				b.display();
				break;

			case 4:
				m.currentIssue();
				break;

			case 5:
				Publication::totalSale();
				break;

			case 6:
				cout<<"Exiting Program...\n";
				break;

			default:
				cout<<"Invalid Choice!\n";
		}

	}while(choice!=6);

	return 0;
}