#include "Queue.h"

Queue::Queue()
{
  qfront = nullptr;
  qlength = 0;
}

Queue::~Queue()
{
  while (qfront != nullptr)
  {
    dequeue();
  }
}

bool Queue::isEmpty() const
{
  if (qfront == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Queue::enqueue(const int value)
{
  LeftistNode *cur = qfront;
  LeftistNode *temp = cur;
  LeftistNode *n = new LeftistNode();

  if (qlength == 0)
  {
    n->setItem(value);
    qfront = n;
    qlength++;
    temp = nullptr;
    cur = nullptr;
  }
  else 
  {
    while (cur != nullptr)
    {
      temp = cur;
      cur = cur->getNext(); 
    }
    temp->setNext(n);
    n->setItem(value);
    qlength++;
    temp = nullptr;
    cur = nullptr;
  }
}

bool Queue::dequeue()
{
  LeftistNode *cur = qfront;
  if (qfront != nullptr) 
  {
    qfront = qfront->getNext();
    delete cur;
    cur = nullptr;
    qlength--;
    return true;
  }
  else
  {
    return false;
  }
}

LeftistNode Queue::peekFront()
{
  int front;
  LeftistNode *p = qfront;
  if (p != nullptr)
  {
    front = p->getItem();
    dequeue();
    // return front;
    return qfront;
  }
  else
  {
    return nullptr;
  }
}

LeftistNode Queue::PrintFront()
{
  if (qfront != nullptr)
  {
    // return qfront->getItem();
    return qfront;
  }
  else
  {
    return nullptr;
  }
}