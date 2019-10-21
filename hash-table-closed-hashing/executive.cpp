#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  myqpTable = new qpTable();
	mydhTable = new dhTable();

  string curInput = "";

  ifstream infile;
  infile.open(filename);

  while(getline(infile, curInput, ','))
  {
    restaurant newElement;

    newElement.name = curInput;

    getline(infile, curInput, ',');
    newElement.rating = stoi(curInput);

    getline(infile, curInput, ',');
    newElement.price = curInput;

    myqpTable->insert(newElement);
    mydhTable->insert(newElement);
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
  bool running = true;

  cout << "\n1. Insert \n";
  cout << "2. Delete \n";
  cout << "3. Find By Name\n";
  cout << "4. Find By Rating\n";
  cout << "5. Find By Price\n";
  cout << "6. Print \n";
  cout << "7. Exit \n";
  cout << ">> ";
  cin >> choice;

  if (choice == 1)
    insert();
  else if (choice == 2)
    deleteElement();
  else if (choice == 3)
    findByName();
  else if (choice == 4)
    findByRating();
  else if (choice == 5)
    findByPrice();
  else if (choice == 6){
    cout<<"Quadratic probing: \n";
    myqpTable->printTable();
    cout<<"\n\n";
    cout<<"Double hashing: \n";
    mydhTable->printTable();
  }
  else if (choice == 7)
    running = false;
  else
    cout << "\nChoose a menu item from 1-9\n";

  if (running == true)
    runMenu();
}

void Executive::insert()
{
  restaurant newElement;
  string input = "";
  cout<<"Enter an element to be inserted: \n";
  cout<<"Name: ";
  cin>>input;

  newElement.name = input;

  cout<<"Rating: ";
  cin>>input;
  newElement.rating = stoi(input);

  cout<<"Price: ";
  cin>>input;
  newElement.price = input;

  bool dh = mydhTable->insert(newElement);
  bool qp = myqpTable->insert(newElement);

  cout<<"Quadratic probing: ";
  if(qp)
  	cout<<newElement.name + " was added to the hash table\n";
  else
  	cout<<newElement.name + " was not added successfully\n";

  cout<<"Double hashing: ";
  if(dh)
    cout<<newElement.name + " was added to the hash table\n";
  else
    cout<<newElement.name + " was not added successfully\n";
}

void Executive::deleteElement()
{
  string element = "";

  cout<<"Enter an element to be deleted: ";
  cin>>element;

  bool dh = mydhTable->deleteValue(element);
  bool qp = myqpTable->deleteValue(element);

  cout<<"Quadratic probing: ";
  if(qp)
    cout<<element + " was deleted\n";
  else
    cout<<element + " was not deleted successfully\n";

  cout<<"Double hashing: ";
  if(dh)
    cout<<element + " was deleted\n";
  else
    cout<<element + " was not deleted successfully\n";
}

void Executive::findByName()
{
  string elementName = "";

  cout<<"Enter a element name to find: ";
  cin>>elementName;

  int dh = mydhTable->find(elementName);
  int qp = myqpTable->find(elementName);

  cout<<"Quadratic probing: ";
  if(qp != -1)
    cout<<elementName + " found at " + to_string(qp) + "\n";
  else
    cout<<elementName + " not found\n";

  cout<<"Double hashing: ";
  if(dh != -1)
    cout<<elementName + " found at " + to_string(dh);
  else
    cout<<elementName + " not found\n";

}

void Executive::findByRating()
{
	int rating = 0;

	cout<<"Enter and rating to be found: ";
	cin>>rating;

	string *dh = mydhTable->searchByRating(rating);
  string *qp = myqpTable->searchByRating(rating);

  cout<<"Quadratic probing: ";
  if(qp != nullptr)
    for(int x = 0; x < qp->size(); x++){
      cout<<qp[x] + " ";
    }
  else
    cout<<to_string(rating) + " restaurants are not found in the hash table.\n";

  cout<<"\nDouble hashing: ";
  if(dh != nullptr){
    for(int x = 0; x < dh->size(); x++){
      cout<<dh[x] + " ";
    }
  }
  else
    cout<<to_string(rating) + " restaurants are not found in the hash table.\n";
}

void Executive::findByPrice()
{
	string price = "";

  cout<<"Enter and price to be found: ";
  cin>>price;

  string *dh = mydhTable->searchByPrice(price);
  string *qp = myqpTable->searchByPrice(price);

  cout<<"Quadratic probing: ";
  if(qp != nullptr)
    for(int x = 0; x < qp->size(); x++){
      cout<<qp[x] + " ";
    }
  else
    cout<<"No restaurants are found with the given price range.\n";

  cout<<"\nDouble hashing: ";
  // if(dh->size() != 0){
  // if(dh->size() < 31 ){
  if(dh != nullptr){
    for(int x = 0; x < dh->size(); x++){
      cout<<dh[x] + " ";
    }
  }
  else
    cout<<"No restaurants are found with the given price range.\n";
}
