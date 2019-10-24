#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  //.myTree = new BiSearchTree();
  // string curInput;

  // ifstream infile;
  // infile.open(filename);

  // while(getline(infile, curInput, ','))
  // {
  //   myTree->insert(curInput);
  // }

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
    insert();
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

void Executive::insert()
{
}

void Executive::deleteElement()
{
}

void Executive::buildHeap()
{
}

void Executive::minLevelElements()
{
}

void Executive::maxLevelElements()
{
}