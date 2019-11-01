#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  myHeap = new MinMaxHeap();
  string curInput;

  ifstream infile;
  infile.open(filename);

  while(getline(infile, curInput, ','))
  {
    myHeap->insert(stoi(curInput));
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
  cout << "\n\n1 - Build Heap\n";
  cout << "2 - Insert\n";
  cout << "3 - Delete\n";
  cout << "4 - Min Level Elements\n";
  cout << "5 - Max Level Elements\n";
  cout << "6 - Exit\n";
  cin >> choice;

  if (choice == 1)
    buildHeap();
  else if (choice == 2)
    insertElement();
  else if (choice == 3)
    deleteElement();
  else if (choice == 4)
    minLevelElements();
  else if (choice == 5)
    maxLevelElements();
  else if (choice == 6)
    running = false;
  else
    cout << "\nChoose a menu item from 1-9\n";

  if (running == true)
    runMenu();
}

void Executive::insertElement()
{
  int newElement;
  cout << "Enter the element to be inserted: ";
  cin >> newElement;

  bool success = myHeap->insert(newElement);

  if (success)
  {
    cout << to_string(newElement) << " has been inserted successfully\n";
  }
  else
  {
    cout << to_string(newElement) << " is already in heap\n";
  }
}

void Executive::deleteElement()
{
  int val;
  cout << "Enter the element to be removed: ";
  cin >> val;

  bool success = myHeap->remove(val);

  if (success)
  {
    cout << to_string(val) << " has been removed successfully\n";
  }
  else
  {
    cout << to_string(val) << " was nit found\n";
  }
}

void Executive::buildHeap()
{
  myHeap->showHeap();
}

void Executive::minLevelElements()
{
  myHeap->minTraversal();
}

void Executive::maxLevelElements()
{
  myHeap->maxTraversal();
}