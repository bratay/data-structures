#include "LeftistNode.h"
#include <iostream>

LeftistNode::LeftistNode(int newvalue)
{
  value = newvalue;
  leftchild = nullptr;
  rightchild = nullptr;
  rank = 1;
}

LeftistNode::~LeftistNode()
{
}

void LeftistNode::setValue(int newvalue)
{
  value = newvalue;
}

int LeftistNode::getValue()
{
  return value;
}

void LeftistNode::setLeftChild(LeftistNode *newleftchild)
{
  leftchild = newleftchild;
}

LeftistNode *LeftistNode::getLeftChild()
{
  return leftchild;
}

void LeftistNode::setRightChild(LeftistNode *newrightchild)
{
  rightchild = newrightchild;
}

LeftistNode *LeftistNode::getRightChild()
{
  return rightchild;
}

void LeftistNode::setRank(int newrank)
{
  rank = newrank;
}

int LeftistNode::getRank()
{
  return rank;
}