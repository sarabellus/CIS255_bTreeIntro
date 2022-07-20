#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "student.h"

using namespace std;

void insertTree(student *&tree, student lName)
{
	student *n;

}

void displayTree(student *&tree)
{

}
void searchTree(student *tree, string sName)
{

}
void deleteNode(student *&tree, string sName)
{

}
int displayMenu()
{
	int opt;

	cout << "Enter one of the following options:" << endl;
	cout << "1. Display Tree" << endl;
	cout << "2. Search Tree" << endl;
	cout << "3. Add to Tree" << endl;
	cout << "4. Remove from Tree" << endl;
	cout << "5. Exit" << endl;
	cin >> opt;

	return opt;
}
int main()
{
	int opt;
	student *tree;
	string sName;
	student lName;

	insertTree(tree, lName);

	opt = displayMenu();

	while (opt != 5)
	{
		if (opt = 1)
			displayTree(tree);
		else if (opt = 2)
		{
			cout << endl;
			cout << "Enter search last name: " << endl;
			cin >> sName;
			searchTree(tree, sName);
		}
		else if (opt = 3)
			insertTree(tree, lName);
		else 
			deleteNode(tree, sName);
		
		opt = displayMenu();
	}
}