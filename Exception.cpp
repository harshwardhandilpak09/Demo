#include<iostream>
#include<exception>
#include<vector>

using namespace std;

class DivideByZero : public exception
{
	public:
		string msg;
		
		DivideByZero(string m){
			msg = m;
		}
	~DivideByZero() throw() {}	
};

class LimitExceed : public exception
{
	public:
		string msg;
		
		LimitExceed(string m){
			msg = m;
		}
	~LimitExceed() throw() {}
};

class InvalidInput : public exception
{
	public:
		string msg;
		
		InvalidInput(string m){
			msg = m;
		}
	~InvalidInput() throw() {}
};

int main(){
	int choice;
	
	while(true){
		cout<<"\n1.Divide Numbers\n2.Operations On Vector\n3.Exit\nEnter your choice: ";
		cin>>choice;

		if(cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"Invalid input! Enter numeric choice.\n";
			continue;
		}
		
		switch(choice){
		
		case 1:
			try{
				int first, second;
			
				cout<<"\nEnter first No: ";
				cin>>first;
				
				cout<<"Enter second No: ";
				cin>>second;
				
				if(cin.fail()){
					throw InvalidInput("Invalid number entered!");
				}
				
				if(second == 0){
					throw DivideByZero("Can't divide by zero!");
				}

				cout<<"Result: "<< first / second << endl;
			}
			catch(DivideByZero &e){
				cout<< e.msg << endl;
			}
			catch(InvalidInput &e){
				cout<< e.msg << endl;
			}
			break;
		
		case 2:
			try{
				int size, index;
				
				cout<<"\nEnter number of elements (max 5): ";
				cin>>size;
				
				if(cin.fail() || size <= 0){
					throw InvalidInput("Invalid size input!");
				}
				
				if(size > 5){
					throw LimitExceed("Array size limit is 5!");
				}

				vector<int> nums(size);
				
				cout<<"Enter elements: ";
				for(int i = 0; i < size; i++){
					cin>>nums[i];
					
					if(cin.fail()){
						throw InvalidInput("Invalid element input!");
					}
				}

				cout<<"Enter index: ";
				cin>>index;

				cout<<"Element: "<< nums.at(index) << endl;
			}	
			catch(LimitExceed &e){
				cout<< e.msg << endl;
			}

			catch(InvalidInput &e){
				cout<< e.msg << endl;
			}
			break;

		case 3:
			return 0;

		default:
			cout<<"Invalid choice!\n";
		}
	}
}
