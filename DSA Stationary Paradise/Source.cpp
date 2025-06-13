#include <iostream>
using namespace std;
#include "List.h"

const int maxSize = 50;

int main()
{
	int choice, count = 0;

	List item[maxSize];

	do
	{
		cout << "----------Welcome to Stationary Paradise----------\n\n";
		cout << "\t\t1. Insert item\n";
		cout << "\t\t2. Sort item\n";
		cout << "\t\t3. Search item\n";
		cout << "\t\t4. Exit\n";
		cout << "\nEnter -> ";
		cin >> choice;

		switch (choice)
		{
		case 1: 
			item[count].insert(item, count);
			break;
		case 2: 
			item[count].sort(item, count);
			break;
		case 3: 
			item[count].searchList(item, count);
			break;
		default:
			cout << "Invalid input !\n";
		}
	} while (choice != 4);

	return 0;
}