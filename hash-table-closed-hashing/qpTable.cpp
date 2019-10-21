#include "qpTable.h"
#include <iostream>
#include <string>

using namespace std;

qpTable::qpTable()
{
  size = 31;
  container = new restaurant[size];
}

qpTable::~qpTable()
{
  delete container;
}

int qpTable::hashFunction(string value)
{
  int position = 0;
  int sum = 0;

  for(int i = 0; i < value.length(); i++)
  {
    sum += int( value.at(i) );
  }

  position = sum % size;

  if(container[position].name == "")
  	return position;

  int hashAttemps = 1;
  
  while(hashAttemps < 31){
  	position = (sum + hashAttemps^2) % size;

  	if(container[position].name == "")
  	   return position;

  	hashAttemps++;
  }

  return -1;
}
