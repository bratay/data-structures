#include "dhTable.h"
#include <iostream>
#include <string>

using namespace std;

dhTable::dhTable()
{
  size = 31;
  container = new restaurant[size];
}

dhTable::~dhTable()
{
  delete container;
}

int dhTable::hashFunction(string value)
{
  int position = 0;
  int sum = 0;
  int r = 29;

  for(int i = 0; i < value.length(); i++)
  {
    sum += int( value.at(i) );
  }

  position = sum % size;

  for(int i = 0; i < value.length(); i++)
  {
    sum += int( value.at(i) );
  }

  if(container[position].name == "")
    return position;

  int hashAttemps = 1;
  int doubleHash = r - (sum %  r);
  while(hashAttemps < 31){
  	position = (sum + (hashAttemps * doubleHash)) % size;

  	if(container[position].name == "")
  	   return position;

  	hashAttemps++;
  }

  return -1;
}
