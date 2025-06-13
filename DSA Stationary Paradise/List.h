#ifndef LIST_H
#define LIST_H

#include <string>

class List
{
private:
	std::string name;
	float price;
	int qty;

public:
	List();
	~List();
	void insert(List [], int&);
	void sort(List [], int);
	void sortList(List [], int);
	void searchList(List [], int);
};
#endif