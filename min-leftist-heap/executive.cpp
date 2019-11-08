#include "MinLeftistHeap.h"
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
  cout << "2 - Merge\n";
  cout << "2 - Delete Min\n";
  cout << "3 - Find Min Element\n";
  cout << "4 - Preorder\n";
  cout << "5 - Inorder\n";
  cout << "6 - Postorder\n";
  cout << "7 - Levelorder\n";
  cout << "8 - Exit\n";
  cout << ">>> ";
  cin >> choice;
  cout << "\n";

  if (choice == 1)
    insertElement();
  else if (choice == 2)
    merge();
  else if (choice == 3)
    deleteElement();
  else if (choice == 4)
    findMinElement();
  else if (choice == 5)
    preorder();
  else if (choice == 6)
    inorder();
  else if (choice == 7)
    postorder();
  else if (choice == 8)
    levelorder();
  else if (choice == 9)
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
    cout << to_string(newElement) << " is already in heap\n";
  }
  else
  {
    cout << to_string(newElement) << " has been inserted successfully\n";
  }
}

void Executive::deleteElement()
{
  bool success = myHeap->deletemin();

  if (success)
  {
    cout << "Min removed successfully\n";
  }
  else
  {
    cout << "Min was not found\n";
  }
}

void Executive::merge()
{
  int H2[3];
  int newElement;

  cout << "Insert 3 elements for H2";
  cin >> newElement;
  H2[0] = newElement;
  cin >> newElement;
  H2[1] = newElement;
  cin >> newElement;
  H2[2] = newElement;

  MinLeftistHeap* H2Heap = new MinLeftistHeap();

  for(int x = 0; x < 3; x++)
  {
    H2Heap->insert(H2[x]);
  }

  myHeap->concate(myHeap->getRoot(), H2Heap->getRoot());

  cout << "\nThe new level order traversal of the combinded tree is: \n";
  myHeap->levelorder();
}

void Executive::findMinElement()
{
  int min = myHeap->findmin();
  cout << "\nThe min element is " << min;
}

void Executive::preorder()
{
  myHeap->Preorder();
}

void Executive::inorder()
{
  myHeap->Inorder();
}

void Executive::postorder()
{
  myHeap->Postorder();
}

void Executive::levelorder()
{
  myHeap->levelorder();
}