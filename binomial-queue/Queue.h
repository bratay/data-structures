

#ifndef QUEUE_H
#define QUEUE_H

#include "QNode.h"
#include "PrecondViolatedExcep.h"
#include <string>

template <class ItemType>
class Queue
{
public:
    ~Queue();

    Queue();

    void enqueue(const ItemType &newEntry) throw(PrecondViolatedExcep);

    void dequeue() throw(PrecondViolatedExcep);

    ItemType peekFront() const throw(PrecondViolatedExcep);

    bool isEmpty() const;

private:
    QNode<ItemType> *m_front;
    int m_size;
};

#include "Queue.hpp"
#endif