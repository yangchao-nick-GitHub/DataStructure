
#include "array_stack.h"
#include <stdio.h>

template<class T>
internal_hook ArrayStack<T>::m_hook = { internal_allocate,  internal_deallocate};

template<class T>
ArrayStack<T>::ArrayStack(int size)
{
    m_capacity = size;
    m_size = 0;
    T *m_item = new T[m_capacity];
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    if (m_item) {
        delete[] m_item;
        m_item = nullptr;
    }
}

template<class T>
bool ArrayStack<T>::IsEmpty()
{
    return m_size == 0;
}

template<class T>
void ArrayStack<T>::StackPush(T data)
{
    assert(m_item);
    if (m_size >= m_capacity) {
        printf("stack is full!\n");
        return ;
    }
    m_item[m_size++] = data;
}

template<class T>
T ArrayStack<T>::StackPop()
{
    assert(m_item);
    if (m_size <= 0) {
        printf("stack is empty\n");
        return 0;
    }
    return m_item[m_size--]; 
}

template<class T>
T ArrayStack<T>::StackTop()
{
    assert(m_item);
    if (m_size <= 0) {
        printf("stack is empty\n");
        return 0;
    }
    return m_item[m_size]; 
}

template<class T>
T ArrayStack<T>::GetPosStackItme(int pos)
{
    assert(m_item);
    if (pos < 0 || pos > m_capacity) {
        return ;
    }
    return m_item[pos];
}