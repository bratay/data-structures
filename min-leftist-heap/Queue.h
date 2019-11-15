#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
private:
  Node* qfront;
  int qlength;

public:
  Queue();

  ~Queue();

  bool isEmpty() const;

  void enqueue( int value);

  bool dequeue();

  Node* peekFront();

  Node* printFront();

};
#include "Queue.cpp"
#endif
