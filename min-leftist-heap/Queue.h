#ifndef QUEUE_H
#define QUEUE_H

#include "LeftistNode.h"

class Queue
{
private:
  LeftistNode *qfront;
  int qlength;

public:
  Queue();

  ~Queue();

  bool isEmpty() const;

  void enqueue(const int value);

  bool dequeue();

  LeftistNode peekFront();

  LeftistNode PrintFront();

};
#include "Queue.cpp"
#endif
