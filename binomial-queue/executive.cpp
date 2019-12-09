#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  myBiQue = new BinomialQueue();
  string curInput = "";

  ifstream infile;
  infile.open(filename);

  while (getline(infile, curInput, ','))
  {
    myBiQue->insert(stoi(curInput));
  }

  infile.close();
  runMenu();
}

Executive::~Executive()
{
}

void Executive::runMenu()
{

  int choice = 0;

  while (choice != 4)
  {

    cout << "1 - Insert\n"
         << "2 - Delete Minimum Element\n"
         << "3 - Levelorder Traversal\n"
         << "4 - Exit\n"
         << "\n   :";

    cin >> choice;

    switch (choice)
    {
    case 1:
      insertItem();
      break;
    case 2:
      deletemin();
      break;
    case 3:
      printLevelOrder();
      break;
    case 4:
    default:
      if (choice != 4)
      {
        cout << "Input integer from 1 - 4\n";
      }
      break;
    }
  }
}

void Executive::insertItem()
{
  int number;

  cout << "Enter a number: ";
  cin >> number;

  myBiQue->insert(number);
}

void Executive::deletemin()
{
  myBiQue->deleteMin();
}

void Executive::printLevelOrder()
{
  myBiQue->levelOrderDisplay();
}