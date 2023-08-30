
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define internal_allocate malloc
#define internal_deallocate free

typedef struct internal_hook {
    void* (*allocate)(size_t size);
    void (*deallocate)(void *pointer);
}internal_hook;


template<class T>
class ArrayStack {
public:
    ArrayStack(int size);
    ~ArrayStack();
    void StackPush(T data);
    T StackPop();
    T StackTop();
    bool IsEmpty();
    T GetPosStackItme(int pos);
    static internal_hook m_hook;

private:
    T *m_item;
    int m_capacity;
    int m_size;
};


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
        delete[]m_item;
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

int main()
{
    ArrayStack<int> stack(10);
    return 0;
}