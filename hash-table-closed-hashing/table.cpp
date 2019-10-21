#include "table.h"
#include <iostream>
#include <string>

using namespace std;

Table::Table()
{
  size = 31;
  container = new restaurant[size];
}

Table::~Table()
{
  delete container;
}

int Table::getSize() const
{
  return size;
}

bool Table::insert(const restaurant &value)
{
  if(find(value.name) != -1) return false;

  int key = hashFunction(value.name);

  if(key == -1) return false;

  container[key] = value;

  return true;
}

bool Table::deleteValue(string value)
{
  int location = find(value);
  if(location == -1) return false;

  //int key = hashFunction(value);

  //if(key == -1) return false;

  container[location].name = "";
  container[location].price = "";
  container[location].rating = -1;

  return true;
}

int Table::find(string value)
{
  for(int i = 0; i < size; i++){
  	if(container[i].name == value)
      return i;
  }

  return -1;
}

string* Table::searchByRating(int rating){
  string holder[31];
  int curPosition = 0;

  for(int i = 0; i < size; i++){
  	if(container[i].rating == rating){
  	   holder[curPosition] = container[i].name;
  	   curPosition++;
  	}
  }

  string *result[curPosition];

  for(int i = 0; i < curPosition; i++){
    result[i] = &holder[i];
  }

  if(curPosition == 0)
    return nullptr;

  return *result;
}

string* Table::searchByPrice(string price){
  string holder[31];
  int curPosition = 0;

  for(int i = 0; i < size; i++){
  	if(container[i].price == price){
  	   holder[curPosition] = container[i].name;
  	   curPosition++;
  	}
  }

  string *result[curPosition];

  for(int i = 0; i < curPosition; i++){
    result[i] = &holder[i];
  }
  if(curPosition == 0)
    return nullptr;

  return *result;
}

void Table::printTable(){
  for(int i = 0; i < getSize(); i++){
    cout<<"\n"<<to_string(i)<<": ";

    if(container[i].name != "")
      cout<<container[i].name + " " + to_string(container[i].rating) + " " + container[i].price;
  }

  cout<<"\n";
}
