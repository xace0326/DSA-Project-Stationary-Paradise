#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main() {

	List main;
	string item;
	int quantity;
	char option;

	cout << "Option:\n"
		<<"1. Insert Item\n2. Check Item\n3. Exit\nEnter your Choice: ";
	cin >> option;

	switch (option) {
	case '1':
		cin.ignore();
		cout << "Enter item name: ";
		getline(cin, item);  //input whole line include space
		cout << "Enter quantity: ";
		cin >> quantity;
		main.addItem(item, quantity);
		cin.ignore(); //clear input buffer
		break;
	case '2':
		system("cls");

		cout << "Option:\n"
			<< "1. Sort by quantity\n2. Sort by name\n3. Back \n4. exit\nEnter your Choice: ";
		cin >> option;

		switch (option) {
		case '1':
			main.sortQuantity();
			break;
		case '2':
			main.sortName();
			break;
		case '4':
			return 0;
		default:
			break;
		}
	default:
		break;
	}

	cout << "1. Search by name\n2. Search by quantity\nPlease enter your choice: ";
	cin >> option;
	if (option == '1') {
		string search;

		cin.ignore();
		cout << "Please enter item name: ";
		getline(cin, search);
		main.BinarySearch(search);
	}
	else if (option == '2') {
		int search;
		cout << "Please enter item name: ";
		cin >> search;
		main.BinarySearch(search);
		cin.ignore();
	}
	else {

	}

	return 0;

}