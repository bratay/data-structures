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
  cout << "\n\n1-AddItem\n";
  cout << "2-Delete\n";
  cout << "3-Leaf\n";
  cout << "4-PrintLeaf\n";
  cout << "5-PrintTreeHeight\n";
  cout << "6-Preorder\n";
  cout << "7-Postorder\n";
  cout << "8-Inorder\n";
  cout << "9-SearchElement\n";
  cout << "10-Exit\n";
  cout << ">> ";
  cin >> choice;

  if (choice == 1)
    insert();
  else if (choice == 2)
    deleteElement();
  else if (choice == 3)
    leaf();
  else if (choice == 4)
    printLeafs();
  else if (choice == 5)
    height();
  else if (choice == 6)
    preorder();
  else if (choice == 7)
    postorder();
  else if (choice == 8)
    inorder();
  else if (choice == 9)
    search();
  else if (choice == 10)
    running = false;
  else
    cout << "\nChoose a menu item from 1-9\n";

  if (running == true)
    runMenu();
}

