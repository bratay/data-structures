#ifndef QUEUE_H
#define QUEUE_H

#include "LeftistNode.h"
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

  void enqueue( LeftistNode* value);

  bool dequeue();

  LeftistNode* peekFront();

  LeftistNode* printFront();

};
#include "Queue.cpp"
#endif
