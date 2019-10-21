#include "executive.h"
#include "list.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
    myList = new List<int>();

    ifstream infile;
    infile.open(filename);

    string currentNum = "";

    while (!infile.eof())
    {
        getline(infile, currentNum, ' ');
        myList->insert(stoi(currentNum));
    }

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
    cout << "3. Find smallest number \n";
    cout << "4. Find largest number \n";
    cout << "5. Average of numbers \n";
    cout << "6. Merge2Lists \n";
    cout << "7. Print \n";
    cout << "8. Exit \n";
    cout << ">> ";
    cin >> choice;

    if (choice == 1)
        insert();
    else if (choice == 2)
        deleteNode();
    else if (choice == 3)
        smallest();
    else if (choice == 4)
        largest();
    else if (choice == 5)
        average();
    else if (choice == 6)
        merge();
    else if (choice == 7)
        print();
    else if (choice == 8)
        running = false;
    else
        cout << "\nChoose a menu item from 1-9\n";

    if (running == true)
        runMenu();
}

bool Executive::isListEmpty(){
	return myList->getLength() == 0;
}

void Executive::insert()
{
    int newNum = 0;
    cout << "\nEnter a integer: ";
    cin >> newNum;
    myList->insert(newNum);
}

void Executive::deleteNode()
{
    int nodeToDelete = 0;
    cout << "\nEnter the number to be deleted: ";
    cin >> nodeToDelete;
    bool successful = myList->remove(nodeToDelete);

    if (successful)
        cout << "Delete was successful\n";
    else
        cout << "Delete was unsuccessful number not found\n";
}
void Executive::smallest()
{
    int length = myList->getLength();
    if (myList->isEmpty())
    {
        cout << "There are not any nodes in your list";
        return;
    }

    int smallest = myList->getEntry(1);
    for (int x = 2; x <= length; x++)
    {
        if (smallest > myList->getEntry(x))
        {
            smallest = myList->getEntry(x);
        }
    }

    cout << "\nSmallest number: " + to_string(smallest) + "\n";
}

void Executive::largest()
{
    int length = myList->getLength();
    if (myList->isEmpty())
    {
        cout << "There are not any nodes in your list";
        return;
    }

    int largest = myList->getEntry(1);
    for (int x = 2; x <= length; x++)
    {
        if (largest < myList->getEntry(x))
        {
            largest = myList->getEntry(x);
        }
    }

    cout << "\nLargest number: " + to_string(largest) + "\n";
}

void Executive::average()
{
    int length = myList->getLength();
    if (myList->isEmpty())
    {
        cout << "There are not any nodes in your list";
        return;
    }

    double sum = 0;
    for (int x = 1; x <= length; x++)
    {
        sum += myList->getEntry(x);
    }

    cout << "\nAverage: " + to_string(sum / length) + "\n";
}

void Executive::merge() 
{
	string newList = "";

	cout<<"Enter new list to be merged: ";
	cin.ignore();
	getline(cin, newList);
	newList += " ";
	
	string currentNum = "";
	for(int i = 0; i < newList.length(); i++)
	{
		while(newList.at(i) != ' ')
		{
			currentNum += newList.at(i);
			i++;
		}
		
		myList->insert(stoi(currentNum));
		currentNum = "";
	}

	int length = myList->getLength();
	int small[length + 1];
	for(int x = 0; x < length; x++)
	{
		small[x] = mergeHelp();
		myList->remove(small[x]);
	}

	for(int x = 0; x < length; x++)
	{
		myList->insert(small[x]);
	}
    
    print();
}

int Executive::mergeHelp(){
	int smallest = myList->getEntry(1);
    for (int x = 2; x <= myList->getLength(); x++)
    {
        if (smallest > myList->getEntry(x))
        {
            smallest = myList->getEntry(x);
        }
    }
    return smallest;
}

void Executive::print()
{
    int length = myList->getLength();
    cout<<"\nList: ";
    if (myList->isEmpty())
    {
        cout << "list empty";
        return;
    }

    for(int x = 1; x <= length; x++){
    	cout<<to_string(myList->getEntry(x)) + ", ";
    }
    cout<<"\b\n";
}
