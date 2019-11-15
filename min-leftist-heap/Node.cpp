#include <string>
#include <fstream>
#include <iostream>

#include "Node.h"

Node::Node()
{
  n_next = nullptr;
}

Node::Node(int value)
{
  n_next = nullptr;
  LeftistNode* newNode = new LeftistNode(value);
  n_value = newNode;
}


Node::~Node()
{
}


void Node::setItem(LeftistNode* value)
{
  n_value = value;
}


LeftistNode* Node::getItem()
{
  return n_value;
}


void Node::setNext(Node *next)
{
  n_next = next;
}


Node *Node::getNext()
{
  return n_next;
}
