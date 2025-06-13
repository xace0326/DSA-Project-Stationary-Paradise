#include <iostream>
#include <iomanip>
#include <string>
//#include <cctype>
#include "List.h"
using namespace std;

List::List()	{ }

List::~List()	{ }

void List::insert(List item[], int& count)
{
	cin.ignore();
	cout << "\nInsert item name: ";
	getline(cin, item[count].name);
	cout << "Insert item price: RM ";
	cin >> price;
	cout << "Insert item quantity: ";
	cin >> qty;
	cout << endl;

	// Uppercase the name
	for (int i = 0; item[count].name[i] != NULL; i++)
	{
		item[count].name[i] = toupper(item[count].name[i]);
	}

	count++;
	sortList(item, count);
}

void List::sort(List item[], int total)
{
	int option;
	bool sorted = false;

	cout << "\t\t1. Sort by quantity\n";
	cout << "\t\t2. Sort by price\n\n";
	cout << "Enter -> ";
	cin >> option;
	cout << endl;

	if (option == 1)
	{
		for (int i = 0; i < total - 1; i++)
		{
			for (int j = 0, sorted = false; j < total - i - 1; j++)
			{
				if (item[j].qty > item[j + 1].qty)
				{
					int temp = item[j].qty;
					item[j].qty = item[j + 1].qty;
					item[j + 1].qty = temp;
				}
				else
					sorted = true;
			}

			// If all items are already sorted
			if (sorted)
				return;
		}
	}
	else if (option == 2)
	{
		for (int i = 0; i < total - 1; i++)
		{
			for (int j = 0, sorted = false; j < total - i - 1; j++)
			{
				if (item[j].price > item[j + 1].price)
				{
					float temp = item[j].price;
					item[j].price = item[j + 1].price;
					item[j + 1].price = temp;
				}
				else
					sorted = true;
			}

			// If all items are already sorted
			if (sorted)
				return;
		}
	}
	else
	{
		cout << "\nInvalid Input !\n";
		return;
	}
	
	
	if (total == 0)
	{
		cout << "Empty !\n\n";
		return;
	}
	else
	{
		for (int i = 0; i < total; i++)
		{
			cout << "Item name: " << setw(30) << item[i].name;
			cout << "\tPrice: " << setw(10) << setprecision(2) << fixed << item[i].price;
			cout << "\tQuantity: " << setw(5) << item[i].qty << endl;
		}
		cout << endl;
	}
}

void List::sortList(List item[], int total)
{
	bool sorted = false;

	for (int i = 0; i < total - 1; i++)
	{
		for (int j = 0, sorted = false; j < total - i - 1; j++)
		{
			if (item[j].name > item[j + 1].name)
			{
				string temp = item[j].name;
				item[j].name = item[j + 1].name;
				item[j + 1].name = temp;
			}
			else
				sorted = true;
		}
		
		// If all items are already sorted
		if (sorted)
			return;
	}
}

void List::searchList(List item[], int n)
{
	if (n != 0)
	{
		int mid, start = 0, end = n - 1;
		string item_name;

		cin.ignore();
		cout << "\nEnter the item name: ";
		getline(cin, item_name);

		// Uppercase the name
		for (int i = 0; item_name[i] != NULL; i++)
		{
			item_name[i] = toupper(item_name[i]);
		}

		while (start <= end)
		{
			mid = (start + end) / 2;

			if (item_name > item[mid].name)
			{
				start = mid + 1;
			}
			else if (item_name < item[mid].name)
			{
				end = mid - 1;
			}
			else
			{
				start = end + 1;
			}
		}

		if (item_name == item[mid].name)
		{
			cout << "Item found !\n\n";
			cout << "Item name: " << item[mid].name << endl;
			cout << "Item price: RM " << setprecision(2) << fixed << item[mid].price << endl;
			cout << "Item quantity: " << item[mid].qty << endl << endl;
		}
		else
		{
			cout << "Item not found !\n\n";
		}
	}

	else
		cout << "\nNo item to search !\n\n";
}