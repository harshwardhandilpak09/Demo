#include<iostream>
#include<vector>
#include<string>
using namespace std;

void getIntVector(vector<int>& arr, int size){
	cout<<"\nEnter "<<size<<" integer values:"<<endl;
	
	for(int i=0;i<size;i++){
		while(true){
			cout<<"Element "<<i+1<<":";
			int value;
			cin>>value;
			
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"Invalid input, enter an integer pls!"<<endl;
			}else {
				arr.push_back(value);
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}
void getFloatVector(vector<float>& arr, int size){
	cout<<"\nEnter "<<size<<" float values:"<<endl;
	
	for(int i=0;i<size;i++){
		while(true){
			cout<<"Element "<<i+1<<":";
			float value;
			cin>>value;
			
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"Invalid input, enter a float pls!"<<endl;
			}else {
				arr.push_back(value);
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

void getDoubleVector(vector<double>& arr, int size){
	cout<<"\nEnter "<<size<<" double values:"<<endl;
	
	for(int i=0;i<size;i++){
		while(true){
			cout<<"Element "<<i+1<<":";
			double value;
			cin>>value;
			
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"Invalid input, enter a double pls!"<<endl;
			}else {
				arr.push_back(value);
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

void getStringVector(vector<string>& arr, int size){
	cout<<"\nEnter "<<size<<" string values:"<<endl;
	cin.ignore();
	
	for(int i=0;i<size;i++){
		while(true){
			cout<<"Element "<<i+1<<":";
			string value;
			getline(cin, value);
			
			if(value.empty()){
				cout<<"Invalid input, enter a non-empty string pls!"<<endl;
			}else {
				arr.push_back(value);
				break;
			}
		}
	}
}

void getCharVector(vector<char>& arr, int size){
	cout<<"\nEnter "<<size<<" char values:"<<endl;
	
	for(int i=0;i<size;i++){
		while(true){
			cout<<"Element "<<i+1<<":";
			char value;
			cin>>value;
			
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"Invalid input, enter a char pls!"<<endl;
			}else {
				arr.push_back(value);
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

template <typename T>
void displayVector(vector<T>& arr){
	cout<<"The vector elements are: ";
	for(int i = 0; i < arr.size(); i++){
		cout<<arr[i] << " ";
	}
	cout<<endl;
}

template <typename T>
void bubbleSort(vector<T>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(){
	int choice, datatype, sortchoice, size;
	while(true){
		cout<<"\nMain Menu\n";
		cout<<"1.Sort an array\n2.Exit\nEnter your choice:";
		cin>>choice;
		
		if(cin.fail() || choice < 1 || choice > 2){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"Invalid input, enter number between 1-2"<<endl;
			continue;
	}	
		if(choice == 1){
			cout << "\n--- Select Data Type ---" << endl;
			cout << "1. Integer" << endl;
			cout << "2. Float" << endl;
			cout << "3. Double" << endl;
			cout << "4. Character" << endl;
			cout << "5. String" << endl;
			cout << "Enter your choice: ";
			cin>>datatype;
			
			if(cin.fail() || datatype < 1 || datatype > 5){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"Invalid input !, enter choice between 1-5"<<endl;
				continue;
		}
			
			cout<<"Enter the size of the array:";
			cin>>size;
			
			if(cin.fail() || size <= 0){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"Invalid size!"<<endl;
				continue;
	}
			switch(datatype){
				case 1:{
					vector<int> arr;
					getIntVector(arr, size);
					
					cout<<"\nOriginal Integer Vector:"<<endl;
					displayVector(arr);
					
					bubbleSort(arr);
					cout<<"\nSorted Integer Vector:"<<endl;
					displayVector(arr);
					break;
				}
				case 2:{
					vector<float> arr;
					getFloatVector(arr, size);
					
					cout<<"\nOriginal Float Vector:"<<endl;
					displayVector(arr);
					
					bubbleSort(arr);
					cout<<"\nSorted Float Vector:"<<endl;
					displayVector(arr);
					break;
				}
				case 3:{
					vector<double> arr;
					getDoubleVector(arr, size);
					
					cout<<"\nOriginal Double Vector:"<<endl;
					displayVector(arr);
					
					bubbleSort(arr);
					cout<<"\nSorted Double Vector:"<<endl;
					displayVector(arr);
					break;
				}
				case 4:{
					vector<char> arr;
					getCharVector(arr, size);
					
					cout<<"\nOriginal Char Vector:"<<endl;
					displayVector(arr);
					
					bubbleSort(arr);
					cout<<"\nSorted Char Vector:"<<endl;
					displayVector(arr);
					break;
				}
				case 5:{
					vector<string> arr;
					getStringVector(arr, size);
					
					cout<<"\nOriginal String Vector:"<<endl;
					displayVector(arr);
					
					bubbleSort(arr);
					cout<<"\nSorted String Vector:"<<endl;
					displayVector(arr);
					break;
				}
				default:
					cout<<"Invalid Input!"<<endl;
			}
			
		}else if(choice == 2){
			cout<<"\nExiting the program"<<endl;
			break;
		}
	}
	return 0;
}
