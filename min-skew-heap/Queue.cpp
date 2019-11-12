#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
  qfront = nullptr;
  qlength = 0;
}

template <typename T>
Queue<T>::~Queue()
{
  while (qfront != nullptr)
  {
    dequeue();
  }
}

template <typename T>
bool Queue<T>::isEmpty() const
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

template <typename T>
void Queue<T>::enqueue(const T value)
{
  Node<T> *cur = qfront;
  Node<T> *temp = cur;
  Node<T> *n = new Node<T>();

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

template <typename T>
bool Queue<T>::dequeue()
{
  Node<T> *cur = qfront;
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

template <typename T>
T Queue<T>::peekFront()
{
  T front;
  Node<T> *p = qfront;
  if (p != nullptr)
  {
    front = p->getItem();
    dequeue();
    return front;
  }
  else
  {
    return nullptr;
  }
}

template <typename T>
T Queue<T>::PrintFront()
{
  if (qfront != nullptr)
  {
    return qfront->getItem();
  }
  else
  {
    return nullptr;
  }
}