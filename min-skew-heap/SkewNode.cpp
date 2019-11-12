#include "SkewNode.h"
#include <iostream>

SkewNode::SkewNode(int newvalue)
{
  value = newvalue;
  leftchild = nullptr;
  rightchild = nullptr;
  rank = 1;
}

SkewNode::~SkewNode()
{
}

void SkewNode::setValue(int newvalue)
{
  value = newvalue;
}

int SkewNode::getValue()
{
  return value;
}

void SkewNode::setLeftChild(SkewNode *newleftchild)
{
  leftchild = newleftchild;
}

SkewNode *SkewNode::getLeftChild()
{
  return leftchild;
}

void SkewNode::setRightChild(SkewNode *newrightchild)
{
  rightchild = newrightchild;
}

SkewNode *SkewNode::getRightChild()
{
  return rightchild;
}

void SkewNode::setRank(int newrank)
{
  rank = newrank;
}

int SkewNode::getRank()
{
  return rank;
}