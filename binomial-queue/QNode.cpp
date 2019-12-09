template <class T>
QNode<T>::QNode()
{
    m_value = T();
    setNext(nullptr);
}

template <class T>
QNode<T>::QNode(T val)
{
    setValue(val);
    setNext(nullptr);
}

template <class T>
T QNode<T>::getValue() const
{
    return m_value;
}

template <class T>
void QNode<T>::setValue(T val)
{
    m_value = val;
}

template <class T>
QNode<T> *QNode<T>::getNext() const
{
    return m_next;
}

template <class T>
void QNode<T>::setNext(QNode<T> *next)
{
    m_next = next;
}