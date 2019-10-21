#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  myTree = new Tree();
  string curInput;

  ifstream infile;
  infile.open(filename);
  
  while(getline(infile, curInput, ','))
  {
    myTree->insert(stoi(curInput));
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
  cout << "\n\n1-IsFull\n";
  cout << "2-AddItem\n";
  cout << "3-Delete\n";
  cout << "4-Leaf\n";
  cout << "5-PrintLeaf\n";
  cout << "6-PrintTreeHeight\n";
  cout << "7-Preorder\n";
  cout << "8-Postorder\n";
  cout << "9-Inorder\n";
  cout << "10-Levelorder\n";
  cout << "11-Exit\n";
  cout << ">> ";
  cin >> choice;

  if (choice == 1)
    full();
  else if (choice == 2)
    insert();
  else if (choice == 3)
    deleteElement();
  else if (choice == 4)
    leaf();
  else if (choice == 5)
    printLeafs();
  else if (choice == 6)
    height();
  else if (choice == 7)
    preorder();
  else if (choice == 8)
    postorder();
  else if (choice == 9)
    inorder();
  else if (choice == 10)
    levelorder();
  else if (choice == 11)
    running = false;
  else
    cout << "\nChoose a menu item from 1-9\n";

  if (running == true)
    runMenu();
}

void Executive::insert(){
  int num;

  cout<<"Give a number to insert: ";
  cin>>num;

  if(myTree->insert(num))
  {
    cout<<to_string(num)<<" inserted successfully";
  }else{
    cout<<to_string(num)<<" not inserted";
  }
}

void Executive::deleteElement(){
  int num;

  cout<<"Give a number to delete: ";
  cin>>num;

  if(myTree->deleteNode(num))
  {
    cout<<to_string(num)<<" deleted successfully";
  }else{
    cout<<to_string(num)<<" not deleted";
  }
}

void Executive::leaf(){
  int num;

  cout<<"Give a number to check if it's a leaf: ";
  cin>>num;

  if(myTree->isLeaf(num))
    cout<<to_string(num)<<" is a leaf";
  else
    cout<<to_string(num)<<" is not a leaf";
}

void Executive::printLeafs(){
  myTree->printLeafs();
}

void Executive::height(){
  cout<<"Height equals "<< to_string(myTree->getTreeHeight());
}

void Executive::full(){
  if(myTree->isFull()){
    cout<< "Full Tree";
  }else{
     cout<<"Not a Full Tree";
  }
}

void Executive::preorder(){
  myTree->preOrderTraversal();
}

void Executive::postorder(){
  myTree->postOrderTraversal();
}

void Executive::inorder(){
  myTree->inOrderTraversal();
}

void Executive::levelorder(){
  myTree->levelOrderTraversal();
}
