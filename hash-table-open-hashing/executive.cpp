#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  int loadFactor = 0;
  string curInput = "";

  ifstream infile;
  infile.open(filename);

  while(getline(infile, curInput, ','))
    loadFactor++;

  myTable = new Table(loadFactor);

  ifstream infile2;
  infile2.open(filename);

  while(getline(infile2, curInput, ','))
    myTable->insert(curInput);

  runMenu();
}

Executive::~Executive()
{
}

void Executive::runMenu()
{
  int choice = 0;
  bool running = true;
  cout << "\n1. Insert \n";
  cout << "2. Delete \n";
  cout << "3. Find \n";
  cout << "4. Print \n";
  cout << "5. Exit \n";
  cout << ">> ";
  cin >> choice;

  if (choice == 1)
    insert();
  else if (choice == 2)
    deleteElement();
  else if (choice == 3)
    find();
  else if (choice == 4)
    myTable->printTable();
    //print();
  else if (choice == 5)
    running = false;
  else
    cout << "\nChoose a menu item from 1-9\n";

  if (running == true)
    runMenu();
}

void Executive::insert()
{
  string newElement = "";
  cout<<"Enter an element to be inserted: ";
  cin>>newElement;

  bool success = myTable->insert(newElement);

  if(success)
  	cout<<newElement + " was added to the hash table\n";
  else
  	cout<<newElement + " was not added successfully\n";
}

void Executive::deleteElement()
{
  string element = "";

  cout<<"Enter an element to be deleted: ";
  cin>>element;

  bool success = myTable->deleteValue(element);

  if(success)
  	cout<<element + " was successfully deleted\n";
  else
  	cout<<element + " was not found\n";
}


void Executive::find()
{
	string element = "";

	cout<<"Enter and element to be found: ";
	cin>>element;

	int index = myTable->find(element);

	if(index >= 0)
	  cout<<element + " was found at index " + to_string(index) + "\n";
	else
	  cout<<element + " was not found\n";
}
