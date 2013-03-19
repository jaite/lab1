#include <iostream>
#include "list.h"

using namespace std;
using namespace cpp_lab1;
int main() {
	List x;
	int choice = 0;
	int input;
	int rem;

	while(choice != -1) {
	cout << "1. Add" << endl << "2. Remove less than" << endl 
	<< "3. Remove equal" << endl << "4. Remove greater" << endl << "5. Print all elements" <<
	endl << "6. Add a bunch of elements" << endl << "7. Test empty(), size() and largest()" << endl << "-1. Quit" << endl;
		cout << "Choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
			cout << "Input number: ";
			cin >> input;
			cout << endl;
			x.insert(input);
			
			break;
			
			case 2:
			cout << "Remove first number less than: ";
			cin >> rem;
			cout << endl;
			x.remove(rem, List::LESS);
			break;
			
			case 3:
			cout << "Remove first number equal to: ";	
			cin >> rem;
			cout << endl;
			x.remove(rem, List::EQUAL);
			break;
			
			case 4:
			cout << "Remove first number greater than: ";
			cin >> rem;
			cout << endl;
			x.remove(rem, List::GREATER);
			break;
			
			case 5:
			cout << "All elements in the list: " << endl;
			x.debugPrint();
			break;
			
			case 6:
			cout << "Adding stuff" << endl;
			x.insert(5);
			x.insert(7);
			x.insert(3);
			x.insert(5);
			x.insert(2);
			x.insert(6);
			x.insert(0);
			break;
			
			case 7:
			cout << "Running List::empty()" << endl;
			if (x.empty()) {
				cout << "The list is empty." << endl;
			} else {
				cout << "The list is not empty - Running List::size()" << endl <<
				"The list has " << x.size() << " elements." << endl;
				cout << "Running List::largest()" << endl << "The largest element is: " << x.largest() << endl;
			}
			break;

		}
		x.debugPrint();
	}
	;
}
