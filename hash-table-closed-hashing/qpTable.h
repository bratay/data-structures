#ifndef QPTABLE_H
#define QPTABLE_H
#include "table.h"
#include <string>

using namespace std;

class qpTable: public Table
{

private:

public:
  qpTable();
  ~qpTable();

  int hashFunction(string value);
};
#endif
