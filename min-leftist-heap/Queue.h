#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
private:
  Node *qfront;
  int qlength;

public:
  Queue();

  ~Queue();

  bool isEmpty() const;

  void enqueue(const int value);

  bool dequeue();

  int peekFront();

  int PrintFront();

};
#include "Queue.cpp"
#endif
