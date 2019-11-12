#include <string>
#include <fstream>
#include <iostream>

template <typename T>
Node<T>::Node()
{
  n_next = nullptr;
}

template <typename T>
Node<T>::~Node()
{
}

template <typename T>
void Node<T>::setItem(T value)
{
  n_value = value;
}

template <typename T>
T Node<T>::getItem()
{
  return n_value;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
  n_next = next;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
  return n_next;
}
