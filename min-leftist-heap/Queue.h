#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue
{
private:
  Node<T> *qfront;
  int qlength;

public:
  Queue();

  ~Queue();

  bool isEmpty() const;

  void enqueue(const T value);

  bool dequeue();

  T peekFront();

  T PrintFront();

};
#include "Queue.cpp"
#endif
