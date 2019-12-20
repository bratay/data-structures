
#ifndef QNODE_H
#define QNODE_H

template <class T>
class QNode
{
public:
    QNode();

    QNode(T val);

    T getValue() const;

    void setValue(T val);

    QNode<T> *getNext() const;

    void setNext(QNode<T> *next);

private:
    T m_value;
    QNode<T> *m_next;
};

#include "QNode.hpp"
#endif