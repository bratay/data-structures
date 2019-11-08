#include "minLeftistHeap.h"
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
    cout << to_string(val) << " was not found\n";
  }
}

void Executive::buildHeap()
{
  myHeap->showHeap();
}

void Executive::merge()
{
  int H2 [3];
  int newElement;

  cout<<"Insert 3 elements for H2";
  cin>>newElement; 
  H2[0] = newElement;
  cin>>newElement; 
  H2[1] = newElement;
  cin>>newElement; 
  H2[2] = newElement;

  myHeap->concate

  cout<<"\nThe new level order traversal of the combinded tree is: \n";
  myHeap->levelorder();
}

void Executive::findMinElement()
{
  int min = myHeap->findMin();
  cout<<"\nThe min element is "<<min;
}

void Executive::preorder()
{
  myHeap->preorder();
}

void Executive::inorder()
{
  myHeap->inorder();
}

void Executive::postorder()
{
  myHeap->postorder();
}

void Executive::levelorder()
{
  myHeap->levelorder();
}