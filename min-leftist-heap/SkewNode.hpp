#include "SkewNode.h"

using namespace std;

SkewNode::SkewNode(int s_value)
{
  value = s_value;
  leftchild = nullptr;
  rightchild = nullptr;
}

SkewNode::~SkewNode()
{
}

void SkewNode::setValue(int s_value)
{
  value = s_value;
}

int SkewNode::getValue()
{
  return value;
}

void SkewNode::setLeftChild(SkewNode *s_leftchild)
{
  leftchild = s_leftchild;
}

SkewNode *SkewNode::getLeftChild()
{
  return leftchild;
}

void SkewNode::setRightChild(SkewNode *s_rightchild)
{
  rightchild = s_rightchild;
}

SkewNode *SkewNode::getRightChild()
{
  return rightchild;
}
