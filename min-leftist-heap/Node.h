#ifndef Node_H
#define Node_H

template <typename T>
class Node
{
private:
  T n_value;
  Node<T> *n_next;
  
public:
  Node();
  ~Node();

  void setItem(T value);

  T getItem();

  void setNext(Node<T> *n_next);

  Node<T> *getNext();
};
#include "Node.cpp"
#endif
