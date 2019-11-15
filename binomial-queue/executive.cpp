#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  myHeap = new MinLeftistHeap();
  string curInput;

  ifstream infile;
  infile.open(filename);

  while (getline(infile, curInput, ','))
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
  cout << "\n1 - Insert\n";
  cout << "2 - Delete Min\n";
  cout << "3 - Levelorder\n";
  cout << "4 - Exit\n";
  cout << ">>> ";
  cin >> choice;
  cout << "\n";

  if (choice == 1)
    insertElement();
  else if (choice == 2)
    delete ();
  else if (choice == 3)
    levelOrder();
  else if (choice == 4)
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

  cout << to_string(newElement) << " has been inserted successfully\n";
}

void Executive::delete ()
{
  int min = myHeap->deletemin();

  if (min != -1)
  {
    cout << "Min removed successfully\n";
  }
  else
  {
    cout << "Queue is empty\n";
  }
}

void Executive::levelorder()
{
  myHeap->levelOrder();
}