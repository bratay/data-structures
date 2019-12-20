
template <class ItemType>
Queue<ItemType>::Queue()
{
    m_front = nullptr;
    m_size = 0;
}

template <class ItemType>
Queue<ItemType>::~Queue()
{
    QNode<ItemType> *temp = nullptr;

    while (!isEmpty())
    {
        temp = m_front;
        m_front = m_front->getNext();
        delete temp;
        m_size--;
    }

    m_front = nullptr;
}

template <class ItemType>
void Queue<ItemType>::enqueue(const ItemType &newEntry) throw(PrecondViolatedExcep)
{
    if (m_front == nullptr)
    {
        try
        {
            m_front = new QNode<ItemType>(newEntry);
            m_size++;
        }
        catch (std::bad_alloc &e)
        {
            std::string message = "Memory could not be allocated";
            throw PrecondViolatedExcep(message);
        }
    }
    else
    {
        try
        {
            QNode<ItemType> *newNode = new QNode<ItemType>(newEntry);
            QNode<ItemType> *temp = m_front;
            while (temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
            m_size++;
        }
        catch (std::bad_alloc &e)
        {
            std::string message = "Memory could not be allocated";
            throw PrecondViolatedExcep(message);
        }
    }
}

template <class ItemType>
void Queue<ItemType>::dequeue() throw(PrecondViolatedExcep)
{
    if (m_front == nullptr)
    {
        throw PrecondViolatedExcep("Removal attempted on an empty queue");
    }
    else
    {
        QNode<ItemType> *temp = m_front;
        m_front = m_front->getNext();
        delete temp;
        m_size--;
    }
}

template <class ItemType>
ItemType Queue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
    if (isEmpty())
    {
        throw PrecondViolatedExcep("Peek attempted on an empty queue");
    }
    else
    {
        return m_front->getValue();
    }
}

template <class ItemType>
bool Queue<ItemType>::isEmpty() const
{
    if (m_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
